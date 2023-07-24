//Programa: LAB3
//NOME: Vitor Gonçalves Reis da Silva
//Versão 1.0 31/10/22
// ##################### Bibliotecas Externas ##############################
#include <stdio.h>
// ########################## TAD X.h ######################################




struct elemento{
    int info;
    int quantP;
    float preco;
    float precof;
    struct elemento *prox;
};
typedef struct elemento tipoElemento;

struct listaDE{
    tipoElemento *primeiro;
    tipoElemento *ultimo;
    int tamanhoLista;

};
typedef struct listaDE tipoLDE;


void inicializaLista(tipoLDE *listaAux){
    listaAux->primeiro=NULL;
    listaAux->ultimo=NULL;
    listaAux->tamanhoLista=0;
}

void Inserir(tipoLDE *listaAux){
    int info;
    int cont=0;
    tipoElemento *novoElem=malloc(sizeof(tipoElemento));
    tipoElemento *aux=malloc(sizeof(tipoElemento));
    tipoElemento *aux2=malloc(sizeof(tipoElemento));
    scanf("%d",&novoElem->info);
    scanf("%d",&novoElem->quantP);
    scanf("%f",&novoElem->preco);
    novoElem->precof=0;
    aux2=listaAux->primeiro;
    while(aux2!=NULL){
        if(aux2->info== novoElem->info){
            cont++;
        }
        aux2=aux2->prox;
    }
    if(cont==0){

        if(listaAux->tamanhoLista==0){
            novoElem->prox=NULL;
            listaAux->primeiro=novoElem;
            listaAux->ultimo=novoElem;

        }
        else if(novoElem->preco > listaAux->primeiro->preco){
            novoElem->prox= listaAux->primeiro;
            listaAux->primeiro=novoElem;
            
        }
        else{
            aux=listaAux->primeiro;
            while(aux->prox!=NULL && novoElem->preco< aux->prox->preco){
                aux=aux->prox;
            }
            if(aux->prox==NULL){
                novoElem->prox=aux->prox;
                aux->prox=novoElem;
                listaAux->ultimo=novoElem;

            }
            else{
                novoElem->prox=aux->prox;
                aux->prox=novoElem;

            }


        }
        listaAux->tamanhoLista++;
    }
    else{
        printf("ja existe\n");
    }

}
void remover(tipoLDE *listaAux){
    int busca;
    tipoElemento *remover=NULL;
    tipoElemento *aux=NULL;
    scanf("%d",&busca);
    if(listaAux->tamanhoLista!=0){
        if(listaAux->primeiro->info==busca){
            
            remover=listaAux->primeiro;
            listaAux->primeiro=remover->prox;
            listaAux->tamanhoLista--;
        }
        else{
            aux=listaAux->primeiro;
            while(aux->prox!=NULL && aux->prox->info!=busca){
                aux=aux->prox;
            }
            if(aux->prox!=NULL){
                remover=aux->prox;
                aux->prox=remover->prox;
                listaAux->tamanhoLista--;
            }
            else{
                printf("nao existe\n");

            }

        }
    }

}
void imprimir(tipoLDE *listaAux){
    int i;
    tipoElemento *no=listaAux->primeiro;
    while(no!=NULL){
        printf("%d %f\n",no->info, no->precof);
        no=no->prox;
    }
    
}
// ###################### Funcoes e Procedimentos do programa #########################

void aumentar(tipoLDE *listaAux){
    int busca;
    int quant;
    tipoElemento *no=listaAux->primeiro;
    scanf("%d",&busca);
    scanf("%d",&quant);
    while(no!=NULL && busca!=no->info){
        no=no->prox;

    }
    if(no!=NULL){  
        no->quantP=no->quantP+quant;
    }
    else{
        printf("nao existe\n");
    }
}

void contabilizar(tipoLDE *listaAux){
    int busca;
    scanf("%d",&busca);
    tipoElemento *no=listaAux->primeiro;
    while(no!=NULL && busca!=no->info){
        no=no->prox;
    }
    if(no!=NULL){  
        if(no->quantP!=0){
            no->precof=no->precof+no->preco;
            no->quantP--;

        }
        else{
            printf("nao existe\n");

        }
        
    }
    else{
        printf("nao existe\n");

    }
    
    
}

// ############################ Principal ###################################

int main(){
    tipoLDE minhaLista;
    int cont,escolha;
    int i;
    inicializaLista(&minhaLista);
    scanf("%d",&cont);
    for(i=0;i<cont;i++){
        scanf("%d",&escolha);
        switch ( escolha ){
            case 1:
            Inserir(&minhaLista);
            break;
            case 2:
            aumentar(&minhaLista);
            break;
            case 3:
            contabilizar(&minhaLista);
            break;
            case 4:
            remover(&minhaLista);
            break;
            default:
            printf ("Valor invalido!\n");
        }
    }
    imprimir(&minhaLista);



}