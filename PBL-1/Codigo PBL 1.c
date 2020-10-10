/*******************************************************************************
Autor: Daniel Fernandes Campos
Componente Curricular: Algoritmos I
Concluido em: 14/10/2011
Declaro que este código foi elaborado por mim de forma individual e não contém nenhum
trecho de código de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e páginas ou documentos eletrônicos da Internet. Qualquer trecho de código
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte
do código, e estou ciente que estes trechos não serão considerados para fins de avaliação.
******************************************************************************************/
#include <stdio.h>/*print scan*/
#include <string.h>/*system*/
#include <locale.h>/*letras com acento funcionar*/
int main(){
    setlocale(LC_ALL,"portuguese");/* para poder usar "caracteres especiais" ( usar letras com acento e ç)*/
    /*um bucado de variaveis usado em contagem de idade, curso, quantidade de entrevistados por clases( cursos, sexo e idade)*/
    int idade=0,curso=0,confirmacao=0,homens_intrevistados=0,entrevistados_total=0,eng_entrevistados=0, medicina_entrevistado=0, historia_entrevistados=0, letras_vernaculas_estrevistados=0, mulheres_entrevistadas=0, faixa_etaria1_entrevistado=0,faixa_etaria2_entrevistado=0,faixa_etaria3_entrevistado=0;
    int sexo=0, desistentes=0;
    /*confirmações usadas para substituir o goto*/
    int conf_idade=0;
    /*variaveis de resultado do pesquisado*/
    float submissao_a_autoridade=0, agressividade_autoritaria=0, convencionalismo=0, indice_de_propensao_ao_aotoritarismo=0;
    /*variaveis para salvar dados de classes ( cursos, sexo, idade e toda a pesquisa)*/
    float submissao_a_autoridade_homem=0, submissao_a_autoridade_mulher=0, submissao_a_autoridade_eng=0, submissao_a_autoridade_medicina=0, submissao_a_autoridade_historia=0, submissao_a_autoridade_letras=0, submissao_a_autoridade_faixa_etaria1=0,submissao_a_autoridade_faixa_etaria2=0, submissao_a_autoridade_faixa_etaria3=0, submissao_a_autoridade_total=0;
    float agressividade_autoritaria_homem=0, agressividade_autoritaria_mulher=0, agressividade_autoritaria_eng=0, agressividade_autoritaria_medicina=0, agressividade_autoritaria_historia=0, agressividade_autoritaria_letras=0, agressividade_autoritaria_faixa_etaria1=0, agressividade_autoritaria_faixa_etaria2=0, agressividade_autoritaria_faixa_etaria3=0, agressividade_autoritaria_total=0;
    float convencionalismo_homen=0, convencionalismo_mulher=0, convencionalismo_eng=0, convencionalismo_medicina=0, convencionalismo_historia=0, convencionalismo_letras=0, convencionalismo_faixa_etaria1=0, convencionalismo_faixa_etaria2=0, convencionalismo_faixa_etaria3=0, convencionalismo_total=0;
    float indice_de_propensao_ao_aotoritarismo_homem=0, indice_de_propensao_ao_aotoritarismo_mulher=0, indice_de_propensao_ao_aotoritarismo_eng=0, indice_de_propensao_ao_aotoritarismo_medicina=0, indice_de_propensao_ao_aotoritarismo_historia=0, indice_de_propensao_ao_aotoritarismo_letras=0, indice_de_propensao_ao_aotoritarismo_faixa_etaria1=0, indice_de_propensao_ao_aotoritarismo_faixa_etaria2=0, indice_de_propensao_ao_aotoritarismo_faixa_etaria3=0, indice_de_propensao_ao_aotoritarismo_total=0;
    /*variavel que pra checar se pesquisa acabou ou nao*/
    int pesquisa=1;
    /*inicio do questionario*/
    int questionario=1;
    int questao=1;/*contador de qual questao ele ta */
    //aqui eu vo declarar a variavel resposta como char pra nao dar o bug de digitar uma letra e ficar em loop infinito
    char resposta;
    /* aqui serao declarada as variaveis usadas no questionario ( ct() = concordo totalment, c() = concordo, cp() = concordo parcialmente, dp() = discordo parcialmente, d() = discordo, dt() = discordo completamente, no lugar do '()' estara o numero da questao*/
    int ct1=0,c1=0,cp1=0,dp1=0,d1=0,dt1=0,ct2=0,c2=0,cp2=0,dp2=0,d2=0,dt2=0,ct3=0,c3=0,cp3=0,dp3=0,d3=0,dt3=0,ct4=0,c4=0,cp4=0,dp4=0,d4=0,dt4=0,ct5=0,c5=0,cp5=0,dp5=0,d5=0,dt5=0,ct6=0,c6=0,cp6=0,dp6=0,d6=0,dt6=0,ct7=0,c7=0,cp7=0,dp7=0,d7=0,dt7=0,ct8=0,c8=0,cp8=0,dp8=0,d8=0,dt8=0,ct9=0,c9=0,cp9=0,dp9=0,d9=0,dt9=0,ct10=0,c10=0,cp10=0,dp10=0,d10=0,dt10=0,ct11=0,c11=0,cp11=0,dp11=0,d11=0,dt11=0,ct12=0,c12=0,cp12=0,dp12=0,d12=0,dt12=0,ct13=0,c13=0,cp13=0,dp13=0,d13=0,dt13=0,ct14=0,c14=0,cp14=0,dp14=0,d14=0,dt14=0,ct15=0,c15=0,cp15=0,dp15=0,d15=0,dt15=0,ct16=0,c16=0,cp16=0,dp16=0,d16=0,dt16=0,ct17=0,c17=0,cp17=0,dp17=0,d17=0,dt17=0,ct18,c18,cp18,dp18,d18,dt18,ct19,c19,cp19,dp19,d19,dt19,ct20,c20,cp20,dp20,d20,dt20=0;
    /*aqui sao as variaveis usadas para calcular os escores*/
    int rq1=0,rq2=0,rq3=0,rq4=0,rq5=0,rq6=0,rq7=0,rq8=0,rq9=0,rq10=0,rq11=0,rq12=0,rq13=0,rq14=0,rq15=0,rq16=0,rq17=0;
    do{/*goto rudimentar, ponto de inicio da pesquisa*/
            questao=1;
            do{ /*goto rudimentar para idade ( loop para menores de 18)*/
                rq1=rq2=rq3=rq4=rq5=rq6=rq7=rq8=rq9=rq10=rq11=rq12=rq13=rq14=rq15=rq16=rq17=0; // zerando variaveis que sao usadas no para calcular os escores ( porque ao inves de escrever por cima eu fiz somando entao pra nao mudar no codigo todo eu zero aqui )
                printf("digite sua idade\n");
                scanf("%d",&idade);
                if (idade<18){
                    printf("você não tem idade o suficiente para fazer o questionario!\n");
                    system("pause");
                    system("cls");}
                }while(idade<18);
            while (questao==1){
                printf("questao 01:\nO que este país necessita, principalmente, antes de leis ou planos políticos, \né de alguns líderes valentes, incansáveis e dedicados em quem o povo possa depositar a sua fé\n");
                printf("para: concordo totalmente digite '1'\npara concordo digite '2'\npara concordo parcialmente digite '3'\nparadiscordo parcialmente digite '4'\npara discord digite '5'\npara discordo totalmente digite 6\npara desistir precione '9'\n");
                fflush(stdin);
                scanf("%c",&resposta);
                getchar();
                switch (resposta){/* aqui a variavel que é usada para calcular o escore recebe um valor a depender da resposta dada*/
                case '1':
                rq1+=1;
                questao++;
                break;
                case '2':
                rq1+=2;
                questao++;
                break;
                case '3':
                rq1+=3;
                questao++;
                break;
                case '4':
                rq1+=4;
                questao++;
                break;
                case '5':
                rq1+=5;
                questao++;
                break;
                case '6':
                rq1+=6;
                questao++;
                break;
                case '9': /* aqui seta questão, que é a variavel de controle, para 21 que é a parte do codigo depois das atribuiçoes e perguntas, assim nao atrapalha o resultado*/
                questao=21;
                break;
                default:
                printf("voce não digitou uma opição valida tente novamente, aperte qualquer botao para continuar."); // isso sera executado se o pesquisado responder algo fora do esperad, nao mudando a variavel do while deixando em um loop
                system("pause");
                }
            }
            while ( questao==2){/*questao 2*/
                printf("questao 02:\nA obediência e o respeito à autoridade são as principais virtudes que devemos ensinar as nossas crianças\n");
                printf("para: concordo totalmente digite '1'\npara concordo digite '2'\npara concordo parcialmente digite '3'\nparadiscordo parcialmente digite '4'\npara discord digite '5'\npara discordo totalmente digite 6\npara desistir precione '9'\n");
                scanf("%c",&resposta);
                getchar();
                switch (resposta){
                case '1':
                rq2+=1;
                questao++;
                break;
                case '2':
                rq2+=2;
                questao++;
                break;
                case '3':
                rq2+=3;
                questao++;
                break;
                case '4':
                rq2+=4;
                questao++;
                break;
                case '5':
                rq2+=5;
                questao++;
                break;
                case '6':
                rq2+=6;
                questao++;
                break;
                case '9':
                questao=21;
                break;
                default:
                printf("voce não digitou uma opição valida tente novamente, aperte qualquer botão para continuar.");
                system("pause");
                }
        }
            while(questao==3){/*quetao 3*/
                printf("questao 03:\nNão há nada pior do que uma pessoa que não sente profundo amor, gratidão e respeito por seus pais\n");
                printf("para: concordo totalmente digite '1'\npara concordo digite '2'\npara concordo parcialmente digite '3'\nparadiscordo parcialmente digite '4'\npara discord digite '5'\npara discordo totalmente digite 6\npara desistir precione '9'\n");
                scanf("%c",&resposta);
                getchar();
                switch (resposta){
                case '1':
                rq3+=1;
                questao++;
                break;
                case '2':
                rq3+=2;
                questao++;
                break;
                case '3':
                rq3+=3;
                questao++;
                break;
                case '4':
                rq3+=4;
                questao++;
                break;
                case '5':
                rq3+=5;
                questao++;
                break;
                case '6':
                rq3+=6;
                questao++;
                break;
                case '9':
                questao=21;
                break;
                default:
                printf("voce nao digitou uma opiçao valida tente novamente, aperte qualquer botao para continuar.");
                system("pause");
                }
            }
            while(questao==4){/*questao 4*/
                printf("questao 04:\nNenhuma pessoa decente, normal e em seu são juízo pensaria em ofender um amigo ou parente próximo\n");
                printf("para: concordo totalmente digite '1'\npara concordo digite '2'\npara concordo parcialmente digite '3'\nparadiscordo parcialmente digite '4'\npara discord digite '5'\npara discordo totalmente digite 6\npara desistir precione '9'\n");
                scanf("%c",&resposta);
                getchar();
                switch (resposta){
                case '1':
                rq4+=1;
                questao++;
                break;
                case '2':
                rq4+=2;
                questao++;
                break;
                case '3':
                rq4+=3;
                questao++;
                break;
                case '4':
                rq4+=4;
                questao++;
                break;
                case '5':
                rq4+=5;
                questao++;
                break;
                case '6':
                rq4+=6;
                questao++;
                break;
                case '9':
                questao=21;
                break;
                default:
                printf("voce nao digitou uma opiçao valida tente novamente, aperte qualquer botao para continuar.");
                system("pause");
                }
            }
            while(questao==5){/*questao 5*/
                printf("questao 05:\nO policial é um guerreiro de Deus para impor a ordem e proteger as pessoas de bem\n");
                printf("para: concordo totalmente digite '1'\npara concordo digite '2'\npara concordo parcialmente digite '3'\nparadiscordo parcialmente digite '4'\npara discord digite '5'\npara discordo totalmente digite 6\npara desistir precione '9'\n");
                scanf("%c",&resposta);
                getchar();
                switch (resposta){
                case '1':
                rq5+=1;
                questao++;
                break;
                case '2':
                rq5+=2;
                questao++;
                break;
                case '3':
                rq5+=3;
                questao++;
                break;
                case '4':
                rq5+=4;
                questao++;
                break;
                case '5':
                rq5+=5;
                questao++;
                break;
                case '6':
                rq5+=6;
                questao++;
                break;
                case '9':
                questao=21;
                break;
                default:
                printf("voce nao digitou uma opiçao valida tente novamente, aperte qualquer botao para continuar.");
                system("pause");
                }
            }
            while(questao==6){/*questao 6*/
                printf("questao 06:\nA maioria de nossos problemas sociais estaria resolvida se pudéssemos nos livrar das pessoas\nimorais, dos marginais e dos pervertidos\n");
                printf("para: concordo totalmente digite '1'\npara concordo digite '2'\npara concordo parcialmente digite '3'\nparadiscordo parcialmente digite '4'\npara discord digite '5'\npara discordo totalmente digite 6\npara desistir precione '9'\n");
                scanf("%c",&resposta);
                getchar();
                switch (resposta){
                case '1':
                rq6+=1;
                questao++;
                break;
                case '2':
                rq6+=2;
                questao++;
                break;
                case '3':
                rq6+=3;
                questao++;
                break;
                case '4':
                rq6+=4;
                questao++;
                break;
                case '5':
                rq6+=5;
                questao++;
                break;
                case '6':
                rq6+=6;
                questao++;
                break;
                case '9':
                questao=21;
                break;
                default:
                printf("voce nao digitou uma opiçao valida tente novamente, aperte qualquer botao para continuar.");
                system("pause");
                }
            }
            while(questao==7){/*questao 7*/
                printf("Questao 07:\nSe falássemos menos e trabalhássemos mais, todos estaríamos melhor\n");
                printf("para: concordo totalmente digite '1'\npara concordo digite '2'\npara concordo parcialmente digite '3'\nparadiscordo parcialmente digite '4'\npara discord digite '5'\npara discordo totalmente digite 6\npara desistir precione '9'\n");
                scanf("%c",&resposta);
                getchar();
                switch (resposta){
                case '1':
                rq7+=1;
                questao++;
                break;
                case '2':
                rq7+=2;
                questao++;
                break;
                case '3':
                rq7+=3;
                questao++;
                break;
                case '4':
                rq7+=4;
                questao++;
                break;
                case '5':
                rq7+=5;
                questao++;
                break;
                case '6':
                rq7+=6;
                questao++;
                break;
                case '9':
                questao=21;
                break;
                default:
                printf("voce nao digitou uma opiçao valida tente novamente, aperte qualquer botao para continuar.");
                system("pause");
                }
            }
            while(questao==8){/*questao 8*/
                printf("Questao 08:\nDeve-se castigar sempre todo insulto à nossa honra\n");
                printf("para: concordo totalmente digite '1'\npara concordo digite '2'\npara concordo parcialmente digite '3'\nparadiscordo parcialmente digite '4'\npara discord digite '5'\npara discordo totalmente digite 6\npara desistir precione '9'\n");
                scanf("%c",&resposta);
                getchar();
                switch (resposta){
                case '1':
                rq8+=1;
                questao++;
                break;
                case '2':
                rq8+=2;
                questao++;
                break;
                case '3':
                rq8+=3;
                questao++;
                break;
                case '4':
                rq8+=4;
                questao++;
                break;
                case '5':
                rq8+=5;
                questao++;
                break;
                case '6':
                rq8+=6;
                questao++;
                break;
                case '9':
                questao=21;
                break;
                default:
                printf("voce nao digitou uma opiçao valida tente novamente, aperte qualquer botao para continuar.");
                system("pause");
                }
            }
            while(questao==9){/*questao 9*/
                 printf("Questao 09:\nOs crimes sexuais tais como o estupro ou ataques a crianças merecem mais que prisão;\nquem comete esses crimes deveria receber punição física publicamente ou receber um castigo pior\n");
                printf("para: concordo totalmente digite '1'\npara concordo digite '2'\npara concordo parcialmente digite '3'\nparadiscordo parcialmente digite '4'\npara discord digite '5'\npara discordo totalmente digite 6\npara desistir precione '9'\n");
                scanf("%c",&resposta);
                getchar();
                switch (resposta){
                case '1':
                rq9+=1;
                questao++;
                break;
                case '2':
                rq9+=2;
                questao++;
                break;
                case '3':
                rq9+=3;
                questao++;
                break;
                case '4':
                rq9+=4;
                questao++;
                break;
                case '5':
                rq9+=5;
                questao++;
                break;
                case '6':
                rq9+=6;
                questao++;
                break;
                case '9':
                questao=21;
                break;
                default:
                printf("voce nao digitou uma opiçao valida tente novamente, aperte qualquer botao para continuar.");
                system("pause");
                }
            }
            while(questao==10){/*questao 10*/
                printf("Questao 10:\nOs homossexuais são quase criminosos e deveriam receber um castigo severo.\n");
                printf("para: concordo totalmente digite '1'\npara concordo digite '2'\npara concordo parcialmente digite '3'\nparadiscordo parcialmente digite '4'\npara discord digite '5'\npara discordo totalmente digite 6\npara desistir precione '9'\n");
                scanf("%c",&resposta);
                getchar();
                switch (resposta){
                case '1':
                rq10+=1;
                questao++;
                break;
                case '2':
                rq10+=2;
                questao++;
                break;
                case '3':
                rq10+=3;
                questao++;
                break;
                case '4':
                rq10+=4;
                questao++;
                break;
                case '5':
                rq10+=5;
                questao++;
                break;
                case '6':
                rq10+=6;
                questao++;
                break;
                case '9':
                questao=21;
                break;
                default:
                printf("voce nao digitou uma opiçao valida tente novamente, aperte qualquer botao para continuar.");
                system("pause");
                }
            }
            while(questao==11){/*questao 11*/
                printf("Questao 11:\nÀs vezes, os jovens têm ideias rebeldes que, com os anos, deverão superar para acalmar os seus pensamentos\n");
                printf("para: concordo totalmente digite '1'\npara concordo digite '2'\npara concordo parcialmente digite '3'\nparadiscordo parcialmente digite '4'\npara discord digite '5'\npara discordo totalmente digite 6\npara desistir precione '9'\n");
                scanf("%c",&resposta);
                getchar();
                switch (resposta){
                case '1':
                rq11+=1;
                questao++;
                break;
                case '2':
                rq11+=2;
                questao++;
                break;
                case '3':
                rq11+=3;
                questao++;
                break;
                case '4':
                rq11+=4;
                questao++;
                break;
                case '5':
                rq11+=5;
                questao++;
                break;
                case '6':
                rq11+=6;
                questao++;
                break;
                case '9':
                questao=21;
                break;
                default:
                printf("voce nao digitou uma opiçao valida tente novamente, aperte qualquer botao para continuar.");
                system("pause");
                }
            }
            while(questao==12){/*questao 12*/
                printf("Questao 12:\nHoje em dia, as pessoas se intrometem cada vez mais em assuntos que deveriam ser somente pessoais e privados\n");
                printf("para: concordo totalmente digite '1'\npara concordo digite '2'\npara concordo parcialmente digite '3'\nparadiscordo parcialmente digite '4'\npara discord digite '5'\npara discordo totalmente digite 6\npara desistir precione '9'\n");
                scanf("%c",&resposta);
                getchar();
                switch (resposta){
                case '1':
                rq12+=1;
                questao++;
                break;
                case '2':
                rq12+=2;
                questao++;
                break;
                case '3':
                rq12+=3;
                questao++;
                break;
                case '4':
                rq12+=4;
                questao++;
                break;
                case '5':
                rq12+=5;
                questao++;
                break;
                case '6':
                rq12+=6;
                questao++;
                break;
                case '9':
                questao=21;
                break;
                default:
                printf("voce nao digitou uma opiçao valida tente novamente, aperte qualquer botao para continuar.");
                system("pause");
                }
            }
            while(questao==13){/*questao 13*/
                printf("Questao 13:\nA ciência tem o seu lugar, mas há muitas coisas importantes que a mente humana jamais poderá compreender\n");
                printf("para: concordo totalmente drq1,igite '1'\npara concordo digite '2'\npara concordo parcialmente digite '3'\nparadiscordo parcialmente digite '4'\npara discord digite '5'\npara discordo totalmente digite 6\npara desistir precione '9'\n");
                scanf("%c",&resposta);
                getchar();
                switch (resposta){
                case '1':
                rq13+=1;
                questao++;
                break;
                case '2':
                rq13+=2;
                questao++;
                break;
                case '3':
                rq13+=3;
                questao++;
                break;
                case '4':
                rq13+=4;
                questao++;
                break;
                case '5':
                rq13+=5;
                questao++;
                break;
                case '6':
                rq13+=6;
                questao++;
                break;
                case '9':
                questao=21;
                break;
                default:
                printf("voce nao digitou uma opiçao valida tente novamente, aperte qualquer botao para continuar.");
                system("pause");
                }
            }
            while(questao==14){/*questao 14*/
                 printf("Questao 14:\nOs homens podem ser divididos em duas classes definidas: os fracos e os fortes\n");
                printf("para: concordo totalmente digite '1'\npara concordo digite '2'\npara concordo parcialmente digite '3'\nparadiscordo parcialmente digite '4'\npara discord digite '5'\npara discordo totalmente digite 6\npara desistir precione '9'\n");
                scanf("%c",&resposta);
                getchar();
                switch (resposta){
                case '1':
                rq14+=1;
                questao++;
                break;
                case '2':
                rq14+=2;
                questao++;
                break;
                case '3':
                rq14+=3;
                questao++;
                break;
                case '4':
                rq14+=4;
                questao++;
                break;
                case '5':
                rq14+=5;
                questao++;
                break;
                case '6':
                rq14+=6;
                questao++;
                break;
                case '9':
                questao=21;
                break;
                default:
                printf("voce nao digitou uma opiçao valida tente novamente, aperte qualquer botao para continuar.");
                system("pause");
                }
            }
            while(questao==15){/*questao 15*/
                 printf("Questao 15:\nUm indivíduo de más maneiras, maus costumes e má educação dificilmente pode fazer amizade com pessoas decentes\n");
                printf("para: concordo totalmente digite '1'\npara concordo digite '2'\npara concordo parcialmente digite '3'\nparadiscordo parcialmente digite '4'\npara discord digite '5'\npara discordo totalmente digite 6\npara desistir precione '9'\n");
                scanf("%c",&resposta);
                getchar();
                switch (resposta){
                case '1':
                rq15+=1;
                questao++;
                break;
                case '2':
                rq15+=2;
                questao++;
                break;
                case '3':
                rq15+=3;
                questao++;
                break;
                case '4':
                rq15+=4;
                questao++;
                break;
                case '5':
                rq15+=5;
                questao++;
                break;
                case '6':
                rq15+=6;
                questao++;
                break;
                case '9':
                questao=21;
                break;
                default:
                printf("voce nao digitou uma opiçao valida tente novamente, aperte qualquer botao para continuar.");
                system("pause");
                }
            }
            while(questao==16){/*questao 16*/
                 printf("Questao 16:\nTodos devemos ter fé absoluta em um poder sobrenatural, cujas decisões devemos acatar\n");
                printf("para: concordo totalmente digite '1'\npara concordo digite '2'\npara concordo parcialmente digite '3'\nparadiscordo parcialmente digite '4'\npara discord digite '5'\npara discordo totalmente digite 6\npara desistir precione '9'\n");
                scanf("%c",&resposta);
                getchar();
                switch (resposta){
                case '1':
                rq16+=1;
                questao++;
                break;
                case '2':
                rq16+=2;
                questao++;
                break;
                case '3':
                rq16+=3;
                questao++;
                break;
                case '4':
                rq16+=4;
                questao++;
                break;
                case '5':
                rq16+=5;
                questao++;
                break;
                case '6':
                rq16+=6;
                questao++;
                break;
                case '9':
                questao=21;
                break;
                default:
                printf("voce nao digitou uma opiçao valida tente novamente, aperte qualquer botao para continuar.");
                system("pause");
                }
            }
            while(questao==17){/*questao 17*/
                printf("Questao 17:\nPobreza é consequência da falta de vontade de querer trabalhar\n");
                printf("para: concordo totalmente digite '1'\npara concordo digite '2'\npara concordo parcialmente digite '3'\nparadiscordo parcialmente digite '4'\npara discord digite '5'\npara discordo totalmente digite 6\npara desistir precione '9'\n");
                scanf("%c",&resposta);
                getchar();
                switch (resposta){
                case '1':
                rq17+=1;
                questao++;
                break;
                case '2':
                rq17+=2;
                questao++;
                break;
                case '3':
                rq17+=3;
                questao++;
                break;
                case '4':
                rq17+=4;
                questao++;
                break;
                case '5':
                rq17+=5;
                questao++;
                break;
                case '6':
                rq17+=6;
                questao++;
                break;
                case '9':
                questao=21;
                break;
                default:
                printf("voce nao digitou uma opiçao valida tente novamente, aperte qualquer botao para continuar.");
                system("pause");
                };
            }
            /*aqui é calculadoos escores do pesquisado que sera atribuido aos outros escores de categoria em outra parte do cogigo*/
                submissao_a_autoridade=(rq1+rq2+rq3+rq4+rq5)/5;
                agressividade_autoritaria=(rq6+rq7+rq8+rq9+rq10+rq11+rq12)/7;
                convencionalismo=(rq13+rq14+rq15+rq16+rq17)/5;
                /*preguiça de mudar em cada questoa entao eu vou enverter o valor aqui pra concordo totalmente ser 6 em vez de 1 e discordo totalmente 1 em vez de 6 como deve ser na escala de linkert*/
                submissao_a_autoridade=7-submissao_a_autoridade;
                agressividade_autoritaria=7-agressividade_autoritaria;
                convencionalismo=7-convencionalismo;
                /*calculando o escore final*/
                indice_de_propensao_ao_aotoritarismo=(((submissao_a_autoridade+agressividade_autoritaria+convencionalismo)/3)-1)*2;
                while(questao==18){/* aqui é checado as resposta dada em todas as quetões eentao é atribuido '+1' ao contador da resposta dada ( isso foi feito por causa da desistencia)*/
                if(rq1==1)
                    ct1++;
                if(rq1==2)
                    c1++;
                if(rq1==3)
                    cp1++;
                if(rq1==4)
                    dp1++;
                if(rq1==5)
                    d1++;
                if(rq1==6)
                    dt1++;
                if(rq2==1)
                    ct2++;
                if(rq2==2)
                    c2++;
                if(rq2==3)
                    cp2++;
                if(rq2==4)
                    dp2++;
                if(rq2==5)
                    d2++;
                if(rq2==6)
                    dt2++;
                if(rq3==1)
                    ct3++;
                if(rq3==2)
                    c3++;
                if(rq3==3)
                    cp3++;
                if(rq3==4)
                    dp3++;
                if(rq3==5)
                    d3++;
                if(rq3==6)
                    dt3++;
                if(rq4==1)
                    ct4++;
                if(rq4==2)
                    c4++;
                if(rq4==3)
                    cp4++;
                if(rq4==4)
                    dp4++;
                if(rq4==5)
                    d4++;
                if(rq4==6)
                    dt4++;
                if(rq5==1)
                    ct5++;
                if(rq5==2)
                    c5++;
                if(rq5==3)
                    cp5++;
                if(rq5==4)
                    dp5++;
                if(rq5==5)
                    d5++;
                if(rq5==6)
                    dt5++;
                if(rq6==1)
                    ct6++;
                if(rq6==2)
                    c6++;
                if(rq6==3)
                    cp6++;
                if(rq6==4)
                    dp6++;
                if(rq6==5)
                    d6++;
                if(rq6==6)
                    dt6++;
                if(rq7==1)
                    ct7++;
                if(rq7==2)
                    c7++;
                if(rq7==3)
                    cp7++;
                if(rq7==4)
                    dp7++;
                if(rq7==5)
                    d7++;
                if(rq7==6)
                    dt7++;
                if(rq8==1)
                    ct8++;
                if(rq8==2)
                    c8++;
                if(rq8==3)
                    cp8++;
                if(rq8==4)
                    dp8++;
                if(rq8==5)
                    d8++;
                if(rq8==6)
                    dt8++;
                if(rq9==1)
                    ct9++;
                if(rq9==2)
                    c9++;
                if(rq9==3)
                    cp9++;
                if(rq9==4)
                    dp9++;
                if(rq9==5)
                    d9++;
                if(rq9==6)
                    dt9++;
                if(rq10==1)
                    ct10++;
                if(rq10==2)
                    c10++;
                if(rq10==3)
                    cp10++;
                if(rq10==4)
                    dp10++;
                if(rq10==5)
                    d10++;
                if(rq10==6)
                    dt10++;
                if(rq11==1)
                    ct11++;
                if(rq11==2)
                    c11++;
                if(rq11==3)
                    cp11++;
                if(rq11==4)
                    dp11++;
                if(rq11==5)
                    d11++;
                if(rq11==6)
                    dt11++;
                if(rq12==1)
                    ct12++;
                if(rq12==2)
                    c12++;
                if(rq12==3)
                    cp12++;
                if(rq12==4)
                    dp12++;
                if(rq12==5)
                    d12++;
                if(rq12==6)
                    dt12++;
                if(rq13==1)
                    ct13++;
                if(rq13==2)
                    c13++;
                if(rq13==3)
                    cp13++;
                if(rq13==4)
                    dp13++;
                if(rq13==5)
                    d13++;
                if(rq13==6)
                    dt13++;
                if(rq14==1)
                    ct14++;
                if(rq14==2)
                    c14++;
                if(rq14==3)
                    cp14++;
                if(rq14==4)
                    dp14++;
                if(rq14==5)
                    d14++;
                if(rq14==6)
                    dt14++;
                if(rq15==1)
                    ct15++;
                if(rq15==2)
                    c15++;
                if(rq15==3)
                    cp15++;
                if(rq15==4)
                    dp15++;
                if(rq15==5)
                    d15++;
                if(rq15==6)
                    dt15++;
                if(rq16==1)
                    ct16++;
                if(rq16==2)
                    c16++;
                if(rq16==3)
                    cp16++;
                if(rq16==4)
                    dp16++;
                if(rq16==5)
                    d16++;
                if(rq16==6)
                    dt16++;
                if(rq17==1)
                    ct17++;
                if(rq17==2)
                    c17++;
                if(rq17==3)
                    cp17++;
                if(rq17==4)
                    dp17++;
                if(rq17==5)
                    d17++;
                if(rq17==6)
                    dt17++;
                questao++;
                }
                while(questao==19){// parte da pesquisa do genero e curso
                    confirmacao=1;/* garantir o loop abaixo ( a mas nao seria entao certo usar do while? sim por esta dentro do while  19 e so seria ativo se a pessoa estivesse aqui, mas nos meus testes por algum motivo colocando do()while{} ele rodava independente entao coloquei while, mas fica a duvida.*/
                    while(confirmacao==1){
                            printf ("por favor informe seu curso, precione:\n1 - Eng. Civil\n2 - Medicina.\n3 - Historia\n4 - Letras Vernaculas\n");
                            scanf("%d",&curso);
                            switch(curso){
                                case 1:
                                case 2:
                                case 3:
                                case 4:
                                    confirmacao=2;
                                    break;
                                default:
                                    printf("curso invalido! tente novamente.");
                                    confirmacao=1;
                            }
                    }
                    confirmacao=1; /* garantir o loop abaixo*/
                    while(confirmacao==1){
                        printf("informe seu sexo ( digite 1 para homem e 2 para mulher)\n");
                        scanf("%d",&sexo);
                        switch(sexo){
                            case 1:
                            case 2:
                                confirmacao=2;
                                break;
                            default:
                                printf("sexo inexistente! tente novamente.\n");
                                confirmacao=1;
                    }
                }
                questao++;
            }
            while (questao==20){//parte do codigo que soma os valores nos contadores dos escores, aqui tem acumuladores de scores( vai somando os esores dos pesquisados para depois tirar a media quando termina a pesquisa
                entrevistados_total++;
                if(sexo==1){
                homens_intrevistados++;
                convencionalismo_homen+=convencionalismo;
                submissao_a_autoridade_homem+=submissao_a_autoridade;
                agressividade_autoritaria_homem+=agressividade_autoritaria;
                indice_de_propensao_ao_aotoritarismo_homem+=indice_de_propensao_ao_aotoritarismo;
                }
                if (sexo==2){
                    mulheres_entrevistadas++;
                    convencionalismo_mulher+= convencionalismo;
                    submissao_a_autoridade_mulher+=submissao_a_autoridade;
                    agressividade_autoritaria_mulher+=agressividade_autoritaria;
                    indice_de_propensao_ao_aotoritarismo_mulher+=indice_de_propensao_ao_aotoritarismo;
                    }
                if(curso==1){
                    eng_entrevistados++;
                    submissao_a_autoridade_eng+=submissao_a_autoridade;
                    agressividade_autoritaria_eng+=agressividade_autoritaria;
                    convencionalismo_eng+= convencionalismo;
                    indice_de_propensao_ao_aotoritarismo_eng+= indice_de_propensao_ao_aotoritarismo;
                }
                if (curso==2){
                medicina_entrevistado++;
                submissao_a_autoridade_medicina+=submissao_a_autoridade;
                agressividade_autoritaria_medicina+=agressividade_autoritaria;
                convencionalismo_medicina+=convencionalismo;
                indice_de_propensao_ao_aotoritarismo_medicina+=indice_de_propensao_ao_aotoritarismo;
                }
                if (curso==3){
                historia_entrevistados++;
                submissao_a_autoridade_historia+=submissao_a_autoridade;
                agressividade_autoritaria_historia+=agressividade_autoritaria;
                convencionalismo_historia+=convencionalismo;
                indice_de_propensao_ao_aotoritarismo_historia+=indice_de_propensao_ao_aotoritarismo;
                }
                if(curso==4){
                letras_vernaculas_estrevistados++;
                submissao_a_autoridade_letras+=submissao_a_autoridade;
                agressividade_autoritaria_letras+=agressividade_autoritaria;
                convencionalismo_letras+=convencionalismo;
                indice_de_propensao_ao_aotoritarismo_letras+=indice_de_propensao_ao_aotoritarismo;
                }
                printf("seus resultados foram:\nSubmiçao à altoridade numa escala de 1 a 6:%.2f\nagrecividade autoritaria numa escala de 1 a 6:%.2f\nconvencionalismo numa escala de 1 a 6:%.2f\nIndice de propensao ao autoritarismo numa escala de 0 a 10:%.2f\n", submissao_a_autoridade, agressividade_autoritaria, convencionalismo, indice_de_propensao_ao_aotoritarismo);
                if(idade>17 && idade<=20){
                    faixa_etaria1_entrevistado++;
                    submissao_a_autoridade_faixa_etaria1=submissao_a_autoridade_faixa_etaria1+submissao_a_autoridade;
                    agressividade_autoritaria_faixa_etaria1+=agressividade_autoritaria;
                    convencionalismo_faixa_etaria1+=convencionalismo;
                    indice_de_propensao_ao_aotoritarismo_faixa_etaria1+=indice_de_propensao_ao_aotoritarismo;}
                else if(idade>20 && idade<=23){
                    faixa_etaria2_entrevistado++;
                    submissao_a_autoridade_faixa_etaria2+=submissao_a_autoridade;
                    agressividade_autoritaria_faixa_etaria2+=agressividade_autoritaria;
                    convencionalismo_faixa_etaria2+=convencionalismo;
                    indice_de_propensao_ao_aotoritarismo_faixa_etaria2+=indice_de_propensao_ao_aotoritarismo;}
                else if(idade>23){
                faixa_etaria3_entrevistado++;
                submissao_a_autoridade_faixa_etaria3+=submissao_a_autoridade;
                agressividade_autoritaria_faixa_etaria3+=agressividade_autoritaria;
                convencionalismo_faixa_etaria3+=convencionalismo;
                indice_de_propensao_ao_aotoritarismo_faixa_etaria3+=indice_de_propensao_ao_aotoritarismo;}
                system("pause");
                questao=1;
                questionario=0;/* seta questionario pra falso, nao ativo*/
            }
            while (questao==21){
                /*caso o pesquisado desista ele vem pra ca; se o pesquisado nao desistir a parte anterior do codigo pula esse pedaço;
                 nao é nescessario fazer nada pois as atribuiçoes ( contadores  e soma em escores) sao puladas */
                desistentes++;
                questao=1;
                printf("\nObrigado pelo seu tempo. Pedimos desculpas por qualquer constragimento ou coisa similar\n");
            }
    printf("Para terminar a pesquisa precione '9'\nPara fazer com outro usuario preicone qualquer outro botão\n");// check para saber se vao fazer a intrevista com outra pessoa ou deseja acabar a pesquisa
    fflush(stdin);
    scanf("%c", &resposta);
    system("cls");
    if (resposta=='9'){
        pesquisa=0;}
    }while (pesquisa==1);
    /*contas contas e mais contas pra mostra dados ( dividindo os acumuladores dos escores pela quantidade de entrevistados para obter a media )*/
    submissao_a_autoridade_eng= (submissao_a_autoridade_eng)/eng_entrevistados;
    convencionalismo_eng= (convencionalismo_eng)/eng_entrevistados;
    agressividade_autoritaria_eng=(agressividade_autoritaria_eng)/eng_entrevistados;
    indice_de_propensao_ao_aotoritarismo_eng=(indice_de_propensao_ao_aotoritarismo_eng)/eng_entrevistados;
    submissao_a_autoridade_faixa_etaria1=(submissao_a_autoridade_faixa_etaria1)/faixa_etaria1_entrevistado;
    agressividade_autoritaria_faixa_etaria1=(agressividade_autoritaria_faixa_etaria1)/faixa_etaria1_entrevistado;
    convencionalismo_faixa_etaria1=(convencionalismo_faixa_etaria1)/faixa_etaria1_entrevistado;
    indice_de_propensao_ao_aotoritarismo_faixa_etaria1=(indice_de_propensao_ao_aotoritarismo_faixa_etaria1)/faixa_etaria1_entrevistado;
    submissao_a_autoridade_faixa_etaria2=(submissao_a_autoridade_faixa_etaria2)/faixa_etaria2_entrevistado;
    agressividade_autoritaria_faixa_etaria2=(agressividade_autoritaria_faixa_etaria2)/faixa_etaria2_entrevistado;
    convencionalismo_faixa_etaria2=(convencionalismo_faixa_etaria2)/faixa_etaria2_entrevistado;
    indice_de_propensao_ao_aotoritarismo_faixa_etaria2=(indice_de_propensao_ao_aotoritarismo_faixa_etaria2)/faixa_etaria2_entrevistado;
    submissao_a_autoridade_faixa_etaria3=(submissao_a_autoridade_faixa_etaria3)/faixa_etaria3_entrevistado;
    agressividade_autoritaria_faixa_etaria3=(agressividade_autoritaria_faixa_etaria3)/faixa_etaria3_entrevistado;
    convencionalismo_faixa_etaria3=(convencionalismo_faixa_etaria3)/faixa_etaria3_entrevistado;
    indice_de_propensao_ao_aotoritarismo_faixa_etaria3=(indice_de_propensao_ao_aotoritarismo_faixa_etaria3)/faixa_etaria3_entrevistado;
    submissao_a_autoridade_medicina= (submissao_a_autoridade_medicina)/medicina_entrevistado;
    convencionalismo_medicina= (convencionalismo_medicina)/medicina_entrevistado;
    agressividade_autoritaria_medicina=(agressividade_autoritaria_medicina)/medicina_entrevistado;
    indice_de_propensao_ao_aotoritarismo_medicina=(indice_de_propensao_ao_aotoritarismo_medicina)/medicina_entrevistado;
    submissao_a_autoridade_historia= (submissao_a_autoridade_historia)/historia_entrevistados;
    convencionalismo_historia= (convencionalismo_historia)/historia_entrevistados;
    agressividade_autoritaria_historia=(agressividade_autoritaria_historia)/historia_entrevistados;
    indice_de_propensao_ao_aotoritarismo_historia=(indice_de_propensao_ao_aotoritarismo_historia)/historia_entrevistados;
    submissao_a_autoridade_letras= (submissao_a_autoridade_letras)/letras_vernaculas_estrevistados;
    convencionalismo_letras= (convencionalismo_letras)/letras_vernaculas_estrevistados;
    agressividade_autoritaria_letras=(agressividade_autoritaria_letras)/letras_vernaculas_estrevistados;
    indice_de_propensao_ao_aotoritarismo_letras=(indice_de_propensao_ao_aotoritarismo_letras)/letras_vernaculas_estrevistados;
    submissao_a_autoridade_homem= (submissao_a_autoridade_homem)/homens_intrevistados;
    convencionalismo_homen = (convencionalismo_homen)/homens_intrevistados;
    agressividade_autoritaria_homem=(agressividade_autoritaria_homem)/homens_intrevistados;
    indice_de_propensao_ao_aotoritarismo_homem=(indice_de_propensao_ao_aotoritarismo_homem)/homens_intrevistados;
    submissao_a_autoridade_mulher= (submissao_a_autoridade_mulher)/mulheres_entrevistadas;
    convencionalismo_mulher= (convencionalismo_mulher)/mulheres_entrevistadas;
    agressividade_autoritaria_mulher=(agressividade_autoritaria_mulher)/mulheres_entrevistadas;
    indice_de_propensao_ao_aotoritarismo_mulher=(indice_de_propensao_ao_aotoritarismo_mulher)/mulheres_entrevistadas;
    submissao_a_autoridade_total=(submissao_a_autoridade_mulher+submissao_a_autoridade_homem)/2;
    agressividade_autoritaria_total=(agressividade_autoritaria_homem+agressividade_autoritaria_mulher)/2;
    convencionalismo_total=(convencionalismo_homen+convencionalismo_mulher)/2;
    indice_de_propensao_ao_aotoritarismo_total=(indice_de_propensao_ao_aotoritarismo_homem+indice_de_propensao_ao_aotoritarismo_mulher)/2;
    /*variaveis pra mostra a porcentagem( escrita per(percento)+variavel que esta sendo calculada o porcento ex: perct1 é a porcentagem relativa de concordo totalmente da questao 1*/
    float perct1=0, perc1=0, percp1=0 , perdp1=0, perd1=0, perdt1=0, perct2=0, perc2=0, percp2=0, perdp2=0, perd2=0, perdt2=0, perct3=0, perc3=0, percp3=0, perdp3=0, perd3=0, perdt3=0, perct4=0, perc4=0, percp4=0, perdp4=0, perd4=0, perdt4=0, perct5=0, perc5=0, percp5=0, perdp5=0, perd5=0, perdt5=0, perct6=0, perc6=0, percp6=0, perdp6=0, perd6=0, perdt6=0, perct7=0, perc7=0, percp7=0, perdp7=0, perd7=0, perdt7=0, perct8=0, perc8=0, percp8=0, perdp8=0, perd8=0, perdt8=0, perct9=0, perc9=0, percp9=0, perdp9=0, perd9=0, perdt9=0, perct10=0, perc10=0, percp10=0, perdp10=0, perd10=0, perdt10=0, perct11=0, perc11=0, percp11=0, perdp11=0, perd11=0, perdt11=0, perct12=0, perc12=0, percp12=0, perdp12=0, perd12=0, perdt12=0, perct13=0, perc13=0, percp13=0, perdp13=0, perd13=0, perdt13=0, perct14=0, perc14=0, percp14=0, perdp14=0, perd14=0, perdt14=0, perct15=0, perc15=0, percp15=0, perdp15=0, perd15=0, perdt15=0, perct16=0, perc16=0, percp16=0, perdp16=0, perd16=0, perdt16=0, perct17=0, perc17=0, percp17=0, perdp17=0, perd17=0, perdt17=0;
    /* aqui acontece o calculo das porcentagens, mas o resultado esta em decimal entao apos isso é mutiplicado por 100 para virar porcentagem mesmo*/
    perct1=(float)ct1/(ct1+c1+cp1+dp1+d1+dt1); perc1=(float)c1/(ct1+c1+cp1+dp1+d1+dt1); percp1=(float)cp1/(ct1+c1+cp1+dp1+d1+dt1); perdp1=(float)dp1/(ct1+c1+cp1+dp1+d1+dt1); perd1=(float)d1/(ct1+c1+cp1+dp1+d1+dt1);perdt1=(float)dt1/(ct1+c1+cp1+dp1+d1+dt1);
    perct2=(float)ct2/(ct2+c2+cp2+dp2+d2+dt2); perc2=(float)c2/(ct2+c2+cp2+dp2+d2+dt2); percp2=(float)cp2/(ct2+c2+cp2+dp2+d2+dt2); perdp2=(float)dp2/(ct2+c2+cp2+dp2+d2+dt2); perd2=(float)d2/(ct2+c2+cp2+dp2+d2+dt2);perdt2=(float)dt2/(ct2+c2+cp2+dp2+d2+dt2);
    perct3=(float)ct3/(ct3+c3+cp3+dp3+d3+dt3); perc3=(float)c3/(ct3+c3+cp3+dp3+d3+dt3); percp3=(float)cp3/(ct3+c3+cp3+dp3+d3+dt3); perdp3=(float)dp3/(ct3+c3+cp3+dp3+d3+dt3); perd3=(float)d3/(ct3+c3+cp3+dp3+d3+dt3);perdt3=(float)dt3/(ct3+c3+cp3+dp3+d3+dt3);
    perct4=(float)ct4/(ct4+c4+cp4+dp4+d4+dt4); perc4=(float)c4/(ct4+c4+cp4+dp4+d4+dt4); percp4=(float)cp4/(ct4+c4+cp4+dp4+d4+dt4); perdp4=(float)dp4/(ct4+c4+cp4+dp4+d4+dt4); perd4=(float)d4/(ct4+c4+cp4+dp4+d4+dt4);perdt4=(float)dt4/(ct4+c4+cp4+dp4+d4+dt4);
    perct5=(float)ct5/(ct5+c5+cp5+dp5+d5+dt5); perc5=(float)c5/(ct5+c5+cp5+dp5+d5+dt5); percp5=(float)cp5/(ct5+c5+cp5+dp5+d5+dt5); perdp5=(float)dp5/(ct5+c5+cp5+dp5+d5+dt5); perd5=(float)d5/(ct5+c5+cp5+dp5+d5+dt5);perdt5=(float)dt5/(ct5+c5+cp5+dp5+d5+dt5);
    perct6=(float)ct6/(ct6+c6+cp6+dp6+d6+dt6); perc6=(float)c6/(ct6+c6+cp6+dp6+d6+dt6); percp6=(float)cp6/(ct6+c6+cp6+dp6+d6+dt6); perdp6=(float)dp6/(ct6+c6+cp6+dp6+d6+dt6); perd6=(float)d6/(ct6+c6+cp6+dp6+d6+dt6);perdt6=(float)dt6/(ct6+c6+cp6+dp6+d6+dt6);
    perct7=(float)ct7/(ct7+c7+cp7+dp7+d7+dt7); perc7=(float)c7/(ct7+c7+cp7+dp7+d7+dt7); percp7=(float)cp7/(ct7+c7+cp7+dp7+d7+dt7); perdp7=(float)dp7/(ct7+c7+cp7+dp7+d7+dt7); perd7=(float)d7/(ct7+c7+cp7+dp7+d7+dt7);perdt7=(float)dt7/(ct7+c7+cp7+dp7+d7+dt7);
    perct8=(float)ct8/(ct8+c8+cp8+dp8+d8+dt8); perc8=(float)c8/(ct8+c8+cp8+dp8+d8+dt8); percp8=(float)cp8/(ct8+c8+cp8+dp8+d8+dt8); perdp8=(float)dp8/(ct1+c8+cp8+dp8+d8+dt8); perd8=(float)d8/(ct8+c8+cp8+dp8+d8+dt8);perdt8=(float)dt8/(ct8+c8+cp8+dp8+d8+dt8);
    perct9=(float)ct9/(ct9+c9+cp9+dp9+d9+dt9); perc9=(float)c9/(ct9+c9+cp9+dp9+d9+dt9); percp9=(float)cp9/(ct9+c9+cp9+dp9+d9+dt9); perdp9=(float)dp9/(ct9+c9+cp9+dp9+d9+dt9); perd9=(float)d9/(ct9+c9+cp9+dp9+d9+dt9);perdt9=(float)dt9/(ct9+c9+cp9+dp9+d9+dt9);
    perct10=(float)ct10/(ct10+c10+cp10+dp10+d10+dt10); perc10=(float)c10/(ct10+c10+cp10+dp10+d10+dt10); percp10=(float)cp10/(ct10+c10+cp10+dp10+d10+dt10); perdp10=(float)dp10/(ct10+c10+cp10+dp10+d10+dt10); perd10=(float)d10/(ct10+c10+cp10+dp10+d10+dt10); perdt10=(float)dt10/(ct10+c10+cp10+dp10+d10+dt10);
    perct11=(float)ct11/(ct11+c11+cp11+dp11+d11+dt11); perc11=(float)c11/(ct11+c11+cp11+dp11+d11+dt11); percp11=(float)cp11/(ct11+c11+cp11+dp11+d11+dt11); perdp11=(float)dp11/(ct11+c11+cp11+dp11+d11+dt11); perd11=(float)d11/(ct11+c11+cp11+dp11+d11+dt11); perdt11=(float)dt11/(ct11+c11+cp11+dp11+d11+dt11);
    perct12=(float)ct12/(ct12+c12+cp12+dp12+d12+dt12); perc12=(float)c12/(ct12+c12+cp12+dp12+d12+dt12); percp12=(float)cp12/(ct12+c12+cp12+dp12+d12+dt12); perdp12=(float)dp12/(ct12+c12+cp12+dp12+d12+dt12); perd12=(float)d12/(ct12+c12+cp12+dp12+d12+dt12); perdt12=(float)dt12/(ct12+c12+cp12+dp12+d12+dt12);
    perct13=(float)ct13/(ct13+c13+cp13+dp13+d13+dt13); perc13=(float)c13/(ct13+c13+cp13+dp13+d13+dt13); percp13=(float)cp13/(ct13+c13+cp13+dp13+d13+dt13); perdp13=(float)dp13/(ct13+c13+cp13+dp13+d13+dt13); perd13=(float)d13/(ct13+c13+cp13+dp13+d13+dt13); perdt13=(float)dt13/(ct13+c13+cp13+dp13+d13+dt13);
    perct14=(float)ct14/(ct14+c14+cp14+dp14+d14+dt14); perc14=(float)c14/(ct14+c14+cp14+dp14+d14+dt14); percp14=(float)cp14/(ct14+c14+cp14+dp14+d14+dt14); perdp14=(float)dp14/(ct14+c14+cp14+dp14+d14+dt14); perd14=(float)d14/(ct14+c14+cp14+dp14+d14+dt14); perdt14=(float)dt14/(ct14+c14+cp14+dp14+d14+dt14);
    perct15=(float)ct15/(ct15+c15+cp15+dp15+d15+dt15); perc15=(float)c15/(ct15+c15+cp15+dp15+d15+dt15); percp15=(float)cp15/(ct15+c15+cp15+dp15+d15+dt15); perdp15=(float)dp15/(ct15+c15+cp15+dp15+d15+dt15); perd15=(float)d15/(ct15+c15+cp15+dp15+d15+dt15); perdt15=(float)dt15/(ct15+c15+cp15+dp15+d15+dt15);
    perct16=(float)ct16/(ct16+c16+cp16+dp16+d16+dt16); perc16=(float)c16/(ct16+c16+cp16+dp16+d16+dt16); percp16=(float)cp16/(ct16+c16+cp16+dp16+d16+dt16); perdp16=(float)dp16/(ct16+c16+cp16+dp16+d16+dt16); perd16=(float)d16/(ct16+c16+cp16+dp16+d16+dt16); perdt16=(float)dt16/(ct16+c16+cp16+dp16+d16+dt16);
    perct17=(float)ct17/(ct17+c17+cp17+dp17+d17+dt17); perc17=(float)c17/(ct17+c17+cp17+dp17+d17+dt17); percp17=(float)cp17/(ct17+c17+cp17+dp17+d17+dt17); perdp17=(float)dp17/(ct17+c17+cp17+dp17+d17+dt17); perd17=(float)d17/(ct17+c17+cp17+dp17+d17+dt17); perdt17=(float)dt17/(ct17+c17+cp17+dp17+d17+dt17);
    /* colocando em porcentagem */
    perct1*=100, perc1*=100, percp1*=100, perdp1*=100, perd1*=100, perdt1*=100, perct2*=100, perc2*=100, percp2*=100, perdp2*=100, perd2*=100, perdt2*=100, perct3*=100, perc3*=100, percp3*=100, perdp3*=100, perd3*=100, perdt3*=100, perct4*=100, perc4*=100, percp4*=100, perdp4*=100, perd4*=100, perdt4*=100, perct5*=100, perc5*=100, percp5*=100, perdp5*=100, perd5*=100, perdt5*=100, perct6*=100, perc6*=100, percp6*=100, perdp6*=100, perd6*=100, perdt6*=100, perct7*=100, perc7*=100, percp7*=100, perdp7*=100, perd7*=100, perdt7*=100, perct8*=100, perc8*=100, percp8*=100, perdp8*=100, perd8*=100, perdt8*=100, perct9*=100, perc9*=100, percp9*=100, perdp9*=100, perd9*=100, perdt9*=100, perct10*=100, perc10*=100, percp10*=100, perdp10*=100, perd10*=100, perdt10*=100, perct11*=100, perc11*=100, percp11*=100, perdp11*=100, perd11*=100, perdt11*=100, perct12*=100, perc12*=100, percp12*=100, perdp12*=100, perd12*=100, perdt12*=100, perct13*=100, perc13*=100, percp13*=100, perdp13*=100, perd13*=100, perdt13*=100, perct14*=100, perc14*=100, percp14*=100, perdp14*=100, perd14*=100, perdt14*=100, perct15*=100, perc15*=100, percp15*=100, perdp15*=100, perd15*=100, perdt15*=100, perct16*=100, perc16*=100, percp16*=100, perdp16*=100, perd16*=100, perdt16*=100, perct17*=100, perc17*=100, percp17*=100, perdp17*=100, perd17*=100, perdt17*=100;
    /*mostrando dados ( frequencia relativa e absoluta 1 questao por linha )*/
    printf("questao 1 : concordo totalmente: %d (%.2f%% ), concordo: %d (%.2f%% ), concordo parcioalmente: %d (%.2f%% ),\n discordo parcialmente: %d (%.2f%% ), discordo: %d (%.2f%% ), discordo totalmente: %d (%.2f%% )\n", ct1, perct1, c1, perc1, cp1, percp1, dp1, perdp1, d1, perd1, dt1, perdt1);
    printf("questao 2 : concordo totalmente: %d (%.2f%% ), concordo: %d (%.2f%% ), concordo parcioalmente: %d (%.2f%% ),\n discordo parcialmente: %d (%.2f%% ), discordo: %d (%.2f%% ), discordo totalmente: %d (%.2f%% )\n", ct2, perct2, c2, perc2, cp2, percp2, dp2, perdp2, d2, perd2, dt2, perdt2);
    printf("questao 3 : concordo totalmente: %d (%.2f%% ), concordo: %d (%.2f%% ), concordo parcioalmente: %d (%.2f%% ),\n discordo parcialmente: %d (%.2f%% ), discordo: %d (%.2f%% ), discordo totalmente: %d (%.2f%% )\n", ct3, perct3, c3, perc3, cp3, percp3, dp3, perdp3, d3, perd3, dt3, perdt3);
    printf("questao 4 : concordo totalmente: %d (%.2f%% ), concordo: %d (%.2f%% ), concordo parcioalmente: %d (%.2f%% ),\n discordo parcialmente: %d (%.2f%% ), discordo: %d (%.2f%% ), discordo totalmente: %d (%.2f%% )\n", ct4, perct4, c4, perc4, cp4, percp4, dp4, perdp4, d4, perd4, dt4, perdt4);
    printf("questao 5 : concordo totalmente: %d (%.2f%% ), concordo: %d (%.2f%% ), concordo parcioalmente: %d (%.2f%% ),\n discordo parcialmente: %d (%.2f%% ), discordo: %d (%.2f%% ), discordo totalmente: %d (%.2f%% )\n", ct5, perct5, c5, perc5, cp5, percp5, dp5, perdp5, d5, perd5, dt5, perdt5);
    printf("questao 6 : concordo totalmente: %d (%.2f%% ), concordo: %d (%.2f%% ), concordo parcioalmente: %d (%.2f%% ),\n discordo parcialmente: %d (%.2f%% ), discordo: %d (%.2f%% ), discordo totalmente: %d (%.2f%% )\n", ct6, perct6, c6, perc6, cp6, percp6, dp6, perdp6, d6, perd6, dt6, perdt6);
    printf("questao 7 : concordo totalmente: %d (%.2f%% ), concordo: %d (%.2f%% ), concordo parcioalmente: %d (%.2f%% ),\n discordo parcialmente: %d (%.2f%% ), discordo: %d (%.2f%% ), discordo totalmente: %d (%.2f%% )\n", ct7, perct7, c7, perc7, cp7, percp7, dp7, perdp7, d7, perd7, dt7, perdt7);
    printf("questao 8 : concordo totalmente: %d (%.2f%% ), concordo: %d (%.2f%% ), concordo parcioalmente: %d (%.2f%% ),\n discordo parcialmente: %d (%.2f%% ), discordo: %d (%.2f%% ), discordo totalmente: %d (%.2f%% )\n", ct8, perct8, c8, perc8, cp8, percp8, dp8, perdp8, d8, perd8, dt8, perdt8);
    printf("questao 9 : concordo totalmente: %d (%.2f%% ), concordo: %d (%.2f%% ), concordo parcioalmente: %d (%.2f%% ),\n discordo parcialmente: %d (%.2f%% ), discordo: %d (%.2f%% ), discordo totalmente: %d (%.2f%% )\n", ct9, perct9, c9, perc9, cp9, percp9, dp9, perdp9, d9, perd9, dt9, perdt9);
    printf("questao 10 : concordo totalmente: %d (%.2f%% ), concordo: %d (%.2f%% ), concordo parcioalmente: %d (%.2f%% ),\n discordo parcialmente: %d (%.2f%% ), discordo: %d (%.2f%% ), discordo totalmente: %d (%.2f%% )\n", ct10, perct10, c10, perc10, cp10, percp10, dp10, perdp10, d10, perd10, dt10, perdt10);
    printf("questao 11 : concordo totalmente: %d (%.2f%% ), concordo: %d (%.2f%% ), concordo parcioalmente: %d (%.2f%% ),\n discordo parcialmente: %d (%.2f%% ), discordo: %d (%.2f%% ), discordo totalmente: %d (%.2f%% )\n", ct11, perct11, c11, perc11, cp11, percp11, dp11, perdp11, d11, perd11, dt11, perdt11);
    printf("questao 12 : concordo totalmente: %d (%.2f%% ), concordo: %d (%.2f%% ), concordo parcioalmente: %d (%.2f%% ),\n discordo parcialmente: %d (%.2f%% ), discordo: %d (%.2f%% ), discordo totalmente: %d (%.2f%% )\n", ct12, perct12, c12, perc12, cp12, percp12, dp12, perdp12, d12, perd12, dt12, perdt12);
    printf("questao 13 : concordo totalmente: %d (%.2f%% ), concordo: %d (%.2f%% ), concordo parcioalmente: %d (%.2f%% ),\n discordo parcialmente: %d (%.2f%% ), discordo: %d (%.2f%% ), discordo totalmente: %d (%.2f%% )\n", ct13, perct13, c13, perc13, cp13, percp13, dp13, perdp13, d13, perd13, dt13, perdt13);
    printf("questao 14 : concordo totalmente: %d (%.2f%% ), concordo: %d (%.2f%% ), concordo parcioalmente: %d (%.2f%% ),\n discordo parcialmente: %d (%.2f%% ), discordo: %d (%.2f%% ), discordo totalmente: %d (%.2f%% )\n", ct14, perct14, c14, perc14, cp14, percp14, dp14, perdp14, d14, perd14, dt14, perdt14);
    printf("questao 15 : concordo totalmente: %d (%.2f%% ), concordo: %d (%.2f%% ), concordo parcioalmente: %d (%.2f%% ),\n discordo parcialmente: %d (%.2f%% ), discordo: %d (%.2f%% ), discordo totalmente: %d (%.2f%% )\n", ct15, perct15, c15, perc15, cp15, percp15, dp15, perdp15, d15, perd15, dt15, perdt15);
    printf("questao 16 : concordo totalmente: %d (%.2f%% ), concordo: %d (%.2f%% ), concordo parcioalmente: %d (%.2f%% ),\n discordo parcialmente: %d (%.2f%% ), discordo: %d (%.2f%% ), discordo totalmente: %d (%.2f%% )\n", ct16, perct16, c16, perc16, cp16, percp16, dp16, perdp16, d16, perd16, dt16, perdt16);
    printf("questao 17 : concordo totalmente: %d (%.2f%% ), concordo: %d (%.2f%% ), concordo parcioalmente: %d (%.2f%% ),\n discordo parcialmente: %d (%.2f%% ), discordo: %d (%.2f%% ), discordo totalmente: %d (%.2f%% )\n", ct17, perct17, c17, perc17, cp17, percp17, dp17, perdp17, d17, perd17, dt17, perdt17);
    /*tem varios prints pq eu botei cada curso em 1 so deu erro ai eu separei em varios deu o mesmo erro fiquei com preguiça de junta*/
    /* curso de engenharia civil*/
    printf("Curso Eng. Civil:\nSubmição a autoridade, de 1 a 6: %f\n", submissao_a_autoridade_eng);
    printf("Agressividade autoritária, de 1 a 6: %f\n", agressividade_autoritaria_eng);
    printf("Convencionalismo, de 1 a 6: %f\n", convencionalismo_eng);
    printf("Indice de propençao ao autoritarismo, de 0 a 10: %f\n", indice_de_propensao_ao_aotoritarismo_eng);
    printf("total de intrevistados: %d\n\n", eng_entrevistados);
    /* curso de medicina*/
    printf("Curso Medicina:\nSubmição a autoridade, de 1 a 6: %f\n", submissao_a_autoridade_medicina);
    printf("Agressividade autoritária, de 1 a 6: %f\n", agressividade_autoritaria_medicina);
    printf("Convencionalismo, de 1 a 6: %f\n",convencionalismo_medicina);
    printf("Indice de propençao ao autoritarismo, de 0 a 10: %f\n",indice_de_propensao_ao_aotoritarismo_medicina);
    printf("total de intrevistados: %d\n\n", medicina_entrevistado);
    /* curso de historia*/
    printf("Curso Historia:\nSubmição a autoridade, de 1 a 6: %f\n", submissao_a_autoridade_historia);
    printf("Agressividade autoritária, de 1 a 6: %f\n", agressividade_autoritaria_historia);
    printf("Convencionalismo, de 1 a 6: %f\n", convencionalismo_historia);
    printf("Indice de propençao ao autoritarismo, de 0 a 10: %f\n", indice_de_propensao_ao_aotoritarismo_historia);
    printf("total de intrevistados: %d\n\n", historia_entrevistados);
    /* curso de Letras Vernaculas*/
    printf("Curso Letras Vernaculas:\nSubmição a autoridade, de 1 a 6: %f\n", submissao_a_autoridade_letras);
    printf("Agressividade autoritária, de 1 a 6: %f\n", agressividade_autoritaria_letras);
    printf("Convencionalismo, de 1 a 6: %f\n", convencionalismo_letras);
    printf("Indice de propençao ao autoritarismo, de 0 a 10: %f\n", letras_vernaculas_estrevistados);
    printf("total de intrevistados: %d\n\n", letras_vernaculas_estrevistados);
    /* Homens */
    printf("Homens:\nSubmição a autoridade, de 1 a 6: %f\n", submissao_a_autoridade_homem);
    printf("Agressividade autoritária, de 1 a 6: %f\n", agressividade_autoritaria_homem);
    printf("Convencionalismo, de 1 a 6: %f\n", convencionalismo_homen);
    printf("Indice de propençao ao autoritarismo, de 0 a 10: %f\n",indice_de_propensao_ao_aotoritarismo_homem);
    printf("total de intrevistados: %d\n\n", homens_intrevistados);
    /* Mulheres*/
    printf("Mulheres:\nSubmição a autoridade, de 1 a 6: %f\n", submissao_a_autoridade_mulher);
    printf("Agressividade autoritária, de 1 a 6: %f\n", agressividade_autoritaria_mulher);
    printf("Convencionalismo, de 1 a 6: %f\n", convencionalismo_mulher);
    printf("Indice de propençao ao autoritarismo, de 0 a 10: %f\n", indice_de_propensao_ao_aotoritarismo_mulher);
    printf("total de intrevistados: %d\n\n", mulheres_entrevistadas);
    /* faixa etaria 1*/
    printf("Faixa etaria de idade entre 18 aos 20 anos:\nSubmição a autoridade, de 1 a 6: %f\n", submissao_a_autoridade_faixa_etaria1);
    printf("Agressividade autoritária, de 1 a 6: %f\n", agressividade_autoritaria_faixa_etaria1);
    printf("Convencionalismo, de 1 a 6: %f\n", convencionalismo_faixa_etaria1);
    printf("Indice de propençao ao autoritarismo, de 0 a 10: %f\n", indice_de_propensao_ao_aotoritarismo_faixa_etaria1);
    printf("total de intrevistados: %d\n\n", faixa_etaria1_entrevistado);
    /* faixa etaria 2*/
    printf("Faixa etaria de idade entre 21 aos 23 anos:\nSubmição a autoridade, de 1 a 6: %f\n", submissao_a_autoridade_faixa_etaria2);
    printf("Agressividade autoritária, de 1 a 6: %f\n", agressividade_autoritaria_faixa_etaria2);
    printf("Convencionalismo, de 1 a 6: %f\n", convencionalismo_faixa_etaria2);
    printf("Indice de propençao ao autoritarismo, de 0 a 10: %f\n", indice_de_propensao_ao_aotoritarismo_faixa_etaria2);
    printf("total de intrevistados: %d\n\n", faixa_etaria2_entrevistado);
    /* faixa etaria 3*/
    printf("Faixa etaria de idade acima de 23 anos:\nSubmiçao a autoridade, de 1 a 6: %f\n", submissao_a_autoridade_faixa_etaria3);
    printf("Agressividade autoritária, de 1 a 6: %f\n", agressividade_autoritaria_faixa_etaria3);
    printf("Convencionalismo, de 1 a 6: %f\n", convencionalismo_faixa_etaria3);
    printf("Indice de propençao ao autoritarismo, de 0 a 10: %f\n", indice_de_propensao_ao_aotoritarismo_faixa_etaria3);
   printf("total de intrevistados: %d\n\n", faixa_etaria3_entrevistado);
   /* Total*/
    printf("Todos os entrevistados:\nSubmição a autoridade, de 1 a 6: %f\n", submissao_a_autoridade_total);
    printf("Agressividade autoritária, de 1 a 6: %f\n", agressividade_autoritaria_total);
    printf("Convencionalismo, de 1 a 6: %f\n", convencionalismo_total);
    printf("Indice de propençao ao autoritarismo, de 0 a 10: %f\n", indice_de_propensao_ao_aotoritarismo_total);
    printf("total de intrevistados: %d\n\n", entrevistados_total);
    /* desistentes */
    printf(" Alem desses intrevistados houve %d de desistentes\n\n", desistentes);
    return 0;
    }
