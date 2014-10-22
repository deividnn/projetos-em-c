#include <iostream>//responsável pela manipulação de fluxo de dados padrão do sistema
#include <cstdlib>//para usar a função srand() e a função rand(),
#include <ctime>//funções para obter e manipular informações de data e hora.

using namespace std;//definir escopos para as estruturas std

long long comparacoes;//variavel global que armazena o numero de comparacoes

//protótipo das funcões
void preencher_vetor(int vetor[],int tamanho);//funcao que preenche o vetor
void mostrar_vetor(int vetor[],int tamanho);//funcao que mostra vetor ordenado
void bubble_sort(int vetor[], int tamanho);//funcao do metodo bubble_sort
void select_sort(int vetor[],int tamanho);//funcao do metodo select_sort
void insert_sort(int vetor[],int tamanho);//funcao do metodo insert-sort
void shell_sort(int vetor[],int tamanho);//funcao do metodo shell_sort
void heapsort(int vetor[],int tamanho);//funcao do metodo heapsort
void gnome_sort(int vetor[],int tamanho);//funcao do metodo gnome_sort
void bucket_sort(int v[], int n) ;//funcao do metodo bucket_sort
void merge_sort (int vetor[], int aux[],int esquerda, int direita);//funcao do metodo merge_sort
void intercalar_merge(int vetor[],int aux[],int esquerda, int meio,int direita);//funcao de intercalar do merge_sort
void quick_sort(int vetor[],int primeiro,int ultimo);//funcao do metodo quick_sort

