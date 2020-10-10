/*******************************************************************************
Autor: Daniel Fernandes Campos
Componente Curricular: Algoritmos I
Concluido em: 26/12/2018
Declaro que este código foi elaborado por mim de forma individual e não contém nenhum
trecho de código de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e páginas ou documentos eletrônicos da Internet. Qualquer trecho de código
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte
do código, e estou ciente que estes trechos não serão considerados para fins de avaliação.
******************************************************************************************/
#include <stdio.h> // entrada e saida de dados
#include <stdlib.h> // alocaçao dinamica
#include<string.h> // strings
#include <locale.h> /* lingiagem em portugues no printf*/
#define QMP 64//Quantidade_Max_Palestras ///   MUDA VALOR DE QUANTIDAE DE PALESTRAS QUE APRESENTARAO PARA TESTES SUGIRO O NUMEORO 5!

// Structs
struct dados_cadastro{ // dados completos da palestra
		int codigo;
		char titulo[200];
		int area_do_conhecimento;
		char autor[200];
		char orientador[200];
		int status; // confirmado ou negado
		int verificacao_coautor;
		char coautor[200];
		int verificacao_coorientador;
		char coorientador[200];
		float nota;
	};
struct organizador_notas{ // dados usados para organizar as palestras
    int posicao_da_palestra;
    float nota;
    char titulo_trabalho[200];
    int area_do_conhecimento;
    int codigo;
};
// Funçoes usadas
void avaliar_candidato(const  char nome_arquivo_palestras[51] ); // opçao A
void cadastra_usuario(const  char nome_arquivo_palestras[51] );// opçao C
void salvar_candidato(FILE *arquivo_palestras, struct dados_cadastro *projeto, int j);
void salvar_projetos_aprovados( struct dados_cadastro *aprovados,const  int i,const  char nome_arquivo_palestras );
void print_area_conhecimento();
void ler_dados(struct dados_cadastro *trabalho_unico, int i, FILE *file);
void gerador_programacao(const char nome_arquivo_palestras[51]); // opçao G
void print_programacao();
void print_titulo_palestras(struct organizador_notas *vetor_ordem_palestras, int quantidade_palestras, int ajuda, FILE *file, int *quant_palestras_salvas, int posicao_maxima_salvar, FILE *file_bin);
void escrever_programacao_txt(struct organizador_notas *vetor_ordem_palestras,int quantidade_palestras);
void print_candidato_para_debug(struct dados_cadastro candidato_unico);
void tirar_enter(char *str1);
void print_programacao(); // opçao V
void apagar_candidato(const char nome_arquivo_palestras[51]); // opçao D
void print_txt(char text[500], FILE *file, int posicao_maxima_salvar, int *ajuda, struct organizador_notas *vetor_ordem_palestras, int *quant_palestras_salvas, int quantidade_palestras, FILE *file_bin);
void salvar_candidato_unico(FILE *arquivo_palestras, struct dados_cadastro projeto);

