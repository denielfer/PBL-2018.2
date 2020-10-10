/*******************************************************************************
Autor: Daniel Fernandes Campos
Componente Curricular: Algoritmos I
Concluido em: 22/11/2018
Declaro que este código foi elaborado por mim de forma individual e não contém nenhum
trecho de código de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e páginas ou documentos eletrônicos da Internet. Qualquer trecho de código
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte
do código, e estou ciente que estes trechos não serão considerados para fins de avaliação.
******************************************************************************************/
#include<stdio.h> /* entrada e saida de dados*/
#include <locale.h> /* lingiagem em portugues no printf*/
#include <stdlib.h>/* ... */
#include <string.h>/* comparaçao de string( preguiça de criar funçao ( na real eu achei que ja tinha feito ) )*/
struct geral { // struct base para ser usada para escala e questao
	int numero_da_struct; // conta o numero da qeustao ou escala
	int codigo_usado; // codigo da escala ou codigo chamado da questao
	char texto_total[350]; // texto total que sera separado se escala
	char escala_resposta[10][30];
};
struct dados{
	char curso[51];
	char sexo[11];
	int idade;
	int respostas[100];
};
/****************************************************************************************************************************************************************************************
================================================================QUADRO DE INFORMAÇÕES DO CODIGO===========================================================================================
INFORMAÇÕES:
 - Para ir para a funçao chamada no codigo basta clicar ctrl + right click, serve para variavel tambem

DUVIDAS E PROBLEMAS:

****************************************************************************************************************************************************************************************/
/* Funçoes usadas */
int abrir_escala( char nome_arquivo[101] , int quantidade, int  *contador_quantidade_escalas, struct geral *escala); // funçao para abrir o arquivo e verificar se deu certo
int abrir_perguntas( char nome_arquivo[101] , int quantidade, int  *contador_quantidade_perguntas, struct geral *perguntas ); // funçao para abrir o arquivo e verificar se deu certo
void print(struct geral *x, int i); // usado para checar se a struc ta certa
int print_pergunta( struct geral perguntas, struct geral *escalas, int contador_quantidade_escalas );
int verificador_de_codigo(int codigo, struct geral *escala, int contador_qunatidade_escalas);// ver qual codigo sera usado com pergunta ( linka pergunta a escalas usadas para responder)
void separador_de_escalas( struct geral *escala, int c);
void menu_pesquisado(struct dados *intrevistado, int numero_intrevistado );
void salvar_resultados( struct dados *intrevistado, int numero_intrevistado, int contador_quantidade_perguntas );
void pesquisa( int numero_intrevistado, struct dados *intrevistado, struct geral *escala, struct geral *perguntas, int *contador_quantidade_perguntas, int *contador_quantidade_escalas );
void ver_resultado( int check , struct dados *intrevistado, struct geral *escala, struct geral *perguntas,int *ponteiro_quantidade_perguntas, int *ponteiro_quantidade_escalas );
void print_resultado( int numero_intrevistado, struct dados *intrevistado, int numero_perguntas, struct geral *escala, struct geral *perguntas);
void print_cursos();
float escore_individual(struct dados *intrevistado, struct geral *escala, struct geral *perguntas, int numero_intrevistado, int *contador_perguntas);
float media_individual(struct dados *intrevistado, struct geral *escala, struct geral *perguntas, int numero_intrevistado, int *contador_perguntas);
int moda_individual(struct dados *intrevistado, struct geral *escala, struct geral *perguntas, int numero_intrevistado, int *contador_perguntas);

