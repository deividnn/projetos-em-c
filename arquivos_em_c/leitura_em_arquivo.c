#include <stdlib.h>
#include <stdio.h>

void main(){
    /**declara ponteiro para arquivo*/
    FILE *arq1;

/**
•“r“ apenas leitura modo texto; o arquivo precisa existir
*/
    arq1 = fopen("arq2.txt","r");
    int tamanho=50;
    /**variavel string com tamanho maximo de tamanho*/
    char texto[tamanho],texto2[tamanho];

    /**verifica se ocorreu algum erro na abertura*/
    if(arq1!=NULL){
        printf("arquivo 1 aberto com sucesso\n");
        /**le a primeira linha de um arquivo ate tamanho bytes e armazena na variavel texto*/
        fgets(texto,tamanho,arq1);
        printf("linha lida com fgtes = %s\n",texto);

        /**outra forma de ler uma linha de um arquivo
        onde se passa o arquivo,formato de saida e a variavel que ira armazenar o que foi lido
        veja que foi retornado a segunda linha pois foi onde o ponteiro do arquivo estava apos ter lido
        com fgets*/
        fscanf(arq1,"%s\n",texto2);
        printf("linha lida com fscanf = %s\n",texto2);

    }else{
        printf("erro na abertura o arquivo 1\n");
    }
    /**fecha o arquivo*/
    fclose(arq1);

}