/*****************************************************************************************************************************************************************************************
IDEIAS:
      NAO APAGA PALESTRA NEGADAS NO ARQUIVO TXT ( ESCREVER ELAS COM STATUS = 0 E NAO FAZER A LEITURA NO FUTURO )
*****************************************************************************************************************************************************************************************/
int main(){
	setlocale(LC_ALL, "Portuguese");
	char menu_opcao;
	char nome_arquivo_palestras[51]; // = "cadastrados_SCT.txt"; /* Ultilize inicializaçao pra ficar mais rapido de testa se quiser ...  */
	FILE *teste_arquivo;
	do{
		printf("Digite o arqivo onde serão/estão salvos os candidatos ( com o .txt):");
		gets(nome_arquivo_palestras);
		teste_arquivo = fopen(nome_arquivo_palestras,"a");
        if(nome_arquivo_palestras == NULL){
            printf("\n\nArquivo nao aberto! Tente novamente.\n\n");
        }
	}while(teste_arquivo == NULL);
	fclose(teste_arquivo);
	while(1){
        fflush(stdin);
		printf("\n\n\n\n\n");
		printf("Menu de ações da Semana de Ciências e Tecnologia na UEFS\n[C]adastra um candidato\n[A]valiar um candidato\n");
		printf("[G]erar a programação dos dois dias \n[V]er programação\n[D]esistente\n[S]air\n");
		scanf("%c", &menu_opcao);
		getchar();
        switch(menu_opcao){
			case 'C':
				cadastra_usuario(nome_arquivo_palestras);// testada; Status OK
				break;
			case 'A':
				avaliar_candidato(nome_arquivo_palestras);// testada; Status OK
				break;
			case 'G':
				gerador_programacao(nome_arquivo_palestras);// testando; Status ??
				break;
			case 'V':
			    print_programacao();
				break;
            case 'D':
                apagar_candidato(nome_arquivo_palestras);// testada; Status OK
                break;
			case 'S':
				return 0;
			default:
				printf("Opção digitada não existe por favor tente novamente!!!");
		}
	}
}

void apagar_candidato(const char nome_arquivo_palestras[51]){ ///Desistencia
    setlocale(LC_ALL, "Portuguese");
    int codigo_para_apagar;
    FILE *file = fopen( nome_arquivo_palestras, "r" );
    if(file == NULL){
        puts("arquivo não aberto\n");
        return;
    }
    struct dados_cadastro *palestras = malloc( 11 * sizeof(struct dados_cadastro) );
    int i, j;
    fgetc(file);
    for( i = 0; feof(file) == 0; i++){
        if(i % 10 == 0){
            palestras = (struct dados_cadastro *)realloc( palestras, ( i +10 ) * sizeof(struct dados_cadastro) );
        }
        ler_dados(palestras, i, file);
        print_candidato_para_debug(palestras[i]);
    }
    printf("\n\nDigite o codigo do trabalho que deseja apagar: ");
    scanf("%d", &codigo_para_apagar);
    getchar();
    for(j=0; j<i; j++){
        if(palestras[j].codigo == codigo_para_apagar){
            palestras[j].status = 0;
        }
    }
    fclose(file);
    file = fopen( nome_arquivo_palestras , "w" );
    for( j=0; j<i; j++){
        if(palestras[j].status !=0){
            salvar_candidato(file, palestras, j);
        }else{
            printf("projeto de codigo %d nao foi salvo\n\n", palestras[j].codigo);
        }
    }
    fclose(file);
    free(palestras);
    gerador_programacao(nome_arquivo_palestras);
    return;
}