int main(){ // the menu
	setlocale(LC_ALL, "Portuguese");
	int escolha, ajuda=0, check=0, i ;
	char nome_arquivo[51];
    int  contador_quantidade_perguntas=0;
	int *ponteiro_quantidade_perguntas = &contador_quantidade_perguntas;
    int  contador_quantidade_escalas=0, *ponteiro_quantidade_escalas = &contador_quantidade_escalas;
	struct dados intrevistado[1000]; // struct onde fica os dados dos intrevistados e suas respostas
	struct geral escala[20]; // structe onde fica as escalas e os codigos
	struct geral perguntas[100]; //struct onde fica as perguntas e os codigos

	printf("Ola, bem vindo!\nNeste programa voce podera fazer pesquisas, ver resultados de pesqusias e ser feliz :) \n");
	do{
		printf("Para comessar digite o nome do arquivo das escalas com o '.txt ' com ate 50 caracteres. ( EXEMPLO: NomeDoArquivo.txt ) \n");
	    scanf("%s", &nome_arquivo);
	    fflush(stdin);
		ajuda = 20;
		check = abrir_escala( nome_arquivo, ajuda, ponteiro_quantidade_escalas, escala );
		if(check == 0){
	    	printf("\nEscala nao aberta. Tente novamente.\n\n");
		}
	}while(check == 0);
	for (i=0; i< contador_quantidade_escalas; i++){
			print( escala, i );
	}
	do{
		printf("digite o nome do arquivo das perguntas com o '.txt ' com ate 50 caracteres. ( EXEMPLO: NomeDoArquivo.txt ) \n");
		scanf("%s", &nome_arquivo);
		ajuda = 100;
		check = abrir_perguntas( nome_arquivo, ajuda, ponteiro_quantidade_perguntas, perguntas);
		if(check == 0){
	    	printf("\nperguntas nao aberta tente novamente.\n\n");
		}
	} while (check == 0);
	for (i=0; i<contador_quantidade_perguntas; i++){
		print( perguntas, i );
	}
	for ( i=0; i<contador_quantidade_escalas; i++  ) {
		separador_de_escalas( escala, i );
	}
	contador_quantidade_perguntas--;
	getchar();
	printf( " Numero de perguntas %i \n", contador_quantidade_perguntas);
	while(1){
		do{// este é o loop caso click alguma coisa que nao ta nas opçoes
			fflush(stdin);
			printf("\n\n\nEntao o que deseja fazer?\n[ 1 ] - Para fazer pesquisa \n[ 2 ] - Para ver resultados\n[ 3 ] - Para continuar pesquisa\n[ 4 ] - Para sair\n");
			scanf("%d", &escolha);
			getchar();
			switch(escolha){
				case 1:
					pesquisa( 0, intrevistado, escala, perguntas, ponteiro_quantidade_perguntas, ponteiro_quantidade_escalas );
					break;
				case 2:
					ver_resultado(1, intrevistado, escala, perguntas, ponteiro_quantidade_perguntas, ponteiro_quantidade_escalas );
					break;
				case 3: // nao precisa pq o fazer pesquisa salva como apendice e como nao tem o numero do intrevistado sendo salvo la é so ir jogando normal como ta sendo feito e no final ler o arquivo de resultados.
					ver_resultado(0, intrevistado, escala, perguntas, ponteiro_quantidade_perguntas, ponteiro_quantidade_escalas );
					break;
                case 4:
                    return 0;
				default :
					printf("\ntente novamente\n");
			}
		}while( escolha < 1 && escolha > 3 );
	}
}

void ver_resultado( int check , struct dados *intrevistado, struct geral *escala, struct geral *perguntas, int *ponteiro_quantidade_perguntas, int *ponteiro_quantidade_escalas ){
	setlocale(LC_ALL, "Portuguese");
	FILE *file;
	char nome_arquivo[50];
	int numero_intrevistado = 0;
	do{
		printf("Digite o nome do arquivo de resultados com final .txt [ exemplo.txt ]. ");
		scanf("%s", &nome_arquivo);
		file = fopen( nome_arquivo, "r");
		if( file == NULL ){
			printf("Arquivo nao achado! Tente novamente.\n");
		}
	}while( file == NULL );
	int i;
	while (feof(file) == 0 && numero_intrevistado < 1000 ) {
		fgets(intrevistado[numero_intrevistado].curso, 51, file);
		for(i=0; intrevistado[ numero_intrevistado ].curso[i] != 0; i++){
			if(intrevistado[ numero_intrevistado ].curso[i] == '\n'){
				intrevistado[ numero_intrevistado ].curso[i] = 0;	
			}
		}
		fgets(intrevistado[numero_intrevistado].sexo, 11, file);
		for(i=0; intrevistado[ numero_intrevistado ].sexo[i] != 0; i++){
			if(intrevistado[ numero_intrevistado ].sexo[i] == '\n'){
				intrevistado[ numero_intrevistado ].sexo[i] = 0;	
			}
		}
		fscanf(file, "%d", &intrevistado[numero_intrevistado].idade);
		for( i = 0 ; i < *ponteiro_quantidade_perguntas ; i++ ){
			fscanf(file, "%d", &intrevistado[numero_intrevistado].respostas[i] ); // o %c é para pegar o espaço que separa os numeros ( no caso da resposta da ultima pergunta o 1 fgets do procimo intrevistado pegaria isso ao invez do nome do curso
		}
		numero_intrevistado++;
		if( fgetc(file) == NULL){
			break;
		}
	}
	printf(" \n\nNumero de intrevistados achados: %d\n\n\n",numero_intrevistado); // Para debug contar a quantidde de vezes que o loop ta indo
	if( check == 0){ // como passa os dados da struct aqui pra a pesquisa, se eu bota ponteiro quando eu for fazer perquisa teria q bota ponteiro tambem dai eu teria que declarar as structs na main e passa pra todas como ponteiro
		pesquisa( numero_intrevistado, intrevistado, escala, perguntas, ponteiro_quantidade_perguntas, ponteiro_quantidade_escalas );
	}
	if( check == 1){ // chama funçao que printara os resultados da pesquisa
		print_resultado(numero_intrevistado, intrevistado, *ponteiro_quantidade_perguntas, escala, perguntas);
	}
}

