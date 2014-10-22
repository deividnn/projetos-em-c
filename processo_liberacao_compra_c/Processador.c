#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Trabalho de AED2
//autores : Deivid Nunes Nascimento e Rodrigo Alberto Ferreira

#define MAX 100//numero maximo de posicoes na tabelahash

int opcao;//opcao do menu
int cod=1;//codigo de operacao da avaliacao
int vetor[MAX];//vetor de posicoes da tabelahash que sao diferentes de null
int vetorPosicoes[MAX];//vetor de chaves geradas pelo hash
int condicao_requisicao=0;//condicao de avaliacao do arquivo de requisicao,nao deixa processa os dados mais de uma vez

//estrutura de requisicao
typedef struct Requisicao{
    int cartao;
    float saldo;
    float limite;
};

//nodo da requisicao
typedef struct Nodo{
    struct Requisicao requisicao;
    struct Nodo* proximo;
};

//estrutura de avaliacao
typedef struct Avaliacao{
    int codigo;
    char resultado;
};

//nodo da avaliacao
typedef struct NodoPilha{
    struct Avaliacao avaliacao;
    struct NodoPilha* proximo;
};

struct NodoPilha* pTopo = NULL;//topo da pilha

struct Nodo* hashTable[MAX];//tabelahash das requisicoes

void inicializa_hashTable(){//inicializa a tabelahash com null
    int i;

    for(i=0;i<MAX;i++){
        hashTable[i]=NULL;
    }
}

//carrega o arquivo de saldo e insere na tabelahash usando lista encadeada para tratamento de colisao
void carregar_saldo(){

    FILE  *arq;
    arq = fopen("saldos.txt","r");
    char separador;
    int posicao;

    if(arq==NULL){
        printf("Erro ao abrir arquivo de saldos\n\n");
    }else{
    inicializa_hashTable();

    while(!feof(arq)){

        struct Nodo *aux = malloc(sizeof(struct Nodo));

        //pega cada linha do arquivo e atribui a variavel da estrutura
        fscanf(arq,"%d\n",&aux->requisicao.cartao);
        fscanf(arq,"%f\n",&aux->requisicao.saldo);
        fscanf(arq,"%f\n",&aux->requisicao.limite);
        fscanf(arq,"%c\n",&separador);

        posicao = hash(aux);//calcula a posicao da tabelahash
        vetor[posicao]= aux->requisicao.cartao;//posicao valida do vetor
        vetorPosicoes[posicao] = posicao;//
        adicionar_hash(aux,posicao);//adiciona o nodo na tabelahash

        printf("posicao: %d\tcartao: %d\tsaldo: %.2f\tlimite: %.2f\n",
               posicao,
               hashTable[posicao]->requisicao.cartao,
               hashTable[posicao]->requisicao.saldo,
               hashTable[posicao]->requisicao.limite);

           aux->proximo = NULL;
           aux = NULL;
           free(aux);
            }
    }
    fclose(arq);
    printf("\n\n");
    printf("Arquivo de saldos carregado com sucesso\n");
    printf("Aperte uma tecla para continuar:");

    getch();
    limpa();
}

//metodo que gera a chave para a tabelahash
int hash(struct Nodo *cartao){
    int num = cartao->requisicao.cartao;
    char numc[10];
    int chave;

    itoa(num,numc,10);
    int tam=strlen(numc);
    int i;

    int soma=0;

    for(i=0;i<tam;i++){

        soma+=numc[i];
    }

    chave = soma%MAX;

    return chave;

}

//metodo que gera a chave que foi usada na tabelahash
int posicaoNoHash(int cartao){

       int i, chave;

       for(i=0;i<MAX-1;i++){
            if(vetor[i]==cartao){
                chave = vetorPosicoes[i];
            }
       }


       return chave;
}

//metodo que adiciona o nodo e sua chave na tabelahash
void adicionar_hash(struct Nodo *aux, int pos) {
    if (hashTable[pos] == NULL) {
        hashTable[pos] = aux;
    } else {

        struct Nodo *atual = hashTable[pos];
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = aux;
    }
}


//metodo que empilha a avaliacao
void empilha(struct NodoPilha *nodo){
    nodo->proximo = pTopo;
    pTopo = nodo;
}