void gerador_programacao(const char nome_arquivo_palestras[51]){//opçao 3
	setlocale(LC_ALL, "Portuguese");
	FILE *file = fopen(nome_arquivo_palestras, "r");
	if( file == NULL){
		printf("Algo de errado aconteceu e o arquivo não aberto!!! Tente novamente!");
		return;
	}
	fgetc(file);
	struct dados_cadastro *vetor_palestras = ( struct dados_cadastro *)malloc( 11 * sizeof( struct dados_cadastro ) );
	int quantidade_palestras = 0 , posicao_palestra_arumando, verifica_posicao, posicao;
	while( feof (file) == 0 ){ /* loop de leitura do arquivo que acada inicio de loop da realoc pra a nova palestra que esta sendo adicionada*/
		if(quantidade_palestras%10 == 0 && quantidade_palestras != 0){
            vetor_palestras = ( struct dados_cadastro *)realloc(vetor_palestras, (quantidade_palestras+10) * sizeof( struct dados_cadastro ) );
        }
		ler_dados( vetor_palestras, quantidade_palestras, file);
		if(vetor_palestras[quantidade_palestras].status !=1){
            continue;
		}
		printf("Palestra lida:\n");
		print_candidato_para_debug(vetor_palestras[quantidade_palestras]);
        quantidade_palestras++;
	}
	printf("Quantidade palestras lidas: %d\n\n",quantidade_palestras);
	fclose(file);/*                                                                         ↕ nao precisa de + 1 pq a soma contece no final ali em cima entao apos salvar a ultima palestra adiciona 1 no contador                    */
	struct organizador_notas *vetor_ordem_palestras = (struct organizador_notas *)malloc( (quantidade_palestras ) * sizeof (  struct organizador_notas ) ); // vetor de structs que contera as organizadas
	for(posicao_palestra_arumando = 0; posicao_palestra_arumando < quantidade_palestras; posicao_palestra_arumando++){ // zera a posiçao e
		vetor_ordem_palestras[posicao_palestra_arumando].posicao_da_palestra = 0;                                       // e a nota dos vetores
		vetor_ordem_palestras[posicao_palestra_arumando].nota = 0;                                                      // o resto nao precisa pois
	}                                                                                                                   // é sobre escrito
	for( posicao_palestra_arumando = 0; posicao_palestra_arumando < quantidade_palestras /* nao precisa do menos 1 pq explicaçao esta acima da explicaçao passada ( essa nota é pra min nao pra quem estiver revisando o codigo se vc estiver lendo isso)*/ ; posicao_palestra_arumando++ ){
		if( posicao_palestra_arumando == 0 ){// joga o primeiro na posicao 0 ( primeiro)
				vetor_ordem_palestras[0].nota = vetor_palestras[posicao_palestra_arumando].nota;
				vetor_ordem_palestras[0].posicao_da_palestra = 1;
				strcpy(vetor_ordem_palestras[0].titulo_trabalho,vetor_palestras[posicao_palestra_arumando].titulo);
				vetor_ordem_palestras[0].area_do_conhecimento = vetor_palestras[posicao_palestra_arumando].area_do_conhecimento;
				vetor_ordem_palestras[0].codigo = vetor_palestras[posicao_palestra_arumando].codigo;
			}
		else{ // para nao primeiros
            posicao = 1; // seta variavel que faz acontagem da posiçao do trabalho atua para 0
			vetor_ordem_palestras[quantidade_palestras -1 ].nota = vetor_palestras[posicao_palestra_arumando].nota; // joga os nao primeiros na ultima posicao
			for( verifica_posicao=0; verifica_posicao < posicao_palestra_arumando; verifica_posicao++){      // compara com os outros e ver em qual lugar fica
				if(vetor_ordem_palestras[quantidade_palestras-1].nota > vetor_ordem_palestras[verifica_posicao].nota){// compara a nota com cada uma das outras se a nota for maior
					vetor_ordem_palestras[verifica_posicao].posicao_da_palestra++;}						    	  // soma 1 na posicao do que esta sendo comparado ( que esta do lado direito do '>')
				else{
					posicao++;																					  // se nao soma um na posiçao do comparado ( que agente vai salvar no luga)
				}
			}
            vetor_ordem_palestras[posicao_palestra_arumando].nota = vetor_palestras[posicao_palestra_arumando].nota; // salva o comparando na posicao acima do ultimo olhado
            vetor_ordem_palestras[posicao_palestra_arumando].posicao_da_palestra = posicao;
            strcpy(vetor_ordem_palestras[posicao_palestra_arumando].titulo_trabalho,vetor_palestras[posicao_palestra_arumando].titulo);
            vetor_ordem_palestras[posicao_palestra_arumando].area_do_conhecimento = vetor_palestras[posicao_palestra_arumando].area_do_conhecimento;
            vetor_ordem_palestras[posicao_palestra_arumando].codigo = vetor_palestras[posicao_palestra_arumando].codigo;
		}
	}
	int i;
	for( i=0; i<quantidade_palestras; i++){
        printf("Palestra de codigo:%d | ficou na posiçao: %d\n",vetor_ordem_palestras[i].codigo, vetor_ordem_palestras[i].posicao_da_palestra);
	}
	printf("\n");
	free(vetor_palestras);
	escrever_programacao_txt(vetor_ordem_palestras, posicao_palestra_arumando);
	free(vetor_ordem_palestras);
}

