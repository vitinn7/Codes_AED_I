//Programa: LAB5
//NOME: Vitor Gonçalves Reis da Silva
//Versão 1.0 13/11/22
// ##################### Bibliotecas Externas ##############################
#include <stdio.h>
// ########################## TAD X.h ######################################  


struct filaCircular{
    int primeiro;
    int ultimo;
    int tamanhofila;
    int elementos[100];
    
};
typedef struct filaCircular tipoFC;

void inicializaFila(tipoFC *filaAux){
    int i;
    filaAux->primeiro=-1;
    filaAux->ultimo=-1;
    filaAux->tamanhofila=0;
    for(i=0;i<100;i++){
        filaAux->elementos[i]=0;
    }
}
// ###################### Funcoes e Procedimentos do programa #########################
int filaVazia(tipoFC *filaAux){
    if(filaAux->primeiro==filaAux->ultimo && filaAux->ultimo==-1){
        return 1;//fila vazia

    }
    else{
        return 0;//fila nao esta vazia
    }
}

int filaCheia(tipoFC *filaAux){
    if((filaAux->ultimo+1)%100==filaAux->primeiro){
        return 1;//fila esta cheia

    }
    else{
        return 0;//fila está cheia
    }
}

void insereElemento(tipoFC *filaAux){
    int dado;
    scanf("%d",&dado);
    if(filaVazia(filaAux)==1){
        filaAux->primeiro=0;
        filaAux->ultimo=0;
        filaAux->elementos[0]=dado;
        filaAux->tamanhofila++;
        
    }
    else if(filaCheia(filaAux)==0){
        int posicao=((filaAux->ultimo+1)%100);
        filaAux->elementos[posicao]=dado;
        filaAux->ultimo=posicao;
        filaAux->tamanhofila++;
    }
    else{
        printf("Fila cheia");
    }
    
}

void remover(tipoFC *filaAux){
    int i;
    if(filaAux->tamanhofila==0){
        printf("vazia\n");
    }
    else if(filaAux->tamanhofila==1){
        inicializaFila(filaAux);
 
    }
    else{
        for(i=0;i<filaAux->tamanhofila;i++){
            filaAux->elementos[i]=filaAux->elementos[i+1];
            
        }
        filaAux->tamanhofila--;
        filaAux->ultimo--;

    }


}
void conclusao(tipoFC *filaAux){
    int i;
    int dado;

    if(filaAux->tamanhofila>0){
        dado=filaAux->elementos[filaAux->primeiro];
        for(i=0;i<filaAux->tamanhofila;i++){
            filaAux->elementos[i]=filaAux->elementos[i+1];
        }
        filaAux->elementos[filaAux->tamanhofila-1]=dado;
    }
    else{
        printf("vazia\n");

    }



}
void imprime(tipoFC *filaAux){
    int i;
    for(i=filaAux->tamanhofila-1;i>=filaAux->primeiro;i--){
        printf("%d ",filaAux->elementos[i]);

    }
    printf("\n");

}

// ############################ Principal ###################################
int main(){
    tipoFC minhaFila;
    int i;
    int repeticoes;
    int escolha;
    inicializaFila(&minhaFila);
    scanf("%d",&repeticoes);
    for(i=0;i<repeticoes;i++){
        scanf("%d",&escolha);
        switch(escolha){
            case 1:
            insereElemento(&minhaFila);
            break;
            case 2:
            remover(&minhaFila);

            break;
            case 3:
            conclusao(&minhaFila);

            break;
            default:
            printf ("Valor invalido!\n");

        }
    }
    imprime(&minhaFila);
}