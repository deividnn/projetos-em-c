#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main(){

    FILE *arq3;
    /**•“w“ cria arquivo vazio para escrita modo texto (se já existe, é apagado)*/
    arq3 = fopen("arq3.txt","w");
    int tamanho=50;
    char texto[tamanho];
    char texto2[tamanho];

      if(arq3!=NULL){
        printf("arquivo 3 aberto com sucesso\n");

        printf("escrevendo no arquivo com fputs\n");

        /**loop para escrever no arquivo ate que digite a palavra fim*/
        do{
            /**armazena o que foi digitado na variavel*/
            gets(texto);
            /**escreve no arquivo o valor da variavel e depois quebra linha*/
            fputs(texto,arq3);
            fputs("\n",arq3);

        /**enquanto valor da variavel for diferente de fim continue escrevendo no arquivo*/
        }while(strcmp(texto,"fim"));

        printf("escrevendo no arquivo com fprintf\n");

         /**loop para escrever no arquivo ate que digite a palavra fim*/
        do{
            /**armazena o que foi digitado na variavel*/
            gets(texto2);
            /**escreve no arquivo o valor da variavel e depois quebra linha*/
            fprintf(arq3,"%s",texto2);
            fprintf(arq3,"\n");

        /**enquanto valor da variavel for diferente de fim continue escrevendo no arquivo*/
        }while(strcmp(texto2,"fim"));

    }else{
        printf("erro na abertura o arquivo 3\n");
    }
    /**fecha o arquivo*/
    fclose(arq3);
}