void print_programacao(){
    setlocale(LC_ALL, "Portuguese");
    FILE *file_bin = fopen("trabalhos organizados.bin", "rb");
    int quantidade_max_palestras, i , j , area_pintada = 1, palestras_printadas = 0, horas = 7, minutos =30;
    fread(&quantidade_max_palestras, sizeof(int), 1, file_bin);
    if(file_bin == NULL){
        printf("\n\nArquivo nao foi aberto ou nao existe!!!\n\n");
        return;
    }
    if(quantidade_max_palestras == 0){
        printf("\n\nNao existe palestras aprovadas!!\n\nPrescione enter para proceguir\n");
        getchar();
        return;
    }
    struct organizador_notas *vetor_palestras = (struct organizador_notas *) malloc( quantidade_max_palestras * sizeof(struct organizador_notas) );
    for(i=0; i<quantidade_max_palestras; i++){
        fread(&(vetor_palestras[i]), sizeof(struct organizador_notas), 1, file_bin);
    }
    int dia = 1;
    printf("As apresentações do dia 1 serao: \n");
    for( i=0; i<quantidade_max_palestras; i++){
        if( i< QMP){
            printf("\t%.2d:%.2d - %s",horas,minutos,vetor_palestras[i].titulo_trabalho);
        }else if(horas == 11 && minutos == 30){
            printf("\t%.2d:%.2d as 13:30 - Almoço\n", horas, minutos);
            horas = 13;
        }
        else if(horas == 17 && minutos == 30 && dia==1){
            printf("As apresentaçoes do dia 2 serao: \n");
            horas = 7;
            dia++;
        }
        else if( i>= QMP || (horas == 17 && minutos == 30 && dia==2)){
            printf("Palestra para reposição: %s",vetor_palestras[i].titulo_trabalho);
        }
        if (minutos == 45){
            horas++;
            minutos = 0;
        }
        else
            minutos+= 15;
    }
}

void print_titulo_palestras(struct organizador_notas *vetor_ordem_palestras, int quantidade_palestras, int ajuda, FILE *file, int *quant_palestras_salvas, int posicao_maxima_salvar, FILE *file_bin){ // como o nome das palestras serao diferentes so preisamos disso para separa-los
	setlocale(LC_ALL, "Portuguese");
	int i;
	for( i=0; vetor_ordem_palestras[i].posicao_da_palestra <= quantidade_palestras  ; i++ ){ // AQUI USA <= pq estamos passando posicao_palestra_arumada na funçao principal que tem valor de quantidae_palestras_maxima -1 ou seja "<= posicao_palestra_arumada" == "<quantidade_palestras_maxima"
		if(vetor_ordem_palestras[i].area_do_conhecimento == ajuda /* se é da mesma area*/ && vetor_ordem_palestras[i].posicao_da_palestra <= posicao_maxima_salvar){ // se esta entre as 64 palestras q vao apresentar
			printf("Palestra codigo: %d foi salva e sera a %d a apresentar\n", vetor_ordem_palestras[i].codigo, vetor_ordem_palestras[i].posicao_da_palestra);
            fprintf(file, "%d %d %s", vetor_ordem_palestras[i].codigo // printa o codigo pra ficar mais facil de achar palestra
                                   , vetor_ordem_palestras[i].area_do_conhecimento
                                   ,vetor_ordem_palestras[i].titulo_trabalho); // printa o titulo para ficar visualmente mais facil de ver a programaçao caso abram o txt e pq essas duas informaçoes podem ser as unicas usadas pra printa a tabela de programaçao
            fwrite(&(vetor_ordem_palestras[i]), sizeof(struct organizador_notas), 1, file_bin);
            *quant_palestras_salvas++;
        }
	}
}

