//Programa: LAB1 Livros
//NOME: Vitor Gonçalves Reis da Silva
//Versão 2.0 06/10/22




#include <stdio.h>
#define N 10


struct listaES{
    int tamanho;
    int lista[N];
    int retiradas;
    int reservas;

};
typedef struct listaES tipoListaES;


void inicializaLista(tipoListaES *listaAux){
    int i;
    listaAux->tamanho=0;
    for(i=0;i<N;i++){
        listaAux->lista[i]=0;

    }
    listaAux->retiradas=0;
    listaAux->reservas=0;
}
void insereElemento(tipoListaES *listaAux){
    int aux;
    if(listaAux->tamanho<10){
        listaAux->tamanho++;
        scanf("%d",&listaAux->lista[listaAux->tamanho-1]);
        printf("Sua reserva foi realizada\n");
        listaAux->reservas++;
        
    }
    else{
        scanf("%d",&aux);
        printf("Lista de reserva cheia\n");
    }
    

}

void retiraElemento(tipoListaES *listaAux){
    int i;
    int j;
    int procura;
    int cont1=0;
    scanf("%d",&procura);
    for(i=0;i<listaAux->tamanho;i++){
        if(procura==listaAux->lista[i]){
            cont1++;
            for(j=i;j<listaAux->tamanho;j++){
                listaAux->lista[j]=listaAux->lista[j+1];
                
            }
            listaAux->tamanho--;
            listaAux->retiradas++;
            printf("O livro foi retirado com sucesso\n");
            
        }

    }
    if(cont1==0){
        printf("Voce nao possui reserva desse livro\n");
    }

}
//oid imprimi(tipoListaES *listaAux){
    //int i;
    //for(i=0;i<listaAux->tamanho;i++){
    //    printf("%d",listaAux->lista[i]);
  //  }
//}
int main(){
    int i;
    int cont;
    int escolha;
    int *retiradas;
    tipoListaES minhaLista;
    scanf("%d",&cont);
    inicializaLista(&minhaLista);
    for(i=0;i<cont;i++){
        scanf("%d",&escolha);
        if(escolha==1){
            insereElemento(&minhaLista);
        }
        if(escolha==2){
            retiraElemento(&minhaLista);
        }


            
        
    } 
    printf("Voce realizou %d reservas e %d retiradas\n",minhaLista.reservas,minhaLista.retiradas);
    //imprimi(&minhaLista);
}