void print_resultado( int numero_intrevistado, struct dados *intrevistado, int numero_perguntas, struct geral *escala, struct geral *perguntas){
	setlocale(LC_ALL, "Portuguese");
	int pergunta_inicial, pergunta_final;
	int matriz_respostas_por_pergunta[1000 /* linha */ ][100 /*coluna*/ ]; // matriz que tem reesposta do intrevistado, em linha, por perguta, em coluna.
	int matriz_contador_respostas[100][10];
	int i , p, ajuda=0, contador=0, x = 0 ;
	float media_respostas[100] ;
	printf("Qual a pergunta inicial?\n");
	scanf("%d", &pergunta_inicial);
	getchar();
	printf("Qual a pergunta final?\n");
	scanf("%d", &pergunta_final);
	getchar();

	// Variveis pra filtragem por genero e curso
	int verificacao[3][2], intrevistados_a_serem_vistos[1001];
	char nome_filtragem[51];
	i=0;
	while( i<1001 ){
		intrevistados_a_serem_vistos[i] = 1;
		i++;
	}

	// FILTRAGEM PARA CURSO
	fflush(stdin);
	printf("Deseja fazer filtragem por cuso?\nDigite [ 1 ] - Para SIM e [ 0 ] - Para NÃO\n");
	scanf("%d", &verificacao[1][1]);
	getchar();
	if( verificacao[1][1] == 1){
		printf("Digite o nome do curso que deseja filtrar, segue modelo:");
		print_cursos();
		gets(nome_filtragem);
		for(i=0; nome_filtragem[i] != 0; i++){
			if(nome_filtragem[i] == '\n'){
				nome_filtragem[i] = 0;	
			}
		}
		for( i=0; nome_filtragem[i] != 0; i++ ){ // isso serve pra tirar o \n se estiver entrando ( sugestao para tirar o bug)
			if (nome_filtragem[i] == '\n'){
				nome_filtragem[i] = 0;
			}
		}
		p = 0;
		for( i = 0; i < numero_intrevistado; i++){
			verificacao[1][2] = strcmp(nome_filtragem, intrevistado[i].curso);
			if(verificacao[1][2] != 0){
				intrevistados_a_serem_vistos[i] = 0;
			}
		}
	}
    // FILTRAGEM PARA SEXO
	fflush(stdin);
	printf("Deseja fazer filtragem por genero?\nDigite [ 1 ] - Para SIM e [ 0 ] - Para NÃO\n");
	scanf("%d", &verificacao[2][1]);
	getchar();
	if( verificacao[2][1] == 1){
		printf("Digite o nome do genero que deseja filtrar, segue modelo: ( modelo : masculino / feminino )\n");
		gets(nome_filtragem);
		for(i=0; nome_filtragem[i] != 0; i++){
			if(nome_filtragem[i] == '\n'){
				nome_filtragem[i] = 0;	
			}
		}
		for( i=0; nome_filtragem[i] != 0; i++){
			if (nome_filtragem[i] == '\n'){
				nome_filtragem[i] = 0;
			}
		}
		p = 0;
        for( i = 0; i < numero_intrevistado ; i++){
            if(intrevistados_a_serem_vistos[i] == 1){
				verificacao[2][2] = strcmp(nome_filtragem, intrevistado[ i ].sexo);
				if(verificacao[2][2] != 0){
					intrevistados_a_serem_vistos[i] = 0;
				}
			}
		}
	}
	// FILTRAGEM PARA IDADE
	int idade_minima_filtragem, idade_maxima_filtragem;
	fflush(stdin);
	printf("Deseja fazer filtragem por idade?\nDigite [ 1 ] - Para SIM e [ 0 ] - Para NÃO\n");
	scanf("%d", &verificacao[3][1]);
	if( verificacao[3][1] == 1){
		printf("Digite idade minima da faixa: ");
		scanf("%d", &idade_minima_filtragem);
		printf("Digite idade maxima da faixa: ");
		scanf("%d", &idade_minima_filtragem);
		getchar();
		p = 0;
		for( i = 0; i < numero_intrevistado; i++){
            if(intrevistados_a_serem_vistos[i] == 1){
				if( intrevistado[ i ].idade < idade_minima_filtragem || intrevistado[ i ].idade > idade_maxima_filtragem ){
                    intrevistados_a_serem_vistos[i] = 0;
				}
			}
        }
	}
	pergunta_inicial = pergunta_inicial-1; // foi feito isso porque contadores de matriz comessa no 0
	for (i=0; i<1000; i++){
		for(p=0; p<100; p++){
			matriz_respostas_por_pergunta[i][p]=0;
		}
	}
	printf(" \n intrevistados em ordem ( 0 esta fora dos requisitos colocados e 1 estara dentro da analize) :  ");
	ajuda = 0;
	for( i=0; i < numero_intrevistado; i++){
        printf("%d", intrevistados_a_serem_vistos[i]);
        ajuda+= intrevistados_a_serem_vistos[i];
	}
	printf("\n");
	for (i=0; i<100; i++){
		for(p=0; p<10; p++){
			matriz_contador_respostas[i][p]=0;
		}
	}
	if( ajuda == 0 ){ // se nao tiver nenhum intrevistado dentro dos parametros da analize
		printf("\n\n\n\nNenhum intrevistado se enquandra no padrao\n");
		return;
    }
    for ( i=0 ; i < numero_intrevistado ; i++){ // i é intrevistado
        for( p=0 ; p< numero_perguntas; p++ ){// p é pergunta
            if(intrevistados_a_serem_vistos[i] == 1){
                matriz_respostas_por_pergunta[i][p] = intrevistado[ i ].respostas[p];
                matriz_contador_respostas[p][intrevistado[ i ].respostas[p]]++;

            }
        }	
    }
	// variaveis pra moda
	int valor_moda_pergunta[100];// indica o valor da moda ( quantidade de pessoas que marcaram a respostas)
	for( i = 0; i < 100; i++ ){
		valor_moda_pergunta[i]=0;
	}
	//printf("\n\nentrando no loop que printa moda\n\n\n"); // para debug essa parte nao estava funcionando usei pra ver ate onde ia*******************************************************
	for( p = pergunta_inicial; p < pergunta_final; p++ ){// p é o numero da pergunta atual
		contador = 0;
		ajuda = 0;
		for( i=0; i < escala[perguntas[p].codigo_usado-1].codigo_usado; i++){ // i é o numero da escala resposta.
		//*********************************************************************************************************************************************************************************]
		// PARTE DO LOOP QUE calcula a moda e escore
			ajuda += matriz_contador_respostas[p][i] * (i+1);// tem o mais 1 pois i comessa de 0
			contador += matriz_contador_respostas[p][i];
			if(valor_moda_pergunta[p] < matriz_contador_respostas[p][i]){
				valor_moda_pergunta[p] = matriz_contador_respostas[p][i];
			}
		}//**********************************************************************************************************************************************************************************
	media_respostas[p] = (float)ajuda/contador;
	}
	for( p = pergunta_inicial; p < pergunta_final; p++ ){
		// PARTE DO LOOP QUE PRINTA PERGUNTA , MEDIA E MODAS
		printf("\nA media  das respostas da pergunta %d é : %f ", p+1 , media_respostas[p] );
		for( i = 0; i <escala[perguntas[p].codigo_usado-1].codigo_usado; i++ ){
			if( i == 1 ){
				printf("Sendo moda: ");
			}
			if(valor_moda_pergunta[p] == matriz_contador_respostas[p][i]){
				printf("%s ;", escala[perguntas[p].codigo_usado-1].escala_resposta[i] );
			}
		}//**********************************************************************************************************************************************************************************
		//PARTE DO LOOP QUE MOSTRA FREQUENCIA ABSOLUTA DAS PERGUTNAS
		printf("\nRespostas dadas :\n");
		for( i = 0; i < escala[perguntas[p].codigo_usado-1].codigo_usado; i++ ){
			printf("Para - ");
			printf("%s - Frequecia absoluta = %d \n", escala[ perguntas[p].codigo_usado-1 ].escala_resposta[i], matriz_contador_respostas[p][i+1]);
		}//************************************************************************************************************************************************************************************
		printf("\n\n");
	}
}

