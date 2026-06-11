#include <stdio.h>
#include <stdlib.h>

void alocar(int **vetor, int *tamanho) {
if (*vetor != NULL) {
printf("Vetor ja alocado!\n");
return;
}

printf("Digite o tamanho do vetor: ");
scanf("%d", tamanho);

*vetor = (int *) malloc((*tamanho) * sizeof(int));

if (*vetor == NULL) {
printf("Erro ao alocar memoria!\n");
*tamanho = 0;
return;
}

printf("Vetor alocado com sucesso!\n");
}

void redimensionar(int **vetor, int *tamanho) {
if (*vetor == NULL) {
printf("Vetor ainda nao alocado!\n");
return;
}

int novo_tamanho;
printf("Digite o novo tamanho: ");
scanf("%d", &novo_tamanho);

int *temp = (int *) realloc(*vetor, novo_tamanho * sizeof(int));

if (temp == NULL) {
printf("Erro ao redimensionar!\n");
return;
}

*vetor = temp;
*tamanho = novo_tamanho;

printf("Vetor redimensionado com sucesso!\n");
}

void preencher(int *vetor, int tamanho) {
if (vetor == NULL) {
printf("Vetor nao alocado!\n");
return;
}

for (int i = 0; i < tamanho; i++) {
printf("vetor[%d]: ", i);
scanf("%d", &vetor[i]);
}
}

void imprimir(int *vetor, int tamanho) {
if (vetor == NULL) {
printf("Vetor nao alocado!\n");
return;
}

printf("\nConteudo do vetor:\n");
for (int i = 0; i < tamanho; i++) {
printf("[%d] = %d\n", i, vetor[i]);
}
}

void liberar(int **vetor, int *tamanho) {
if (*vetor == NULL) {
printf("Vetor ja esta vazio!\n");
return;
}

free(*vetor);
*vetor = NULL;
*tamanho = 0;

printf("Memoria liberada!\n");
}

int main() {
int *vetor = NULL;
int tamanho = 0;
int opcao;

do {
printf("\n===== MENU =====\n");
printf("1 - Alocar vetor\n");
printf("2 - Redimensionar vetor\n");
printf("3 - Preencher vetor\n");
printf("4 - Imprimir vetor\n");
printf("5 - Liberar memoria\n");
printf("0 - Sair\n");
printf("Escolha: ");
scanf("%d", &opcao);

switch (opcao) {
case 1:
alocar(&vetor, &tamanho);
break;
case 2:
redimensionar(&vetor, &tamanho);
break;
case 3:
preencher(vetor, tamanho);
break;
case 4:
imprimir(vetor, tamanho);
break;
case 5:
liberar(&vetor, &tamanho);
break;
case 0:
liberar(&vetor, &tamanho);
printf("Encerrando...\n");
break;
default:
printf("Opção inválida!\n");
}

} while (opcao != 0);

return 0;
}