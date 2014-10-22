#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**estrutura que sera salvo no arquivo de indices
compoem da chave referente ao registro no arquivo de dados
e o rrn que é a quantidade de bytes deslocada pelo registro*/
typedef struct Chave{
    char chave[11];
    long rrn;
}Chave;

/**estrutura salva no arquivo de dados*/
typedef struct Pessoa{
    struct Chave codigo;
    char nome[50];
    int idade;
}Pessoa;

/**funcaoq que procura uma chave no indice  e retorna o registro que esta no arquivo de dados*/
void buscar_pessoa(char *chave,int qtd,FILE *indices,FILE *arquivo);

void main(){
    /**declaracxao dos arquivos de indices e de dados*/
    FILE *arquivo,*indices;

    /**abre os dois arquivos em modo de escrita e leitura */
    arquivo = fopen("pessoas2.dat","w+");
    indices = fopen("indices2.dat","w+");

    if(arquivo!=NULL && indices!=NULL){
        printf("arquivoS criado\n");

        int qtd = 3,i=0;
        /**chave da pessoa*/
        char chave[11],nome[50];
        /**vetor de pessoas que sera escrita no arquivo de dados*/
        Pessoa pessoas[qtd];

        while(i<qtd){

            printf("digite a chave da pessoa %d:",i+1);
            scanf("%s",chave);
            printf("digite o nome da pessoa %d:",i+1);
            scanf("%s",nome);
            strcpy(pessoas[i].codigo.chave,chave);
            strcpy(pessoas[i].nome,nome);
            pessoas[i].idade=i+1;
            /**deslocamento em bytes do ponteiro*/
            pessoas[i].codigo.rrn=ftell(arquivo);

            /**escreve o registro no arquivo de dados*/
            fprintf(arquivo,"%s\t%s\t%d\n",pessoas[i].codigo.chave,
                    pessoas[i].nome,
                    pessoas[i].idade);
            /**escreve a chave com o rrn no arquivo de indices*/

            fprintf(indices,"%s\t%ld\n",pessoas[i].codigo.chave,pessoas[i].codigo.rrn);

            printf("pessoa %d salva no arquivo na posicao %ld bytes\n",i+1,pessoas[i].codigo.rrn);

            i++;
        }
        char buscaChave[11];
        printf("digite a chave da pessoa que quer buscar no arquivo de dados:");
        scanf("%s",&buscaChave);
        /**busca uma chave e retorna a pessoa*/
        buscar_pessoa(buscaChave,qtd,indices,arquivo);

    }else{
        printf("erro ao criar arquivo\n");
    }
    /**fecha os arquivos*/
    fclose(arquivo);
    fclose(indices);
}


void buscar_pessoa(char *chave,int qtd,FILE *indices,FILE *arquivo){
    /**vetor de chaves que tem no arquivo de indices*/
    Chave chaves[qtd];
    /**registro que armazenara a pessoa*/
    Pessoa pessoa;
    int i=0,j=0,achou=0,k;

if (indices) {
        /**coloca os ponteiros dos arquivos no inicio para leitura*/
    rewind(indices);
    rewind(arquivo);
/**copia todos os dados do arquivo de indices para o vetor de chaves*/
        while (i<qtd) {
            fscanf(indices,"%s%ld",&chaves[i].chave,&chaves[i].rrn);
            printf("copiado para vetor de chaves %s e rrn %ld\n",chaves[i].chave,chaves[i].rrn);
            i++;
        }
        printf("procurando chave %s\n",chave);

        /**procura pela chave dentro do vetor de chaves*/
        while(j<qtd){

            if(strcmp(chaves[j].chave,chave)==0){
                achou=1;
                k=j;
            }
            j++;
        }

        /**se achou a chave posicione o ponteiro no rrn e pegue a pessoa no arquivo de dados*/
        if(achou==1){
            printf("chave encontrada na posicao %ld\n",chaves[k].rrn);
            /**a posicao inicial da pessoa */
                fseek(arquivo,chaves[k].rrn,SEEK_SET);
                fscanf(arquivo,"%s%s%d",
                       &pessoa.codigo.chave,
                       &pessoa.nome,
                       &pessoa.idade);

               printf("dados da pessoa\n chave = %s\n nome = %s\n idade = %d\n",
                       pessoa.codigo.chave,
                       pessoa.nome,
                       pessoa.idade);
        }
    }
}