void pesquisa( int numero_intrevistado, struct dados *intrevistado, struct geral *escala, struct geral *perguntas, int *contador_quantidade_perguntas, int *contador_quantidade_escalas ){
    setlocale(LC_ALL, "Portuguese");
	int i=0, pesquisa =1 , j = 0 , l = 0, valor_maximo_escala /* essa variavel foi criado pois as questoes de 4 a 6 ou 4 a 8 sao problematicas*/ ;
	// aqui comessa o loop de intrevistado *******************************************************************************************************
	for( ; numero_intrevistado<1000; numero_intrevistado++ ){// aqui comessa o loop de intrevistado
		printf("\n");
		for( i = 0; i < 39; i++){ // joga pesquisa feita com o intrevistao pra cima pra ficar mais limpa a tela
			printf("_____________________");
		}
		fflush(stdin);	
		printf("\n\t\t\t\t\tIntrevistado numero %d\n\n", numero_intrevistado+1);
		menu_pesquisado( intrevistado, numero_intrevistado );
		for (i=0; i<*contador_quantidade_perguntas; i++ ){// aqui comessa o loop das questoes
			do{
				printf ("\n QUESTÃO %d - ", i+1);
				valor_maximo_escala = print_pergunta(perguntas [ i ] , escala , *contador_quantidade_escalas);
				scanf("%d", &intrevistado[numero_intrevistado].respostas[i]);
				fflush(stdin);
			}while( intrevistado[numero_intrevistado].respostas[i] <= 0 || intrevistado[numero_intrevistado].respostas[i] > valor_maximo_escala );
		}
		printf("Dados do pesquisado: \n");
		printf("%s\n%s\n%d\nRespostas: "
			,intrevistado[numero_intrevistado].curso,intrevistado[numero_intrevistado].sexo,intrevistado[numero_intrevistado].idade);
		for(i=0; i< *contador_quantidade_perguntas; i++ ){
			printf("%d", intrevistado[ numero_intrevistado ].respostas[ i ]);
		}
		salvar_resultados(intrevistado, numero_intrevistado, *contador_quantidade_perguntas);
		printf ("\n O escore do intrevistado %d de 1 a 10 eh: %f , sendo a moda das respostas: %d  e a media das respostas foi: %f \n", 
				numero_intrevistado+1, escore_individual(intrevistado, escala, perguntas, numero_intrevistado, contador_quantidade_perguntas),
				moda_individual(intrevistado, escala, perguntas, numero_intrevistado, contador_quantidade_perguntas),
				media_individual(intrevistado, escala, perguntas, numero_intrevistado, contador_quantidade_perguntas) );
		printf("\nDeseja fazer com outro intrevistado?\nDigite [ 1 ] - para fazer\nDigite [ 2 ] - para encerar a pesquisa\n");
		scanf("%d", &pesquisa);
		getchar();
		if( pesquisa == 2){
			printf("Pesquisa terminada!!!\n");
			//print_resultado(numero_intrevistado, intrevistado, *contador_quantidade_perguntas, escala, perguntas); ***coloca o print dos resultados ou nao ?***********
			break;//                                                                                                 *************************************************
		}
		for( i = 0; i < 10; i++){ // joga pesquisa feita com o intrevistao pra cima pra ficar mais limpa a tela
			printf("\n");
		}
	}
}

