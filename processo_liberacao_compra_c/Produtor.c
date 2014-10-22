#include <stdio.h>
#include <stdlib.h>

//Trabalho de AED2
//autores : Deivid Nunes Nascimento e Rodrigo Alberto Ferreira

int cod = 1;//codigo da requisicao
int opcao;//opcao do  menu

//estrutura de registro da requisicao de compra
typedef struct Requisicao{
    int codigo;
    int cartao;
    float valor;
};

//estrutura de registro do nodo de requisicoes
typedef struct Nodo{
    struct Requisicao requisicao;
    struct Nodo* pProximo;
};

//inicio e fim da fila de requisicoes
struct Nodo* pBegin = NULL;
struct Nodo* pEnd = NULL;

//metodo que enfileira uma requisicao
void enqueue(struct Nodo *pNodo){

    if(pBegin==NULL){
        pBegin=pNodo;
    }else{
        pEnd->pProximo = pNodo;
    }
    pEnd=pNodo;
    pNodo->pProximo=NULL;

}

//metodo que imprimi todas as requisicoes enfileiradas
void imprimir(){
    if(pBegin==NULL){

        printf("Nao ha requisicoes\n");
        printf("Aperte uma tecla para continuar:");

        getch();
        limpa();

    }else{

    struct Nodo* pAtual = pBegin;

    while(pAtual!=NULL){

        printf("Codigo:%d\tNumero do cartao:%d\tValor da compra:%.2f\n",
               pAtual->requisicao.codigo,
               pAtual->requisicao.cartao,
               pAtual->requisicao.valor);

               pAtual = pAtual->pProximo;
        }
        printf("Aperte uma tecla para continuar:");

        getch();
        limpa();
    }
}

//metodo que armazena todas as requisicoes da fila em um arquivo
void armazenar(){

if(pBegin==NULL){

        printf("Nao ha requisicoes para escrever\n\n");
        printf("Aperte uma tecla para continuar:");

        getch();
        limpa();

    }else{

    struct Nodo* pAtual = pBegin;
    remove("requisicoes.txt");//exclui o arquivo antes de escrever as requisicoes

        while(pAtual!=NULL){

       FILE * arquivo;
       char linha [16];

       arquivo = fopen ("requisicoes.txt","a+");

       sprintf(linha,"%d",pAtual->requisicao.codigo);
       fputs (linha,arquivo);
       fputs("\n",arquivo);
       sprintf(linha,"%d",pAtual->requisicao.cartao);
       fputs (linha,arquivo);
       fputs("\n",arquivo);
       sprintf(linha,"%.2f",pAtual->requisicao.valor);
       fputs (linha,arquivo);
       fputs("\n#\n",arquivo);

       fclose (arquivo);

                   pAtual = pAtual->pProximo;
            }
            printf("Requisicoes salva no arquivo\n\n");
            printf("Aperte uma tecla para continuar:");

            getch();
            limpa();
        }

     }

//metodo que limpa a tela
void limpa(){
    system("cls");
}

//metodo que inclui uma requisicao na fila
void incluir(){

   struct Nodo *v = malloc(sizeof(struct Nodo));

   v->requisicao.codigo=cod;
   v->pProximo=NULL;

   printf("Digite o numero do cartao(8 digitos):");
   scanf("%d",&v->requisicao.cartao);
   printf("Digite o valor da compra:");
   scanf("%f",&v->requisicao.valor);

   enqueue(v);
   free(v);//libera a memoria alocada
   cod++;//codigo da requisicao incrementa apos o enqueue

    printf("\n\nRequisicao incluida com sucesso!\n");
    printf("Aperte uma tecla para continuar:");

    getch();
    limpa();
}

int main(){


    do{
        printf("Trabalho de AED II - Produtor\n\n\n");
        printf("1 - Incluir requisicao\n");
        printf("2 - Armazenar requisicao\n");
        printf("0 - Sair\n\n");
        printf("Escolha uma opcao:");
        scanf("%d",&opcao);

        switch(opcao){
            case 1:{
                incluir();
            }break;

            case 2:{
                armazenar();
            }break;

            case 3 :{
                imprimir();
            }break;

            default:{
                if(opcao>3){
                    printf("opcao invalida\n");
                    getch();
                }

               limpa();
            }
        }

    }while(opcao!=0);

}