int main(){

    srand(10);//semente de numeros aleatórios constante

    //declaração de variáveis
    int opcao;
    int tamanho;

    cout<<"GCC101 - Algoritmos e Estruturas de Dados 1\n";
    cout<<"Trabalho 1 - Algoritmos de Ordenacao\n\n";

    do{
        //menu de opções do usuário
        cout<<"1 - Ordenar vetor com (Bolha)  Bubble_Sort\n";
        cout<<"2 - Ordenar vetor com (Selecao)  Select_Sort\n";
        cout<<"3 - Ordenar vetor com (Insercao)  Insert_Sort\n";
        cout<<"4 - Ordenar vetor com (Concha) Shell_Sort\n";
        cout<<"5 - Ordenar vetor com (Pilha)  HeapSort\n";
        cout<<"6 - Ordenar vetor com (Gnomo)  Gnome_Sort\n";
        cout<<"7 - Ordenar vetor com (Balde)  Bucket_Sort\n";
        cout<<"8 - Ordenar vetor com (Uniao)  Merge_Sort\n";
        cout<<"9 - Ordenar vetor com (Ordenacao Rapida)  Quick_Sort\n";
        cout<<"10 - Sair\n\n";
        cout<<"Digite uma opcao: ";
        cin>>opcao;

        switch(opcao){
            case 1:{//opcao do bubble_sort
                comparacoes=0;
                tamanho=0;
                cout<<"Qual o tamanho do vetor?";
                cin>>tamanho;

                int vetor[tamanho];

                 preencher_vetor(vetor,tamanho);//funcao para preencher o vetor
                 bubble_sort(vetor,tamanho);//metodo bubble_sort
                 mostrar_vetor(vetor,tamanho);//mostra o vetor ordenado usando bubble_sort

                 cout<<endl<<"O vetor de tamanho "<<tamanho<<" teve "<<comparacoes<<" comparacoes usando o metodo bubble_sort\n\n";

            }break;

            case 2:{//opcao do select_sort
                comparacoes=0;
                tamanho=0;
                cout<<"Qual o tamanho do vetor?";
                cin>>tamanho;

                int vetor[tamanho];

                 preencher_vetor(vetor,tamanho);//funcao para preencher o vetor
                 select_sort(vetor,tamanho);//metodo select_sort
                 mostrar_vetor(vetor,tamanho);//mostra o vetor ordenado usando select_sort

                 cout<<endl<<"O vetor de tamanho "<<tamanho<<" teve "<<comparacoes<<" comparacoes usando o metodo select_sort\n\n";

            }break;

            case 3:{//opcao do insert_sort
                comparacoes=0;
                tamanho=0;
                cout<<"Qual o tamanho do vetor?";
                cin>>tamanho;

                int vetor[tamanho];

                 preencher_vetor(vetor,tamanho);//funcao para preencher o vetor
                 insert_sort(vetor,tamanho);//metodo insert_sort
                 mostrar_vetor(vetor,tamanho);//mostra o vetor ordenado usando insert_sort

                 cout<<endl<<"O vetor de tamanho "<<tamanho<<" teve "<<comparacoes<<" comparacoes usando o metodo insert_sort\n\n";

            }break;

             case 4:{//opcao do shell_sort
                comparacoes=0;
                tamanho=0;
                cout<<"Qual o tamanho do vetor?";
                cin>>tamanho;

                int vetor[tamanho];

                 preencher_vetor(vetor,tamanho);//funcao para preencher o vetor
                 shell_sort(vetor,tamanho);//metodo shell_sort
                 mostrar_vetor(vetor,tamanho);//mostra o vetor ordenado usando shell_sort

                 cout<<endl<<"O vetor de tamanho "<<tamanho<<" teve "<<comparacoes<<" comparacoes usando o metodo shell_sort\n\n";

            }break;

            case 5:{//opcao do heapsort
                comparacoes=0;
                tamanho=0;
                cout<<"Qual o tamanho do vetor?";
                cin>>tamanho;

                int vetor[tamanho];

                 preencher_vetor(vetor,tamanho);//funcao para preencher o vetor
                 heapsort(vetor,tamanho);//metodo heapsort
                 mostrar_vetor(vetor,tamanho);//mostra o vetor ordenado usando heapsort

                 cout<<endl<<"O vetor de tamanho "<<tamanho<<" teve "<<comparacoes<<" comparacoes usando o metodo heapsort\n\n";

            }break;

            case 6:{//opcao do gnomesort
                comparacoes=0;
                tamanho=0;
                cout<<"Qual o tamanho do vetor?";
                cin>>tamanho;

                int vetor[tamanho];

                 preencher_vetor(vetor,tamanho);//funcao para preencher o vetor
                 gnome_sort(vetor,tamanho);//metodo gnome_sort
                 mostrar_vetor(vetor,tamanho);//mostra o vetor ordenado usando gnome_sort

                 cout<<endl<<"O vetor de tamanho "<<tamanho<<" teve "<<comparacoes<<" comparacoes usando o metodo gnome_sort\n\n";

            }break;

            case 7:{//opcao do bucket_sort
                comparacoes=0;
                tamanho=0;
                cout<<"Qual o tamanho do vetor?";
                cin>>tamanho;

                int vetor[tamanho];

                 preencher_vetor(vetor,tamanho);//funcao para preencher o vetor
                 bucket_sort(vetor,tamanho);//metodo bucket_sort
                 mostrar_vetor(vetor,tamanho);//mostra o vetor ordenado usando bucket_sort

                 cout<<endl<<"O vetor de tamanho "<<tamanho<<" teve "<<comparacoes<<" comparacoes usando o metodo bucket_sort\n\n";

            }break;

            case 8:{//opcao do merge_sort
                comparacoes=0;
                tamanho=0;
                cout<<"Qual o tamanho do vetor?";
                cin>>tamanho;

                int vetor[tamanho];
                int aux[tamanho];

                 preencher_vetor(vetor,tamanho);//funcao para preencher o vetor
                 merge_sort(vetor,aux,0,tamanho-1);//metodo merge_sort
                 mostrar_vetor(vetor,tamanho);//mostra o vetor ordenado usando merge_sort

                 cout<<endl<<"O vetor de tamanho "<<tamanho<<" teve "<<comparacoes<<" comparacoes usando o metodo merge_sort\n\n";

            }break;

            case 9:{//opcao do quick_sort
                comparacoes=0;
                tamanho=0;
                cout<<"Qual o tamanho do vetor?";
                cin>>tamanho;

                int vetor[tamanho];

                 preencher_vetor(vetor,tamanho);//funcao para preencher o vetor
                 quick_sort(vetor,0,tamanho-1);//metodo quick_sort
                 mostrar_vetor(vetor,tamanho);//mostra o vetor ordenado usando quick_sort

                 cout<<endl<<"O vetor de tamanho "<<tamanho<<" teve "<<comparacoes<<" comparacoes usando o metodo quick_sort\n\n";

            }break;

        }//fim do menu usuario

        if(opcao>10)cout<<"opcao invalida!\a\n\n";//opcao invalida caso seja digitado numero maior que 10(alerta sonoro)

    }while(opcao!=10);//condicao do do{}while

}

//******************funcoes dos metodos de ordenacao*************************************
//***************************************************************************************

