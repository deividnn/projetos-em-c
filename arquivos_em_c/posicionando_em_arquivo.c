#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct dados{
    char nome[55];
    float salario;
    int idade;
    char sexo;
}dados;

void main(){
    /**declara ponteiro para arquivo*/
    FILE *arq5;

    /**•“wb+“ Cria arquivo vazio para leitura e escrita modo binario*/
     arq5 = fopen("arq5.txt","wb+");

    /**verifica se ocorreu algum erro na abertura*/
    if(arq5!=NULL){
        printf("arquivo 5 aberto com sucesso\n");

        /**tamanho em bytes do registro*/
        int tamanho = sizeof(dados);
        int qtd = 50,i=0;
        /**vetor de pessoas inseridas no arquivo*/
        dados pessoas[qtd];
        /**registro que sera retornado apos a posicao setada
        */
        dados pessoaDoArquivo;

        while(i<qtd){
            /**preenche dados de 5 registros*/
            strcpy(pessoas[i].nome,"pessoa");
            pessoas[i].idade=i+1;
            float t = 723.22;
            pessoas[i].salario=t+(float)i+11;
            if(i%2==0){
                pessoas[i].sexo='M';
            }else{
                pessoas[i].sexo='F';
            }
            /**escreve no arquivo o registro*/
            fwrite(&pessoas[i],tamanho,1,arq5);
            printf("pessoa %d escrita no arquivo\n",i+1);
            i++;
        }
    /**escolhe qual posicao no arquivo sera lido*/
    printf("qual posicao entre 1 e %d voce quer ver?",qtd);
    int pos;
    scanf("%d",&pos);
    /**coloca o ponteiro na posicao escolhida

    int fseek (FILE *fp,long numbytes,int origem);

    SEEK_SET	0	In�cio do arquivo
    SEEK_CUR	1	Ponto corrente no arquivo
    SEEK_END	2	Fim do arquivo

    */
    fseek(arq5,(tamanho*pos)-tamanho,0);
    /**le um bloco de tamanho dados do arquivo e imprimi os valores*/
    fread(&pessoaDoArquivo,tamanho,1,arq5);
    printf("percorreu %d bytes ate o registro %d\n",tamanho*pos,pos);
    printf("pessoa na posicao %d =\n nome %s\n salario %.2f\n idade %d\n sexo %c\n\n",pos,
           pessoaDoArquivo.nome,
           pessoaDoArquivo.salario,
           pessoaDoArquivo.idade,
           pessoaDoArquivo.sexo);

    }else{
        printf("erro na abertura o arquivo 5\n");
    }
    /**fecha o arquivo*/
    fclose(arq5);


}