void menu_pesquisado(struct dados *intrevistado, int numero_intrevistado){
	setlocale(LC_ALL, "Portuguese");
	int c, i = 0;
	do{
		printf(" Digite o nome do seu curso, segue modelo: ");
		print_cursos();
		gets(intrevistado[ numero_intrevistado ].curso);
		for(i=0; intrevistado[ numero_intrevistado ].curso[i] != 0; i++){
			if(intrevistado[ numero_intrevistado ].curso[i] == '\n'){
				intrevistado[ numero_intrevistado ].curso[i] = 0;	
			}
		}
		printf("\nDeseja redigitar?\n 1 - para sim\n 2 - para não\n");
		scanf("%d", &c);
		fflush(stdin);
	}while( c != 2 );
	do{
		printf(" Digite seu sexo ( modelo : masculino / feminino ):");
		gets(intrevistado[ numero_intrevistado ].sexo);
		for(i=0; intrevistado[ numero_intrevistado ].sexo[i] != 0; i++){
			if(intrevistado[ numero_intrevistado ].sexo[i] == '\n'){
				intrevistado[ numero_intrevistado ].sexo[i] = 0;	
			}
		}
		printf("\nDeseja redigitar?\n 1 - para sim\n 2 - para não\n");
		scanf("%d", &c);
		fflush(stdin);
	}while( c != 2 );
	do{
		printf(" Digite sua idade.  ");
		scanf("%d", &intrevistado[ numero_intrevistado ].idade);
		getchar();
		if(intrevistado[ numero_intrevistado ].idade <0 || intrevistado[ numero_intrevistado ].idade>100){
			printf(" Essa idade nao é aceita po é maior que 100 ou menor de 0! Digite novamente!\n ");
		}
	}while(intrevistado[ numero_intrevistado ].idade <=0 || intrevistado[ numero_intrevistado ].idade>100);
}

