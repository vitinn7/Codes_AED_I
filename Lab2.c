//Programa: LAB2 
//NOME: Vitor Gonçalves Reis da Silva
//Versão 2.0 24/10/22
// ##################### Bibliotecas Externas ##############################
#include <stdio.h>
#define N 10
// ########################## TAD X.h ######################################

struct info{
    int valor;
    int prox;

};
typedef struct info tipoInfo;

struct listaEE{
    int tamanhoLista;
    int primeiro;
    int ultimo;
    int posLivre[N];
    int quantidade[8];
    tipoInfo elemento[N];
};
typedef struct listaEE tipoListaEE;

void inicializaLista(tipoListaEE *listaAux){
    int i=0;
    listaAux->tamanhoLista=0;
    listaAux->primeiro=-1;
    listaAux->ultimo=-1;
    listaAux->ultimo=-1;
    for(i=0;i<N;i++){
        listaAux->elemento[i].valor=0;
        listaAux->elemento[i].prox=-1;
        listaAux->posLivre[i]=1;
        listaAux->quantidade[i]=0;
    }
}
void imprimi(tipoListaEE *listaAux){
    int i;
    int aux;
    int j;

    for(i=0;i<listaAux->tamanhoLista;i++){
        
        if(i==0){
            printf("%d ",listaAux->elemento[listaAux->primeiro].valor);
            aux=listaAux->elemento[listaAux->primeiro].prox;
            j=i;

        }
        else{
            printf("%d ",listaAux->elemento[aux].valor);

            aux=listaAux->elemento[aux].prox;
            j=i;
        }
        

    }
    printf("\n");

    //if(j==listaAux->tamanhoLista-1){
        //printf("\n");
    //}

}
void insereElemento(tipoListaEE *listaAux){ 
    int i;
    int j;
    int aux;
    int valor=66000;
    int teto=66999;
    for(i=0;i<N;i++){
        if(listaAux->posLivre[i]==1){
            j=i;
            listaAux->posLivre[j]=0;
            break;
        }
    }
    scanf("\n%d",&listaAux->elemento[j].valor);
    for(i=0;i<8;i++){
        if(listaAux->elemento[j].valor>=valor && listaAux->elemento[j].valor<teto){
            listaAux->quantidade[i]++;
            valor=valor+10000;
            teto=teto+10000;
        }
        else{
            valor=valor+10000;
            teto=teto+10000;

        }
    }

    if(listaAux->tamanhoLista==0){
        listaAux->elemento[j].prox=-1;
        listaAux->primeiro=j;
        listaAux->tamanhoLista++;
        listaAux->ultimo=j;
        listaAux->posLivre[j]=0;
    }
    else if(listaAux->elemento[j].valor< listaAux->elemento[listaAux->primeiro].valor){
        listaAux->elemento[j].prox=listaAux->primeiro;
        listaAux->primeiro=j;
        listaAux->tamanhoLista++;
         listaAux->posLivre[j]=0;
    }
    else{
        aux=listaAux->primeiro;
        while(listaAux->elemento[aux].prox!= -1 && listaAux->elemento[j].valor> listaAux->elemento[listaAux->elemento[aux].prox].valor ){
            aux=listaAux->elemento[aux].prox;
            
        }
        listaAux->posLivre[j]=0;
        listaAux->elemento[j].prox=listaAux->elemento[aux].prox;
        listaAux->elemento[aux].prox=j;
        listaAux->ultimo=j;
        listaAux->tamanhoLista++;

        
    }

}   
    

void remover(tipoListaEE *listaAux){
    int num;
    int remover=0;
    int aux;
    scanf("%d",&num);
    if(listaAux->tamanhoLista!=0){
        if(listaAux->elemento[listaAux->primeiro].valor==num){
            remover=listaAux->primeiro;
            listaAux->primeiro=listaAux->elemento[remover].prox;
            listaAux->posLivre[remover]=1;
            listaAux->tamanhoLista--;
            imprimi(listaAux);

        }
        else{
            aux=listaAux->primeiro;
            while(listaAux->elemento[aux].prox!= -1 && listaAux->elemento[listaAux->elemento[aux].prox].valor!=num){
                aux=listaAux->elemento[aux].prox;
            }
            if(listaAux->elemento[aux].prox!= -1){
                remover=listaAux->elemento[aux].prox;
                listaAux->elemento[aux].prox=listaAux->elemento[remover].prox; 
                listaAux->posLivre[remover]=1;
                listaAux->tamanhoLista--;
                imprimi(listaAux);

            }
            else{
                printf("nao existe\n");
                imprimi(listaAux);
            }

        }

    }
    else{
        printf("nao existe\n");
        imprimi(listaAux);

    }


}
void imprimir2(tipoListaEE *listaAux){
    int ano=2011;
    int i;
    for(i=0;i<8;i++){
        if(i!=7){
            printf("%d: %d\n", ano, listaAux->quantidade[i]);
            ano=ano+1;

        }
        else{
            printf("%d: %d", ano, listaAux->quantidade[i]);

        }


    }

}

int main(){
    int cont;
    int i;
    int escolha;
    int aux;
    tipoListaEE minhaLista;
    inicializaLista(&minhaLista);
    scanf("%d",&cont);
    for(i=0;i<cont;i++){
        scanf("%d",&escolha);
        if(escolha==1){
            if(minhaLista.tamanhoLista<N){
                insereElemento(&minhaLista);
                imprimi(&minhaLista);

            }
            else{
                scanf("%d",&aux);
                printf("lista cheia\n");
                imprimi(&minhaLista);
            }
        }
        if(escolha==2){
            remover(&minhaLista);

        }

    }

    imprimir2(&minhaLista);



}