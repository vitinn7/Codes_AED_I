//Programa: LAB6
//NOME: Vitor Gonçalves Reis da Silva
//Versão 1.0 17/11/22
// ##################### Bibliotecas Externas ##############################
#include <stdio.h>
#include <math.h>
// ########################## TAD X.h ######################################  

struct elemento{
    int valor;
    struct elemento *ant;
};
 
typedef struct elemento tipoElemento;

struct pilha{
    int tamanhoPilha;
    tipoElemento *topo;
};

typedef struct pilha tipoPilha;


void inicializaPilha(tipoPilha *pilhaAux){
    pilhaAux->topo=NULL;
    pilhaAux->tamanhoPilha=0;

}

void empilha(tipoPilha *pilhaAux, int dado){
    tipoElemento *novo=(tipoElemento*)malloc(sizeof(tipoElemento));
    
    if(novo==NULL){
        printf("Erro na ao alocar");
        return;
    }
    else{
        novo->valor=dado;
        novo->ant=pilhaAux->topo;
        pilhaAux->topo=novo;
        pilhaAux->tamanhoPilha++;

    }

}

void binario(tipoPilha *pilhaAux,int n){
    int numero;
    numero=n;
    printf("%d ",n);
    while(numero!=0){
        empilha(pilhaAux,numero%2);
        numero=numero/2;
    }
    if(numero==0 && pilhaAux->tamanhoPilha==0){
        empilha(pilhaAux,numero);
    }

}
void imprime(tipoPilha *pilhaAux){
    tipoElemento *aux=pilhaAux->topo;
    if(aux==NULL){
        printf("Pilha vazia\n");
    }
    else{
        while(aux!=NULL){
            printf("%d",aux->valor);
            aux=aux->ant;
        }
    }
    printf(" ");

}
void inverte(tipoPilha *pilhaAux){
    tipoElemento *aux=pilhaAux->topo;
    if(aux==NULL){
        printf("Pilha vazia\n");

    }
    else{
        while(aux!=NULL){
            if(aux->valor==0){
                aux->valor=1;
                aux=aux->ant;

            }
            else{
                aux->valor=0;
                aux=aux->ant;
            }
        }
    }
}
void decimal(tipoPilha *pilhaAux){
    int resultado=0;
    int cont=pilhaAux->tamanhoPilha-1;
    tipoElemento *aux=pilhaAux->topo;
    if(aux==NULL){
        printf("Pilha vazia\n");

    }
    else{
        while(aux!=NULL){
            if(aux->valor!=0){
                resultado=resultado+(aux->valor*(pow(2,cont)));
                //printf("%d",resultado);
            }
            cont--;
            aux=aux->ant;
        }



    }
    printf("%d\n",resultado);

}


int main(){
    tipoPilha minhaPilha;
    int quantidade;
    int i;
    int dado;
    scanf("%d",&quantidade);
    for(i=0;i<quantidade;i++){
        inicializaPilha(&minhaPilha);
        scanf("%d",&dado);
        binario(&minhaPilha,dado);
        imprime(&minhaPilha);
        inverte(&minhaPilha);
        imprime(&minhaPilha);
        decimal(&minhaPilha);

    }
    

}