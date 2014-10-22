#include <stdlib.h>
#include <stdio.h>

void main(){
    /**declara ponteiro para arquivo*/
    FILE *arq1;

/**
•“r“ apenas leitura modo texto; o arquivo precisa existir
•“w“ cria arquivo vazio para escrita modo texto (se já existe, é apagado)
•“a“ adiciona (append) texto no final do arquivo (se arquivo não existe, cria)
•“r+“ Abre arquivo para leitura e escrita modo texto
•“w+“ Cria arquivo vazio para leitura e escrita modo texto
•“a+“ Abre arquivo para leitura e adição modo texto
•rb, wb, ab, rb+, wb+, ab+ : análogo para modo binário
  */
    arq1 = fopen("arq1.txt","w");

    /**verifica se ocorreu algum erro na abertura*/
    if(arq1!=NULL){
        printf("arquivo 1 aberto com sucesso\n");
    }else{
        printf("erro na abertura o arquivo 1\n");
    }
    /**fecha o arquivo*/
    fclose(arq1);

}
