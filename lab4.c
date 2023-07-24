//Programa: LAB4
//NOME: Vitor Gonçalves Reis da Silva
//Versão 1.2 12/11/22
// ##################### Bibliotecas Externas ##############################
#include <stdio.h>
// ########################## TAD X.h ######################################


struct elemento{
    int info;
    struct elemento *prox;
    struct elemento *ant;

};
typedef struct elemento tipoElemento;

struct estruturaLDDE{
    tipoElemento *primeiro;
    tipoElemento *ultimo;
    int tamanhoLista;
};

typedef struct estruturaLDDE tipoLDDE;

void inicializaLista(tipoLDDE *listaAux){
    listaAux->primeiro=NULL;
    listaAux->ultimo=NULL;
    listaAux->tamanhoLista=0;
}

void Insere(tipoLDDE *listaAux){
    tipoElemento *novo=(tipoElemento*)malloc(sizeof(tipoElemento));
    scanf("%d", &novo->info);
    if(listaAux->tamanhoLista==0){
        novo->prox=NULL;
        novo->ant=NULL;
        listaAux->primeiro=novo;
        listaAux->ultimo=novo;
    }
    else{
        novo->prox=NULL;
        novo->ant=listaAux->ultimo;
        listaAux->ultimo->prox=novo;
        listaAux->ultimo=novo;
    }
    listaAux->tamanhoLista++;

}

void imprimir(tipoLDDE *listaAux){
    tipoElemento *no=listaAux->primeiro;
    while(no!=NULL){
        printf("%d ",no->info);
        no=no->prox;
    }
    

    
}

void adicionar(tipoLDDE *listaAux){
    int valor;
    int posicao;
    int contador=0;
    tipoElemento *novo=(tipoElemento*)malloc(sizeof(tipoElemento));
    tipoElemento *aux=NULL;
    scanf("%d", &novo->info);
    scanf("%d",&posicao);

    aux=listaAux->primeiro;
    while(contador<posicao){
        aux=aux->prox;
        contador++;
    }
    if(posicao==0){
        novo->ant=NULL;
        listaAux->primeiro->ant=novo;
        novo->prox=listaAux->primeiro;
        listaAux->primeiro=novo;
    }
    else{
        if(contador==listaAux->tamanhoLista){
            novo->prox=NULL;
            novo->ant=listaAux->ultimo;
            listaAux->ultimo->prox=novo;
            listaAux->ultimo=novo;

        }
        else{
            novo->prox=aux;
            novo->ant=aux->ant;
            aux->ant->prox=novo;
            aux->ant=novo;
            
        }
    }
    listaAux->tamanhoLista++;
    triplas(listaAux);

}



void triplas(tipoLDDE *listaAux){
    tipoElemento *aux=NULL;
    tipoElemento *aux2=NULL;
    int i;
    int valor=0;
    while(listaAux->tamanhoLista>=3 && valor!=listaAux->tamanhoLista){
        valor = listaAux->tamanhoLista;
        if(listaAux->primeiro->info+listaAux->primeiro->prox->info+listaAux->ultimo->info==10){// primeiro +segundo+ultimo
            if(listaAux->tamanhoLista>3){
            listaAux->primeiro->prox->prox->ant=NULL;
            listaAux->primeiro=listaAux->primeiro->prox->prox;
            listaAux->ultimo->ant->prox=NULL;
            listaAux->ultimo=listaAux->ultimo->ant;
            listaAux->tamanhoLista=listaAux->tamanhoLista-3;

            }
            else{
                aux=listaAux->primeiro;
                for(i=0;i<3;i++){
                    aux=listaAux->primeiro;
                    listaAux->primeiro=aux->prox;
                    listaAux->tamanhoLista--;

                }
            }

            
        }
        else if(listaAux->primeiro->prox->info+listaAux->primeiro->prox->prox->info+listaAux->primeiro->info==10){// segundo+primeiro +terceiro
            listaAux->primeiro->prox->prox->prox->ant=NULL;
            listaAux->primeiro=listaAux->primeiro->prox->prox->prox;
            listaAux->tamanhoLista=listaAux->tamanhoLista-3;
           

        }
        else{
            if(listaAux->ultimo->info+listaAux->ultimo->ant->info+listaAux->primeiro->info==10){//ultimo +penultimo+primeiro
                listaAux->primeiro->prox->ant=NULL;
                listaAux->primeiro=listaAux->primeiro->prox;
                listaAux->ultimo->ant->ant->prox=NULL;
                listaAux->ultimo=listaAux->ultimo->ant->ant;
                listaAux->tamanhoLista=listaAux->tamanhoLista-3;
                
            }
            else if(listaAux->ultimo->ant->info+listaAux->ultimo->ant->ant->info+listaAux->ultimo->info==10){//ultimo+penultimo+antepenultimo
                listaAux->ultimo->ant->ant->ant->prox=NULL;
                listaAux->ultimo= listaAux->ultimo->ant->ant->ant;
                listaAux->tamanhoLista=listaAux->tamanhoLista-3;

            }
            else{//verificacao do meio
                int contador=3;
                aux2=listaAux->primeiro->prox->prox;
                
                while(listaAux->tamanhoLista>3 && contador<listaAux->tamanhoLista-1  && aux2->info+aux2->prox->info+aux2->ant->info!=10){
                    aux2=aux2->prox;
                    contador++;
                }

                
                if(listaAux->tamanhoLista>3 && aux2->info+aux2->prox->info+aux2->ant->info==10){
                    aux2->ant->ant->prox=aux2->prox->prox;
                    aux2->prox->prox->ant=aux2->ant->ant;
                    listaAux->tamanhoLista=listaAux->tamanhoLista-3;
                    

                    
                } 
               
            }
        }
        
    }
    


}
// ###################### Funcoes e Procedimentos do programa #########################
// ############################ Principal ###################################
int main(){
    tipoLDDE minhaLista;
    int i;
    int j;
    inicializaLista(&minhaLista);
    for(i=0;i<10;i++){
        Insere(&minhaLista);
        
    }
    triplas(&minhaLista);
    imprimir(&minhaLista);
    printf("\n");
    for(i=0;i<5;i++){
        adicionar(&minhaLista);
        if(minhaLista.tamanhoLista!=0){
            imprimir(&minhaLista);
            printf("\n");
        }
    }
    if(minhaLista.tamanhoLista==0){
        printf("ganhou");
    }
    else{
        printf("perdeu");
    }
}