//metodo que carrega o arquivo de avaliacoes
void carregar_requisicoes(){

    FILE *arq1;
    arq1 = fopen("requisicoes.txt","r");

    char separador;

    if(arq1==NULL){
        printf("Erro ao abrir o arquivo de requisicoes\n\n");
    }else{
        if(condicao_requisicao==0){
            while(!feof(arq1)){
                int cartao;
                int codigo,posicao;
                float valor;

                struct NodoPilha *aux2 = malloc(sizeof(struct NodoPilha));

                fscanf(arq1,"%d\n",&codigo);
                fscanf(arq1,"%d\n",&cartao);
                fscanf(arq1,"%f\n",&valor);
                fscanf(arq1,"%c\n",&separador);

                posicao=posicaoNoHash(cartao);//posicao da tabelahash que possui esse cartao

                if(hashTable[posicao]!=NULL){//a avaliacao apenas ocorre se a posicao na tabelahash for diferente de null

                    if(hashTable[posicao]->requisicao.cartao==cartao){
                        //se o valor da compra for menor ou igual ao saldo do cartao o resultado da avaliacao eh aceito
                        //e o saldo do cartao eh atualizado senao eh negado

                        if(valor<=hashTable[posicao]->requisicao.saldo){
                            printf("Requisicao numero: %d do cartao %d foi aceita\n",codigo,cartao);

                            aux2->avaliacao.resultado='A';
                            hashTable[posicao]->requisicao.saldo -=valor;


                        }else{
                            printf("Requisicao numero: %d do cartao %d foi negada\n",codigo,cartao);

                            aux2->avaliacao.resultado='N';
                        }

                        aux2->avaliacao.codigo=cod;//codigo da operacao
                        empilha(aux2);//empilha o nodo da avaliacao


                        free(aux2);//libera memoria alocada

                        cod++;
                    }
                }
                condicao_requisicao++;
            }

        }else{
            printf("Requisicoes ja avaliadas\n");
        }
    }
    fclose(arq1);
    printf("\n\n");
    printf("Arquivo de requisicoes carregado com sucesso\n");
    printf("Aperte uma tecla para continuar:");

    getch();
    limpa();
}

//apos a avaliacao e atualizacao dos saldos o arquivo saldos.txt eh salvo
void salvar_saldos(){

    if(cod>1){

    remove("saldos.txt")==0;

    FILE * arq2;
    char linha[16];

    arq2 = fopen("saldos.txt","a+");

    int i;

       for(i=0;i<MAX;i++){

            if(vetor[i]>0){

                struct Nodo *aux3=malloc(sizeof(struct Nodo));
                aux3 = hashTable[i];

                sprintf(linha,"%d",aux3->requisicao.cartao);
                fputs(linha,arq2);
                fputs("\n",arq2);
                sprintf(linha,"%.2f",aux3->requisicao.saldo);
                fputs(linha,arq2);
                fputs("\n",arq2);
                sprintf(linha,"%.2f",aux3->requisicao.limite);
                fputs(linha,arq2);
                fputs("\n#\n",arq2);

                free(aux3);//libera a memoria alocada
            }
       }
        fclose(arq2);
        printf("Arquivo de saldos atualizado com sucesso\n\n");
        printf("Aperte uma tecla para continuar:");

        getch();
        limpa();

    }else{
        printf("Avalie o arquivo de requisicoes primeiro\n\n");
        printf("Aperte uma tecla para continuar:");

        getch();
        limpa();
    }

 }

//apos a avalicao o arquivo avaliacoes.txt e  salvo
void salvar_avaliacoes(){
if(pTopo==NULL){

        printf("Nao ha avaliacoes para escrever\n\n");
        printf("Aperte uma tecla para continuar:");

        getch();
        limpa();

    }else{

    struct NodoPilha* pAtual = pTopo;
    remove("avaliacoes.txt")==0;//exclui o arquivo antes de escrever as requisicoes

    while(pAtual!=NULL){

   FILE * arq3;
   char linha [16];

   arq3 = fopen ("avaliacoes.txt","a+");

   sprintf(linha,"%d",pAtual->avaliacao.codigo);
   fputs (linha,arq3);
   fputs("\n",arq3);
   sprintf(linha,"%c",pAtual->avaliacao.resultado);
   fputs (linha,arq3);
   fputs("\n#\n",arq3);

   fclose (arq3);

               pAtual = pAtual->proximo;
        }
            printf("Avaliacoes salva no arquivo\n\n");
            printf("Aperte uma tecla para continuar:");

            getch();
            limpa();
        }
 }

//metodo que limpa a tela
void limpa(){
    system("cls");
}


int main(){


    do{

        printf("Trabalho de AED II - Processsador\n\n\n");
        printf("1 - Carregar o arquivo de saldos\n");
        printf("2 - Avaliar o arquivo de requisicoes\n");
        printf("3 - Salvar o arquivo de saldos\n");
        printf("4 - Salvar arquivo de avaliacoes\n");
        printf("0 - Sair\n\n");
        printf("Escolha uma opcao:");
        scanf("%d",&opcao);

        switch(opcao){
            case 1:{
                printf("\n\n");
                carregar_saldo();

            }break;

            case 2:{
                printf("\n\n");
                carregar_requisicoes();

            }break;

            case 3:{
                printf("\n\n");
                salvar_saldos();
            }break;

            case 4:{
                printf("\n\n");
                salvar_avaliacoes();
            }break;

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