void print_txt(char text[500], FILE *file, int posicao_maxima_salvar, int *ajuda, struct organizador_notas *vetor_ordem_palestras, int *quant_palestras_salvas, int quantidade_palestras, FILE *file_bin){
    printf("Area do conhecimento %d\n", *ajuda);
    fprintf(file, text);
    if(*quant_palestras_salvas<=posicao_maxima_salvar){
        print_titulo_palestras(vetor_ordem_palestras, quantidade_palestras, *ajuda, file, quant_palestras_salvas, posicao_maxima_salvar, file_bin);
        if(*quant_palestras_salvas == quantidade_palestras){
            printf("todas as palestras foram salvas em um total de: %d", quant_palestras_salvas);
            return ;
        }
    }
    printf("\n");
    *ajuda+=1;
}

void escrever_programacao_txt(struct organizador_notas *vetor_ordem_palestras,int quantidade_palestras){
	setlocale(LC_ALL, "Portuguese");
	FILE *file = fopen("Trabalhos organizados para apresentação.txt", "w");
	FILE *file_bin = fopen("trabalhos organizados.bin", "wb");
	int quant_palestras_salvas=0; // variavel que guarda quantidade palestras salvas
	int posicao_maxima_salvar = QMP;
	int ajuda = 1; // ajuda guardao numero da area de conhecimento qesta sendo olhada
	fwrite(&quantidade_palestras, sizeof(int), 1, file_bin);
    int i;
///     string que separa a area, arquivo, posiçao maxima que apresenta, area que apresenta, vetor, quuantidade que ja foram salvas, quantidade total de palestras pra salver
	print_txt("00 1 Palestras Ciências da Saúde:\n", file, posicao_maxima_salvar, &ajuda, vetor_ordem_palestras, &quant_palestras_salvas, quantidade_palestras, file_bin);

	print_txt("00 2 Palestras Ciências Exatas:\n", file, posicao_maxima_salvar, &ajuda, vetor_ordem_palestras, &quant_palestras_salvas, quantidade_palestras, file_bin);

    print_txt("00 3 Palestras Engenharias:\n", file, posicao_maxima_salvar, &ajuda, vetor_ordem_palestras, &quant_palestras_salvas, quantidade_palestras, file_bin);

	print_txt("00 4 Palestras Ciências Sociais:\n", file, posicao_maxima_salvar, &ajuda, vetor_ordem_palestras, &quant_palestras_salvas, quantidade_palestras, file_bin);

    print_txt("00 5 Palestras Ciências Humanas:\n", file, posicao_maxima_salvar, &ajuda, vetor_ordem_palestras, &quant_palestras_salvas, quantidade_palestras, file_bin);

    print_txt("00 6 Palestras Ciências da Saúde:\n", file, posicao_maxima_salvar, &ajuda, vetor_ordem_palestras, &quant_palestras_salvas, quantidade_palestras, file_bin);

    print_txt("00 7 Palestras Linguística, Letras e artes:\n", file, posicao_maxima_salvar, &ajuda, vetor_ordem_palestras, &quant_palestras_salvas, quantidade_palestras, file_bin);

	fprintf(file, "-1 -1 Trabalhos que nao serao apresentados ( para reposição) :\n");
	int organizador_posicoes/* essa variavel representa a posiçao atual q esta sendo salva*/;
	for(organizador_posicoes = posicao_maxima_salvar+1; organizador_posicoes<= quantidade_palestras; organizador_posicoes++){ // printa todas as palestras em ordem de posiçao crecente
        for( i = 0; vetor_ordem_palestras[i].posicao_da_palestra <= quantidade_palestras; i++){ // "<=" mesma explicaçao do print_titulo_palestras, roda todo o vetor procurando a palestra que sera printada ( da de posiçao 65 ate o final)
            if ( vetor_ordem_palestras[i].posicao_da_palestra == organizador_posicoes ){
                fprintf(file, "%d %d %s", vetor_ordem_palestras[i].codigo, vetor_ordem_palestras[i].area_do_conhecimento, vetor_ordem_palestras[i].titulo_trabalho);
                fwrite(&(vetor_ordem_palestras[i]), sizeof(struct organizador_notas), 1, file_bin);
                printf("Palestra codigo: %d foi salva como repositorio\n", vetor_ordem_palestras[i].codigo);
                break;
            }
        }
	}
	fclose(file);
    fclose(file_bin);
}