void salvar_resultados( struct dados *intrevistado, int numero_intrevistado, int contador_quantidade_perguntas ){
	setlocale(LC_ALL, "Portuguese");
	int i=0, j = 0;
	FILE *salvar;
	salvar = fopen("respostas.txt", "a");
	if( salvar == NULL){
		salvar = fopen( "respostas.txt", "w" );
	}
	fprintf (salvar,"\n" );
		fprintf(salvar,"%s\n%s\n%d\n"
			,intrevistado[numero_intrevistado].curso,intrevistado[numero_intrevistado].sexo,intrevistado[numero_intrevistado].idade);
	for( i = 0; i < contador_quantidade_perguntas ; i++ ){
		if(i+1 == contador_quantidade_perguntas){
			fprintf(salvar,"%d", intrevistado[numero_intrevistado].respostas[i]); // se for o ultimo elemento salva sem o espaço depois do numero
		}
		else{
			fprintf(salvar,"%d ", intrevistado[numero_intrevistado].respostas[i]);
		}
	}
	fclose ( salvar );
}

int abrir_escala( char nome_arquivo[101] , int quantidade, int  *contador_quantidade_escalas, struct geral *escala){
	setlocale(LC_ALL, "Portuguese");
	int i =0;
	FILE *file;
	file = fopen (nome_arquivo, "r") ;
	if( file == NULL){
		printf("arquivo não aberto! algo inesperado aconteceu!!!");
		return 0;
	}
	char str1[350], str2[350];
    while(feof(file) == 0 && *contador_quantidade_escalas < quantidade){
    	fscanf (file, "%i", &escala[i].numero_da_struct);
		fscanf (file, "%i", &escala[i].codigo_usado);
		fgetc(file);
    	fgets(escala[i].texto_total, 350, file);
    	*contador_quantidade_escalas +=1;
    	i++;
	//	printf("escala %i pega\n", *contador_quantidade_escalas); <---- para dbug caso tenha problema com escala serve para ver quantas escalas pegas
	}
	fclose(file);
	return 1;
}

void separador_de_escalas( struct geral *escala, int c){
	setlocale(LC_ALL, "Portuguese");
	int i = 0 , j = 0 , cont =0 ;
//	printf("%s \n", escala[c].texto_total); // <-- para debug em caso de escala nao esta sendo pega
	while( escala[c].texto_total[cont] != 0 ) {
		if( escala[c].texto_total[cont] != ',' ) {
			escala[c].escala_resposta[i][j] = escala[c
			].texto_total[cont];
			j++;
		}
		else{
			escala[c].escala_resposta[i][j] = '\0';
		//	printf("%s \n", escala[c].escala_resposta[i] ); // nao printa a ultima pq nao reentra no loop pra entra no else <----------- esse printe serve para testa se as escalas
		//   estao sendo colocadas no lugar mais para dbug
			i++;
			j=0;
		}
		cont++;
	}
}

