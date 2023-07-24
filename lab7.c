//Programa: LAB2 
//NOME: Vitor Gonçalves Reis da Silva
//Versão 1.0 06/12/22
// ##################### Bibliotecas Externas ##############################
#include <stdio.h>
#include <string.h>
// ########################## TAD X.h ######################################

struct pessoa{
    char nome[15];
    char sexo;
    int ano;
    char antecessor[15];


};
typedef struct pessoa tipoPessoa;

struct noArvoreBB{
    tipoPessoa pessoa;
    struct noArvoreBB *esq;
    struct noArvoreBB *dir;
};

typedef struct noArvoreBB tipoABB;

// ###################### Funcoes e Procedimentos do programa #########################
void inicializa(tipoABB **arvoreAux){
    tipoABB *novo= *arvoreAux;
    char nome[15];
    char sexo;
    int ano;
    novo=(tipoABB*)malloc(sizeof(tipoABB));
    scanf("%s %c",&nome,&sexo);
    scanf("%d",&ano);
    strcpy(novo->pessoa.nome,nome);
    novo->pessoa.sexo=sexo;
    novo->pessoa.ano=ano;
    novo->dir=NULL;
    novo->esq=NULL;
    *arvoreAux=novo;
}
tipoABB* busca(tipoABB *arvoreAux,char pesquisa[]){
    tipoABB* aux=NULL;
    tipoABB* aux2=NULL;
    if(arvoreAux){
        if(strcmp(arvoreAux->pessoa.nome,pesquisa)==0){
            return arvoreAux;
        }
        aux=busca(arvoreAux->esq,pesquisa);
        if(aux && strcmp(aux->pessoa.nome,pesquisa)==0){
            return aux;
        }
        aux2=busca(arvoreAux->dir,pesquisa);
        if(aux2 && strcmp(aux2->pessoa.nome,pesquisa)==0){
            return aux2;
        }
        
    }
    
}
tipoABB* ultimo(tipoABB *arvoreAux){
    tipoABB* aux=NULL;
    tipoABB* aux2=NULL;
    if(arvoreAux){
        if(arvoreAux->dir==NULL && arvoreAux->esq==NULL){
            return arvoreAux;
        }
        aux=ultimo(arvoreAux->esq);
        if(aux &&(aux->dir==NULL && aux->esq==NULL )){
            return aux;
        }
    }
}

void procurar(tipoABB *aux,char pesquisa[],char nome[],char sexo,int ano){
    tipoABB *aux2=NULL;
    aux2=busca(aux,pesquisa);

    if(strcmp(aux2->pessoa.nome,pesquisa)==0){
        if(aux2->esq==NULL){
            tipoABB *novo=(tipoABB*)malloc(sizeof(tipoABB));
            strcpy(novo->pessoa.nome,nome);
            novo->pessoa.sexo=sexo;
            novo->pessoa.ano=ano;
            strcpy(novo->pessoa.antecessor,pesquisa);
            novo->esq=NULL;
            novo->dir=NULL;
            aux2->esq=novo;
        }
        else{
            if(aux2->esq->pessoa.sexo=='M'){
                if(sexo=='M' && ano<aux2->esq->pessoa.ano){
                    tipoABB *novo=(tipoABB*)malloc(sizeof(tipoABB));
                    strcpy(novo->pessoa.nome,nome);
                    novo->pessoa.sexo=sexo;
                    novo->pessoa.ano=ano;
                    strcpy(novo->pessoa.antecessor,pesquisa);  
                    novo->esq=NULL;
                    novo->dir=NULL;
                    aux2->dir=aux2->esq;
                    aux2->esq=novo;
                }
                else{
                    tipoABB *novo=(tipoABB*)malloc(sizeof(tipoABB));
                    strcpy(novo->pessoa.nome,nome);
                    novo->pessoa.sexo=sexo;
                    novo->pessoa.ano=ano;
                    strcpy(novo->pessoa.antecessor,pesquisa);
                    novo->esq=NULL;
                    novo->dir=NULL;
                    aux2->dir=novo;
                }

            }
            else{
                if((sexo=='M' && aux2->esq->pessoa.ano<2011) || ano<aux2->esq->pessoa.ano){
                    printf("oi");
                    tipoABB *novo=(tipoABB*)malloc(sizeof(tipoABB));
                    strcpy(novo->pessoa.nome,nome);
                    novo->pessoa.sexo=sexo;
                    novo->pessoa.ano=ano;
                    strcpy(novo->pessoa.antecessor,pesquisa);
                    novo->esq=NULL;
                    novo->dir=NULL;
                    aux2->dir=aux2->esq;
                    aux2->esq=novo;
                }
                else{
                    tipoABB *novo=(tipoABB*)malloc(sizeof(tipoABB));
                    strcpy(novo->pessoa.nome,nome);
                    novo->pessoa.sexo=sexo;
                    novo->pessoa.ano=ano;
                    strcpy(novo->pessoa.antecessor,pesquisa);
                    novo->esq=NULL;
                    novo->dir=NULL;
                    aux2->dir=novo;
                }
            }
        
        }
    }
   
}
void inserir(tipoABB **arvoreAux){
    char nome[15];
    char sexo;
    int ano;
    char antecessor[15];
    scanf("%s %c %d %s",&nome,&sexo,&ano,&antecessor);
    procurar(*arvoreAux,antecessor,nome,sexo,ano);

}
void imprimir(tipoABB *arvoreAux){
    //printf("oi");
    if(arvoreAux){
        printf("%s\n",arvoreAux->pessoa.nome);
        imprimir(arvoreAux->esq);
        imprimir(arvoreAux->dir);
    }

   
}

void remover(tipoABB *arvoreAux){
    char procura[15];
    scanf("%s",&procura);
    tipoABB *aux=NULL;
    tipoABB *aux2=NULL;
    tipoABB *aux3=NULL;
    tipoABB *aux4=NULL;
    aux=busca(arvoreAux,procura);
    aux2=ultimo(arvoreAux);
    aux4=busca(arvoreAux,aux2->pessoa.antecessor);
    while(strcmp(aux2->pessoa.nome,procura)!=0){
        if(aux2->dir==NULL && aux2->esq==NULL){
            if(strcmp(aux4->esq->pessoa.nome,aux2->pessoa.nome)==0){
                aux4->esq=aux4->dir;
                aux4->dir=NULL;
            }
            else{
                aux4->dir=NULL;
            }
            free(aux2);
            aux2=ultimo(aux);
            aux4=busca(arvoreAux,aux2->pessoa.antecessor);
        }
    }

    aux3=busca(arvoreAux,aux2->pessoa.antecessor);
    if(strcmp(aux3->esq->pessoa.nome,procura)==0){
        aux3->esq=aux3->dir;
        aux3->dir=NULL;
    
    }
    else{
        aux3->dir=NULL;
    }
    free(aux2);




}





// ############################ Principal ###################################
int main(){
    int quant;
    int i;
    int escolha;
    tipoABB *minhaArvore=NULL;
    inicializa(&minhaArvore);
    scanf("%d",&quant);
    for(i=0;i<quant;i++){
        scanf("%d",&escolha);
        if(escolha==1){
            inserir(&minhaArvore);
        }
        else if(escolha==2){
            remover(minhaArvore);

        }
        else{
            printf("valor invalido");
        }
    }
    imprimir(minhaArvore);
    
    
    
    
    




}