void ler_dados(struct dados_cadastro *trabalho_unico, int i, FILE *file){
    setlocale(LC_ALL, "Portuguese");
    fgets(trabalho_unico[i].titulo, 200, file);
    fscanf(file, "Status: %d", &trabalho_unico[i].status);
    fscanf(file, "\nNota: %f", &trabalho_unico[i].nota);
    fgetc(file);
	fgets(trabalho_unico[i].autor, 200, file);
    fscanf(file, "Existencia de coautor: %d", &trabalho_unico[i].verificacao_coautor);
    fgetc(file);
	if( trabalho_unico[i].verificacao_coautor == 1 ){
		fgets(trabalho_unico[i].coautor, 200, file);
	}
	fgets(trabalho_unico[i].orientador, 200, file);
    fscanf(file, "Existencia de coorientador: %d", &trabalho_unico[i].verificacao_coorientador);
    fgetc(file);
	if(trabalho_unico[i].verificacao_coorientador == 1){
		fgets(trabalho_unico[i].coorientador, 200, file);
	}
    fscanf(file, "Area do conhecimento: %d", &trabalho_unico[i].area_do_conhecimento);
    fscanf(file, "\nCodigo: %d",&trabalho_unico[i].codigo);
    fgetc(file);
}

void avaliar_candidato( const char nome_arquivo_palestras[51] ){ // opçao 2
	setlocale(LC_ALL, "Portuguese");
	FILE *file = fopen(nome_arquivo_palestras, "r");
	struct dados_cadastro *vetor_palestras = ( struct dados_cadastro *)malloc( 11 * sizeof( struct dados_cadastro ));
	int i = 0;
	fgetc(file);
	while( feof(file) == 0){
		if(i%10 == 0 && i!=0){
			vetor_palestras = ( struct dados_cadastro *)realloc(vetor_palestras, (i + 10) * sizeof( struct dados_cadastro ) );
		}
		ler_dados(vetor_palestras, i, file);
		printf("Trabalho avaliado:\n");
		print_candidato_para_debug( vetor_palestras[i]);
		while(vetor_palestras[i].status != 1 && vetor_palestras[i].status != 0){
			printf("Para avaliaçao  dos trabalhos digite 1 para aprovado e digite 0 caso reprovado\n");
			scanf("%d", &vetor_palestras[i].status);
			getchar();
			if(vetor_palestras[i].status == 1){
				do{
					printf("Digite a nota de 0 a 10 do trabalho ( de codigo: %d )chamado : %s\nNota: ", vetor_palestras[i].codigo, vetor_palestras[i].titulo);
					scanf("%f", &vetor_palestras[i].nota);
					getchar();
				}while(vetor_palestras[i].nota < 0 || vetor_palestras[i].nota > 10 );
			}
		}
		if( vetor_palestras[i].status == 0 ){ // reescreve encima dos que tem codigo 0 ( negados )
			i--;
		}
        i++;
	}
	fclose(file);
	salvar_projetos_aprovados(vetor_palestras, i, *nome_arquivo_palestras);
	remove(nome_arquivo_palestras);
	rename("arquivo organizado.txt",nome_arquivo_palestras);
	free(vetor_palestras);
	puts("\nProjetos salvos\n");
	puts("Presione enter para continuar para a geração da programação");
	getchar();
	gerador_programacao(nome_arquivo_palestras);
	return;
}

