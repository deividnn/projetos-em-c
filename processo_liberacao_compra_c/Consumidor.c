#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Trabalho de ADE2
//autores : Deivid Nunes Nascimento e Rodrigo Alberto Ferreira

#define MAX 100//numero maximo de posicoes no vetor ordenado

int opcao;//opcao do menu do usuario
int contador = 0;//contador da posicao do vetor
int condicao_requisicao=0;//variavel que incrementa se o arquivo de requisicao foi carregado
int condicao_avaliacao=0;//variavel que incrementa se o arquivo de avaliacao foi carregado
char resultado[30];//string com o resultado da avaliacao

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

//estrutura de registro da avaliacao
typedef struct Avaliacao{
    int codigo;
    char resultado;
};

//estrutura  do nodo da avaliaco
typedef struct Nodo2{
    struct Avaliacao avaliacao;
    struct Nodo2* proximo;
};

//inicio e fim da fila de requisicoes
struct Nodo* pBegin = NULL;
struct Nodo* pEnd = NULL;
//inicio e fim da fila de avaliacoes
struct Nodo2* Begin = NULL;
struct Nodo2* End = NULL;

struct Nodo* vetor[MAX];//vetor de requisicoes

//metodo que enfileira uma avaliacao
void enqueue_avaliacao(struct Nodo2 *nodo){

    if(Begin==NULL){
        Begin=nodo;
    }else{
        End->proximo = nodo;
    }
    End=nodo;
    nodo->proximo=NULL;

}

//metodo que imprimi todas as avaliacoes enfileiradas
void imprimir_avaliacao(){
    if(Begin==NULL){

        printf("Nao ha avaliacoes\n");
        printf("Aperte uma tecla para continuar:");

        getch();
        limpa();

    }else{

    struct Nodo2* Atual = Begin;

    while(Atual!=NULL){

                    if(Atual->avaliacao.resultado=='A'){
                        strcpy(resultado,"Aceito");
                    }else{
                        strcpy(resultado,"Negado");
                    }

        printf("Codigo Operacao: %d\tResultado: %s\n",
               Atual->avaliacao.codigo,
               resultado);

               Atual = Atual->proximo;
        }
    }
}

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
void imprimir_requisicao(int codigo){
    if(pBegin==NULL){

        printf("Nao ha requisicoes\n");
        printf("Aperte uma tecla para continuar:");

        getch();
        limpa();

    }else{

    struct Nodo* pAtual = pBegin;
    struct Nodo2* aux= Begin;
    char resultado[30];

    while(pAtual!=NULL){
        if(codigo==pAtual->requisicao.codigo){
        printf("Codigo Requisicao: %d\nNumero do cartao: %d\nValor da compra: %.2f\n",
               pAtual->requisicao.codigo,
               pAtual->requisicao.cartao,
               pAtual->requisicao.valor);

            }
               pAtual = pAtual->pProximo;

        }

            while(aux!=NULL){
            if(codigo==aux->avaliacao.codigo){

            if(aux->avaliacao.resultado=='A'){
                strcpy(resultado,"Aceito");
            }else{
                strcpy(resultado,"Negado");
            }

            printf("Resultado: %s\n\n",
                   resultado);
            }

            aux = aux->proximo;
        }

    }
}


//metodo que imprimi todas as requisicoes com seus resultados
void imprimir_todas_requisicoes(){
    if(pBegin==NULL){

        printf("Nao ha requisicoes\n");
        printf("Aperte uma tecla para continuar:");

        getch();
        limpa();

    }else{

    struct Nodo* aux=malloc(sizeof(struct Nodo));

    int i;
        for(i=0;i<MAX-1;i++){
            if(vetor[i]!=NULL){

            aux = vetor[i];

            procura_resultado(aux->requisicao.codigo);

            printf("Codigo: %d\tCartao: %d\tValor: %.2f\tResultado: %s\n",
                   aux->requisicao.codigo,
                   aux->requisicao.cartao,
                   aux->requisicao.valor,
                   resultado);
            }
            aux=NULL;
            free(aux);
        }
        getch();

    }
}

//procura o resultado na fila de avaliacoes pelo codigo da requisicao
void procura_resultado(int codigo){

    struct Nodo2* aux= Begin;

    while(aux!=NULL){

                if(aux->avaliacao.codigo == codigo){

                    if(aux->avaliacao.resultado=='A'){
                        strcpy(resultado,"Aceito");
                    }else{
                        strcpy(resultado,"Negado");
                    }

                }
                aux = aux->proximo;
            }
            return resultado;
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

        printf("Codigo: %d\tNumero do cartao: %d\t Valor da compra: %.2f\n",
               pAtual->requisicao.codigo,
               pAtual->requisicao.cartao,
               pAtual->requisicao.valor);

               pAtual = pAtual->pProximo;
        }

    }
}

