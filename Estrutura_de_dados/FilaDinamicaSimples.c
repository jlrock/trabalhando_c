#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

/* inicializa a fila */
void inicializar(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

/* verifica se a fila está vazia */
int filaVazia(Fila *f) {
    return (f->inicio == NULL);
}

/* insere no final da fila */
int enqueue(Fila *f, int valor) {
    No *novo = (No*) malloc(sizeof(No));

    if (!novo) {
        printf("\nErro: memoria insuficiente!");
        return 0;
    }

    novo->dado = valor;
    novo->prox = NULL;

    /* se a fila estiver vazia */
    if (filaVazia(f)) {
        f->inicio = novo;
        f->fim = novo;
    }
    else {
        f->fim->prox = novo;
        f->fim = novo;
    }

    return 1;
}

/* remove do início da fila */
int dequeue(Fila *f, int *valorRemovido) {
    No *removido;

    if (filaVazia(f)) {
        printf("\nErro: fila vazia!");
        return 0;
    }

    removido = f->inicio;
    *valorRemovido = removido->dado;

    f->inicio = removido->prox;

    /* se a fila ficou vazia */
    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(removido);
    return 1;
}

/* consulta o primeiro elemento */
int front(Fila *f, int *valorInicio) {
    if (filaVazia(f)) {
        printf("\nFila vazia!");
        return 0;
    }

    *valorInicio = f->inicio->dado;
    return 1;
}

/* imprime a fila */
void imprimir(Fila *f) {
    No *aux = f->inicio;

    if (filaVazia(f)) {
        printf("\nFila vazia!");
        return;
    }

    printf("\nInicio -> ");

    while (aux != NULL) {
        printf("%d ", aux->dado);
        aux = aux->prox;
    }

    printf("<- Fim");
}

/* libera toda a memória */
void liberar(Fila *f) {
    No *aux = f->inicio;

    while (aux != NULL) {
        No *temp = aux->prox;
        free(aux);
        aux = temp;
    }

    f->inicio = NULL;
    f->fim = NULL;
}

int main(void) {
    Fila f;
    int valor;

    inicializar(&f);

    enqueue(&f, 10);
    enqueue(&f, 20);
    enqueue(&f, 30);

    imprimir(&f);

    if (dequeue(&f, &valor)) {
        printf("\nRemovido: %d", valor);
    }

    imprimir(&f);

    if (front(&f, &valor)) {
        printf("\nPrimeiro da fila: %d", valor);
    }

    liberar(&f);
    return 0;
}