void cadastra_usuario(const  char nome_arquivo_palestras[51] ){// opçao 1
	setlocale(LC_ALL, "Portuguese");
	struct dados_cadastro projeto;
	FILE *arquivo_palestras = fopen(nome_arquivo_palestras, "a");
	if( arquivo_palestras == NULL){
		arquivo_palestras = fopen(nome_arquivo_palestras, "w");
	}
	int confirmacao;
	do{
        printf("Bem vindo ao cadastro de projetos\nPara comessar porfavor digite o codigo do projeto: ");
        scanf("%d", &projeto.codigo);
        getchar();
        printf("Agora digite o nome do autor do projeto: ");
        gets(projeto.autor);
        do{
        printf("Digite a opção correspondente a area do conhecimento deste projeto\n");
        print_area_conhecimento();
        scanf("%d", &projeto.area_do_conhecimento);
        getchar();
        }while(projeto.area_do_conhecimento<1 || projeto.area_do_conhecimento>7);
        printf("Agora digite o nome do projeto: ");
        gets(projeto.titulo);
        printf("Agora digite o nome do orientador do projeto: ");
        gets(projeto.orientador);
        printf("Existem coautores neste projeto? ( [ 1 ] - para sim e [ 0 ] - para não)\n ");
        scanf("%d", &projeto.verificacao_coautor);
        getchar();
        if(projeto.verificacao_coautor == 1){
            printf("Digite o nome do coautor: ");
            gets(projeto.coautor);
        }
        printf("Existem coorientadores neste projeto? ( [ 1 ] - para sim e [ 0 ] - para não)\n ");
        scanf("%d", &projeto.verificacao_coorientador);
        getchar();
        if(projeto.verificacao_coorientador == 1){
            printf("Digite o nome do coorientador: ");
            gets(projeto.coorientador);
        }
        projeto.status = -1;
        projeto.nota = -1;
        printf("Deseja corigir algo?\n[ 1 ] para sim ou [ 0 ] para nao\n");
        scanf("%d", &confirmacao);
    }while(confirmacao != 0);
	salvar_candidato_unico(arquivo_palestras, projeto);
	fclose(arquivo_palestras);
}

void print_candidato_para_debug(struct dados_cadastro candidato_unico){
	setlocale(LC_ALL, "Portuguese");
	printf("\n\n");
	printf("Titulo :%sStatus: %d\nNota: %f\n", candidato_unico.titulo, candidato_unico.status, candidato_unico.nota);
	printf("Autor: %s", candidato_unico.autor);
	//printf("Existencia de coautor: %d\n", candidato_unico.verificacao_coautor); // somente usado para debug
	if( candidato_unico.verificacao_coautor == 1){
		printf("Coautor :%s", candidato_unico.coautor);
	}
	printf("Orientador: %s", candidato_unico.orientador);
	//printf("Existencia de coorientador: %d\n",candidato_unico.verificacao_coorientador); // somente usado para debug
	if( candidato_unico.verificacao_coorientador == 1){
		printf("coorientador: %s", candidato_unico.coorientador);
	}
	printf("Área do conhecimento: %d\n", candidato_unico.area_do_conhecimento);
	printf("Codigo: %d\n", candidato_unico.codigo);
	//printf("aperte entrer apra proseguir");
	//getchar();
}

