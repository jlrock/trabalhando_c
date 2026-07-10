#include <stdio.h>
#include <stdlib.h>
//questão ainda está incompleta 

typedef struct No{
    int dado;
    struct No* prox;
}No;

typedef struct{
    No* inicio;
}Lista;

Lista* criarLista(){
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    if(lista == NULL){
        printf("Erro ao alocar memoria para a lista\n");
        return NULL;
    }
    lista->inicio=NULL;
    return lista;
}

No* criarNo(int dado){
    No* no = (No*) malloc(sizeof(No));
    if(no==NULL){
        printf("Erro ao alocar memoria para o no\n");
        return NULL;
    }
    no->dado=dado;
    no->prox=NULL;
    return no;
}

void addNoLista(Lista* lista, No* no){
    if(lista->inicio==NULL){
        lista->inicio=no;
        return;
    }

    No* aux = lista->inicio;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox=no;
}

int main(){
    Lista * lista = criarLista();

    No* noX;
    for(int i=1; i<=4; i++){
        noX = criarNo(i*10);
        addNoLista(lista, noX);
    }

    No* aux = lista->inicio;
    while(aux != NULL){
        printf("%d -> ", aux->dado);
        aux = aux->prox;
    }
    printf("NULL\n");
    return 0;
}