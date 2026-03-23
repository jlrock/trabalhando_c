#include <stdio.h>

int main(){
    int x;
    while (x != 0){
        printf("Digite um numero entre 1, 2, 3 e 4. Digite 0 para sair:\n");
        scanf("%d", &x);
        switch (x){
            case 1:
                printf("Numero 1 escolhido\n");
                break;
            case 2:
                printf("Numero 2 escolhido\n");
                break;
            case 3:
                printf("Numero 3 escolhido\n");
                break;
            case 4:
                printf("Numero 4 escolhido\n");
                break;
            default:
                printf("Nenhum desses numeros escolhidos\n");
                break;
        }
    }
    printf("Saindo...");
    return 0;
}