void salvar_candidato(FILE *arquivo_palestras, struct dados_cadastro *projeto, int j){
	setlocale(LC_ALL, "Portuguese");
	printf("\nestou salvamdo o trabalgo de codigo: %d\n", projeto[j].codigo);
	tirar_enter(projeto[j].titulo);
	fprintf(arquivo_palestras, "\n%s\nStatus: %d\nNota: %f\n", projeto[j].titulo, projeto[j].status, projeto[j].nota);
	tirar_enter(projeto[j].autor);
	fprintf(arquivo_palestras, "%s\n", projeto[j].autor);
	fprintf(arquivo_palestras, "Existencia de coautor: %d\n", projeto[j].verificacao_coautor);
	if( projeto[j].verificacao_coautor == 1){
        tirar_enter(projeto[j].coautor);
		fprintf(arquivo_palestras, "%s\n", projeto[j].coautor);
	}
	tirar_enter(projeto[j].orientador);
	fprintf(arquivo_palestras, "%s\n", projeto[j].orientador);
	fprintf(arquivo_palestras,"Existencia de coorientador: %d\n",projeto[j].verificacao_coorientador);
	if( projeto[j].verificacao_coorientador == 1){
        tirar_enter(projeto[j].coorientador);
		fprintf(arquivo_palestras, "%s\n", projeto[j].coorientador);
	}
	fprintf(arquivo_palestras, "Area do conhecimento: %d\n", projeto[j].area_do_conhecimento);
	fprintf(arquivo_palestras, "Codigo: %d", projeto[j].codigo);
	printf("projeto salvo\n");
}

void salvar_candidato_unico(FILE *arquivo_palestras, struct dados_cadastro projeto){
   	setlocale(LC_ALL, "Portuguese");
	printf("\nestou salvamdo o trabalgo de codigo: %d\n", projeto.codigo);
	tirar_enter(projeto.titulo);
	fprintf(arquivo_palestras, "\n%s\nStatus: %d\nNota: %f\n", projeto.titulo, projeto.status, projeto.nota);
	tirar_enter(projeto.autor);
	fprintf(arquivo_palestras, "%s\n", projeto.autor);
	fprintf(arquivo_palestras, "Existencia de coautor: %d\n", projeto.verificacao_coautor);
	if( projeto.verificacao_coautor == 1){
        tirar_enter(projeto.coautor);
		fprintf(arquivo_palestras, "%s\n", projeto.coautor);
	}
	tirar_enter(projeto.orientador);
	fprintf(arquivo_palestras, "%s\n", projeto.orientador);
	fprintf(arquivo_palestras,"Existencia de coorientador: %d\n",projeto.verificacao_coorientador);
	if( projeto.verificacao_coorientador == 1){
        tirar_enter(projeto.coorientador);
		fprintf(arquivo_palestras, "%s\n", projeto.coorientador);
	}
	fprintf(arquivo_palestras, "Area do conhecimento: %d\n", projeto.area_do_conhecimento);
	fprintf(arquivo_palestras, "Codigo: %d", projeto.codigo);
	printf("projeto salvo\n");
}

void salvar_projetos_aprovados( struct dados_cadastro *aprovados, const int i, const char nome_arquivo_palestras ){
	setlocale(LC_ALL, "Portuguese");
	FILE *file = fopen("arquivo organizado.txt", "w");
    int j;
	for( j=0; j<i; j++){
       // print_candidato_para_debug(aprovados[j]);
        salvar_candidato( file,aprovados, j );
	}
	fclose (file);
}

void print_area_conhecimento(){
    setlocale(LC_ALL, "Portuguese");
	printf("[ 1 ] - Para Ciências da Saúde;\n[ 2 ] - Para Ciências Exatas;\n[ 3 ] - Para Ciências agrárias;\n[ 4 ] - Engenharias;\n");
	printf("[ 5 ] - Ciências Sociais;\n[ 6 ] - Ciências Humanas;\n[ 7 ] - Linguística, Letras e artes.\n");
}

void tirar_enter(char *str1){
    setlocale(LC_ALL, "Portuguese");
    int i;
    for( i=0; str1[i] !='\n' && str1[i] !=0 ; i++){ // chega ate o 1 caracter antes do '\n'
    }
    str1[i]=0; // coloca o '\0' no lugar do '\n'
}
