#include <stdlib.h>
#include <stdio.h>

void main(){
    /**declara ponteiro para arquivo*/
    FILE *arq4;
    float valor,valor3;
    int valor2,valor4;

    valor = 12.5;
    valor2 = 30;

    /**Cria arquivo vazio para leitura e escrita modo binario*/
     arq4 = fopen("arq4.txt","wb+");


      /**verifica se ocorreu algum erro na abertura*/
    if(arq4!=NULL){
        printf("arquivo 4 aberto com sucesso\n");

        /**escreve no arquivo um bloco de tamanho float no arquivo o valor da variavel valor*/
        fwrite(&valor,sizeof(float),1,arq4);
        /**escreve no arquivo um bloco de tamanho int no arquivo o valor da variavel valor2*/
        fwrite(&valor2,sizeof(int),1,arq4);

        /**coloca o ponteiro do arquivo no inicio*/
        rewind(arq4);

        /**le um bloco de tamanho float do arquivo para a variavel valor3 e imprimi esse valor*/
        fread(&valor3,sizeof(float),1,arq4);
        printf("%.2f\n",valor3);
        /**le um bloco de tamanho int do arquivo para a variavel valor4 e imprimi esse valor*/
        fread(&valor4,sizeof(int),1,arq4);
        printf("%d\n",valor4);



    }else{
        printf("erro na abertura o arquivo 4\n");
    }
    /**fecha o arquivo*/
    fclose(arq4);
}