int abrir_perguntas( char nome_arquivo[101] , int quantidade, int *contador_quantidade_perguntas, struct geral *perguntas){
	setlocale(LC_ALL, "Portuguese");
	int i=0;
	FILE *file;
	file = fopen (nome_arquivo, "r") ;
	if( file == NULL){
		printf("arquivo não aberto! algo inesperado aconteceu!!!\n\n");
		return 0;
	}
    while(feof(file) == 0 && i < quantidade){
		fgets(perguntas[i].texto_total, 350, file);
		fscanf (file, "%i", &perguntas[i].codigo_usado);
		fgetc(file);
		i++;
    	perguntas[i].numero_da_struct = i;
    //	printf("escala %i pega\n", i); // <---- serve para checa quantas perguntas foram pegas, mais para debug em caso de perguntas nao estaren sendo lidas
	}
	fclose(file);
	*contador_quantidade_perguntas = i+1;
	return 1;
}

int print_pergunta( struct geral perguntas, struct geral *escala, int contador_quantidade_escalas ){
	setlocale(LC_ALL, "Portuguese");
	int j = 0 , escala_usada;
	printf(" %s", perguntas.texto_total);
	escala_usada = verificador_de_codigo( perguntas.codigo_usado, escala,  contador_quantidade_escalas);
	for( j = 0; j < escala[escala_usada].codigo_usado; j++ ){
		printf("\nDigite %d para - ", j+1);
		printf("%s", escala[escala_usada].escala_resposta[j]);
	}
	printf("\n");
	return j;
}

int verificador_de_codigo(int codigo, struct geral *escala, int contador_quantidade_escalas){
	setlocale(LC_ALL, "Portuguese");
	int i=0;
	while ( i < contador_quantidade_escalas ){
		if( escala[i].numero_da_struct == codigo)
			return i;
		else
			i++;
	}
	printf("nao achou escala!!!!");
	return -1;
}

void print(struct geral *x, int i ){
	setlocale(LC_ALL, "Portuguese");
	printf("coisa %d :  ", i+1 );
	printf("  %d   %d   %s\n", x[i].numero_da_struct, x[i].codigo_usado, x[i].texto_total);
}

void print_cursos(){
		printf("\n \tAgronomia, \tAdministracao, \tCiencias Contabeis, \tCiencias Economicas, \tCiencias Farmaceuticas, \tDireito, \n");
		printf(" \tEnfermagem, \tEngenharia Civil, \tEngenharia de Alimentos, \n\tEngenharia da Computacao, \tCiências Biologicas, \n");
		printf(" \tFisica, \n\tEnsino Fundamental, \tGeografia,");
		printf(" \tHistoria, \tLetras com Espanhol, \n\tLetras com Frances, \tLetras com Ingles,");
		printf(" \tLetras ( para Letras Vernaculas), \tMatematica, \n\tPedagogia, \tMedicina, \tMusica ou \tOdontologia. \n");
}

float escore_individual(struct dados *intrevistado, struct geral *escala, struct geral *perguntas, int numero_intrevistado, int *contador_perguntas){
	float escore = 0;
	int i;
	for(i=0; i < *contador_perguntas; i++){
		escore += intrevistado[ numero_intrevistado].respostas[i]/(escala[ perguntas[i].codigo_usado ].codigo_usado * 1.0);// o vezes 1.0 é pra confirma q ta em float
	}
	escore= (escore/ *contador_perguntas ) *10;
	return escore;
}

float media_individual(struct dados *intrevistado, struct geral *escala, struct geral *perguntas, int numero_intrevistado, int *contador_perguntas){
	float media = 0;
	int i;
	for(i=0; i < *contador_perguntas; i++){
		media += (float)intrevistado[ numero_intrevistado].respostas[i];
	}
	media = media/ *contador_perguntas;
	return media;
}

int moda_individual(struct dados *intrevistado, struct geral *escala, struct geral *perguntas, int numero_intrevistado, int *contador_perguntas){
	int moda[20], ajuda = 0, posicao_moda;
	int i;
	for (i =0; i<*contador_perguntas; i++){
		moda[i]=0;
	}
	for(i = 0; i< *contador_perguntas; i++){
		moda[ intrevistado[ numero_intrevistado ].respostas[i] ]++;
	}
	for(i = 0; i< *contador_perguntas; i++){
		if( moda[i] > ajuda){
			ajuda = moda[i];
			posicao_moda = i;
		}
	}
	return posicao_moda;
}