//funcao que preenche o vetor com numeros aleatorios
void preencher_vetor(int vetor[],int tamanho){

    //preenchendo o vetor
    cout<<"\n";
    cout<<"vetor preenchido com "<<tamanho<<" valores"<<endl;

    for(int i=0;i<tamanho;i++){
        vetor[i]=rand()%tamanho;//retorna um numero aleatorio //de 0 ate tamanho

		cout<<vetor[i]<<"\t";
    }
    cout<<"\n\n";
}

//mostra vetor ordenado
void mostrar_vetor(int vetor[],int tamanho){

    cout<<"vetor ordenado\n";
        for(int i=0;i<tamanho;i++){

        cout<<vetor[i]<<"\t";
    }
}

//metodo de ordenacao bubble_sort
void bubble_sort(int vetor[], int tamanho){
    int troca,aux;//variaves do metodo bubble_sort

      do{//usa o do{}while para percorrer o vetor enquanto houver troca
            troca=0;

            for(int i=0;i<tamanho-1;i++){//percorre o vetor ate a penultima posicao

                if(vetor[i]>vetor[i+1]){
                //compara a posicao i com a i+1,se i for maior que i+1 os valores sao trocados
                aux=vetor[i];
                vetor[i]=vetor[i+1];
                vetor[i+1]=aux;

                troca++;//troca recebe mais 1

                }

                comparacoes++;//comparacoes recebe mais 1
            }

        }while(troca>0);//enquanto troca for maior que zero loop do{}while continua
}

//metodo de ordenação select_sort
void select_sort(int vetor[],int tamanho){

    int maior_pos,aux;//variaveis do select_sort

    for(int i=0;i<tamanho-1;i++){//percorre o vetor ate a penultima posicao

        maior_pos=i;//atribui o valor da posicao i ao maior posicao

        for(int j=i+1;j<tamanho;j++){//percorre o vetor da posicao i+1 ate o tamanho do vetor

            if(vetor[j]<vetor[maior_pos]){
            //se o valor da posicao j for menor que o valor da posicao maior_pos,maior_pos sera o j
                maior_pos=j;
            }
            comparacoes++;//comparacoes recebe mais 1

        }
        //tribui o valor da posicao maior_pos para posicao i
        aux=vetor[i];
        vetor[i]=vetor[maior_pos];
        vetor[maior_pos]=aux;
    }
}

//metodo de ordenacao insert_sort
void insert_sort(int vetor[],int tamanho){
    //variaveis do insert_sort
    int aux;
    bool ordenado;

    for(int i=1;i<tamanho;i++){//percorre todo o vetor

        ordenado=false;//atriui false a variavel ordenado

        for(int j=i-1;(j>=0)&&(!ordenado);j--){//percorre vetor da posicao i-1 ate ordenado seja true e j seja  maior e igual a zero

            if(vetor[j+1]>=vetor[j]){
            //se valor da posicao j+1 for maior ou igual a valor da posicao j ordenado recebe false
            //senao posicao j recebe valor de j+1

               ordenado=true;

            }else{//troca de valores
            aux=vetor[j];
            vetor[j]=vetor[j+1];
            vetor[j+1]=aux;
            }
            comparacoes++;//comparacoes recebe mais 1
        }
    }

}

//metodo de orndecao shell-sort
void shell_sort(int vetor[],int tamanho){
    //variaveis do shell_sort
    int valor,j;

    int intervalo = 1;

    do {//pega o tamanho do intervalo para fazer vetores menores
        intervalo = 3*intervalo+1;//sequencia de Knuth para ordenacao crescente
    } while(intervalo < tamanho);

    do {
        intervalo =intervalo / 3;
        //ordena vetor do primeiro intervalo ex: intervalo=3
        for(int i = intervalo; i<tamanho; i++){//percorre vetor da posicao intervalo a ate tamanho do vetor
                valor=vetor[i];
                j = i - intervalo;
                //usa o metodo de  insert_sort para ordena o vetor de tamanho intervalo
                while (j >= 0 && valor < vetor[j]) {
                    vetor [j + intervalo] =vetor[j];
                    j = j - intervalo;
                    comparacoes++;
                    }
                vetor [j + intervalo] = valor;
                }
        } while ( intervalo > 1);//faz isso ate que intervalo seja 1
}

