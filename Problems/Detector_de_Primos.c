#include <stdio.h>

int main(){
    printf("Digite um numero inteiro positivo: ");
    int x;
    scanf("%d", &x);

    int count, numprimos = 0;
    for(int i = 1; i<=x; i++){
        for(int j=1; j<=i; j++){
            if(i%j == 0){
                count++;
            }
        }
        if(count == 2){
            printf("%d eh primo\n", i);
            numprimos++;
        }
        count=0;
    }

    printf("Existem %d primos entre 1 e %d\n", numprimos, x);
    return 0;
}