//metodo que carrega o arquivo de requisicoes
void carregar_requisicoes(){

    FILE *arq1;
    arq1 = fopen("requisicoes.txt","r");

    char separador;

    if(arq1==NULL){
        printf("Erro ao abrir o arquivo de requisicoes\n\n");
    }else{
        while(!feof(arq1)){

            struct Nodo *aux = malloc(sizeof(struct Nodo));

            fscanf(arq1,"%d\n",&aux->requisicao.codigo);
            fscanf(arq1,"%d\n",&aux->requisicao.cartao);
            fscanf(arq1,"%f\n",&aux->requisicao.valor);
            fscanf(arq1,"%c\n",&separador);

                if(condicao_requisicao==0){
                enqueue(aux);
                vetor[contador]=aux;//adiciona o nodo no vetor para ordenacao futura
                contador++;
                }
                aux=NULL;
                free(aux);

            }
        imprimir();
        condicao_requisicao++;
    }

    fclose(arq1);
    printf("\n\n");
    printf("Arquivo de requisicoes carregado com sucesso\n");
    printf("Aperte uma tecla para continuar:");

    getch();
    limpa();
}

//metodo que carrega o arquivo de avaliacoes
void carregar_avaliacao(){

    FILE *arq2;
    arq2 = fopen("avaliacoes.txt","r");

    char separador;

    if(arq2==NULL){
        printf("Erro ao abrir o arquivo de requisicoes\n\n");
    }else{
    while(!feof(arq2)){

        struct Nodo2 *aux = malloc(sizeof(struct Nodo2));

        fscanf(arq2,"%d\n",&aux->avaliacao.codigo);
        fscanf(arq2,"%c\n",&aux->avaliacao.resultado);
        fscanf(arq2,"%c\n",&separador);

            if(condicao_avaliacao==0){
            enqueue_avaliacao(aux);
            }
            aux=NULL;
            free(aux);
        }
        imprimir_avaliacao();
        condicao_avaliacao++;
    }

    fclose(arq2);
    printf("\n\n");
    printf("Arquivo de avaliacoes carregado com sucesso\n");
    printf("Aperte uma tecla para continuar:");

    getch();
    limpa();
}

//metodo para consultar requisicao por codigo
void resultado_requisicao(){

    if(condicao_avaliacao>0 && condicao_requisicao>0){
    int cod;
    printf("Digite o codigo da requisicao: ");
    scanf("%d",&cod);
    printf("\n");

    imprimir_requisicao(cod);

    }else{
        printf("Carregue os arquivos de requisicoes e avaliacoes primeiro\n");
    }
    printf("\n\n");
    printf("Arquivo de avaliacoes carregado com sucesso\n");
    printf("Aperte uma tecla para continuar:");

    getch();
    limpa();

}

//metodo que mostra todas as requisicoes ordenada por cartao de credito
void resultado_todas_requisicoes(){

    if(condicao_avaliacao>0 && condicao_requisicao>0){

    printf("\n");

    imprimir_todas_requisicoes();

    }else{
        printf("Carregue os arquivos de requisicoes e avaliacoes primeiro\n");
    }
    printf("\n\n");
    printf("Arquivo de avaliacoes carregado com sucesso\n");
    printf("Aperte uma tecla para continuar:");

    getch();
    limpa();

}

void ordena_por_selecao() {

    struct Nodo *aux = malloc(sizeof(struct Nodo));

    int i, j, min,cont;

        for (i = 0; i < (MAX - 1); i++) {
            min = i;
            if(vetor[i]!=NULL){
                for (j = (i + 1); j < MAX; j++) {
                    if(vetor[j]!=NULL){
                        if (vetor[j]->requisicao.cartao < vetor[min]->requisicao.cartao) {//compara os numeros de cartao de credito
                            min = j;
                        }
                    }
                }
            if (i != min) {//faz a troca
                aux = vetor[i];
                vetor[i] = vetor[min];
                vetor[min] = aux;
                free(aux);
            }
        }
    }

}

//metodo que limpa a tela
void limpa(){
    system("cls");
}

int main(){

    do{
        printf("Trabalho de AED II - Consumidor\n\n\n");
        printf("1 - Carregar arquivo de requisicoes\n");
        printf("2 - Carregar arquivo de avaliacoes\n");
        printf("3 - Apresentar resultado de uma requisicao\n");
        printf("4 - Apresentar resultados de todas as requisicoes\n");
        printf("0 - Sair\n\n");
        printf("Escolha uma opcao:");
        scanf("%d",&opcao);

        switch(opcao){
            case 1:{
                printf("\n\n");
                carregar_requisicoes();
                ordena_por_selecao();
            }break;

            case 2:{
                printf("\n\n");
                carregar_avaliacao();
            }break;

            case 3:{
                printf("\n\n");
                resultado_requisicao();
            }break;

            case 4:{
                printf("\n\n");
                printf("Lista de requisicoes ordenado por cartao de credito\n");
                resultado_todas_requisicoes();
            }

            default:{
                if(opcao>4){
                    printf("opcao invalida\n");
                    getch();
                }

                limpa();
            }
        }

    }while(opcao!=0);
}