//metodo de ordenacao heapsort
void heapsort(int vetor[],int tamanho){
    //variaveis do heapsort
    int valor, filha, pai ;

    for (int i = 1 ; i < tamanho ; i++ ){//constroi o heap
            valor = vetor[i] ;
            filha = i ;
            pai = ( filha - 1 ) / 2 ;

            while ( filha > 0 && vetor[pai] < valor ){
                    vetor[filha] = vetor[pai] ;
                    filha = pai ;
                    pai = ( filha - 1 ) / 2 ;// pega o ultimo nó que possui um filho
                    comparacoes++;
                }
                vetor[filha] = valor ;
    }

    int filha2, pai2,valor2 ;
    for (int i = tamanho- 1 ; i > 0 ; i-- ){// pega a ultima filha que é pai
            valor2 = vetor[i] ;
            vetor[i] = vetor[0] ;
            pai2 = 0 ;

            if ( i == 1 ){
                    filha2 = -1 ;
                }else{
                    filha2 = 1 ;
                }

            if ( i > 2 && vetor[2] > vetor[1] ){
                    filha2 = 2 ;
            }

            while ( filha2 >= 0 && valor2 < vetor[filha2] ){
                    vetor[pai2] = vetor[filha2] ;
                    pai2 = filha2 ;
                    filha2 = 2 * pai2 + 1 ;

                    if ( filha2 + 1 <= i - 1 && vetor[filha2] < vetor[filha2 + 1] ){
                       filha2++ ;
                    }

                    if ( filha2 > i - 1 ){
                       filha2 = -1 ;
                    }

                        comparacoes++;
                }
                vetor[pai2] = valor2 ;
            }
}

//metodo de ordenacao gnome_sort
void gnome_sort(int vetor[],int tamanho){
    int i=0, aux;

    while( i < tamanho ){

        if ( i == 0 || vetor [i - 1] <= vetor[i] ){

                i++;

            }else{

                aux = vetor[i];
                vetor[i] = vetor[i - 1];
                vetor[--i] = aux;
            }
            comparacoes++;
    }
}

//metodo de ordenacao bucket_sort
void bucket_sort(int vetor[], int tamanho) {
  int i, j;
  int balde[tamanho];

  for(i=0; i < tamanho; i++) {
        balde[i] = 0;
  }

  for(i=0; i < tamanho; i++) {
        (balde[vetor[i]])++;
  }

  for (int i=0, j=0; j < tamanho; ++j){
        for (int k=balde[j]; k > 0; --k){
            vetor[i++]=j;
            comparacoes++;
        }
    }
}

//metodo de ordenacao merge_sort
void merge_sort (int vetor[], int aux[],int esquerda, int direita){

     int meio,i;

     if(esquerda<direita){
          meio=(esquerda+direita)/2;
          merge_sort(vetor,aux,esquerda,meio);
          merge_sort(vetor,aux,meio+1,direita);
          intercalar_merge(vetor,aux,esquerda,meio+1,direita);
     }
}

//funcao de intercalar do merge_sort
void intercalar_merge(int vetor[],int aux[],int esquerda, int meio,int direita){

     int esquerda1=esquerda,
         meio1=meio,
         meio2=meio1-1,
         au=0,i,j;

     while(esquerda1<=meio2 && meio<=direita){

          if (vetor[esquerda1]<vetor[meio1]){
           aux[au++] = vetor[esquerda1++];
          }
          else{
           aux[au++] = vetor[meio1++];
          }
          comparacoes++;
     }


     while(esquerda1<=meio2){

          aux[au++] = vetor[esquerda1++];
          comparacoes++;

     }

     while(meio1<=direita){

          aux[au++] = vetor[meio1++];
          comparacoes++;
     }

     for(i=0;i<au;i++){

        vetor[i+esquerda]=aux[i];

      }
}

//metodo de ordenacao quick_sort
void quick_sort(int vetor[],int primeiro,int ultimo){

    int pivo,j,aux,i;

     if(primeiro<ultimo){
         pivo=primeiro;
         i=primeiro;
         j=ultimo;

         while(i<j){

             while(vetor[i]<=vetor[pivo]&&i<ultimo){
                 i++;
             comparacoes++;
             }

             while(vetor[j]>vetor[pivo]){
                 j--;
             comparacoes++;
             }

             if(i<j){

                 aux=vetor[i];
                  vetor[i]=vetor[j];
                  vetor[j]=aux;
             }
             comparacoes++;
         }

         aux=vetor[pivo];
         vetor[pivo]=vetor[j];
         vetor[j]=aux;
         quick_sort(vetor,primeiro,j-1);
         quick_sort(vetor,j+1,ultimo);

    }
}

