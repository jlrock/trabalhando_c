#include <stdio.h>
#include <math.h>

int main(){
    int a, b, c;
    float x1, x2, delta;

    printf("\nBem vindo(a) a minha calculadora de equacao do segundo grau!");

    printf("\nDigite o termo que multiplica o x2: ");
    scanf("%d", &a);

    printf("\nDigite o termo que multiplica o x: ");
    scanf("%d", &b);
    
    printf("\nDigite o termo independente: ");
    scanf("%d", &c);

    printf("\nSua equacao do segundo grau eh (%d)x2 + (%d)x + (%d) = 0", a,b,c);
    
    delta = b*b - 4*a*c;
    
    if(delta < 0){
        printf("\nEquacao sem solucao nos reais.");
        return 0;
    }
    
    x1 = (-b+sqrt(delta))/(2*a);
    x2 = (-b-sqrt(delta))/(2*a);
    
    if(x1==x2){
        printf("\nAs duas raizes da equacao sao %f", x1);
        return 0;
    }

    printf("\nAs raizes da equacao sao %f e %f", x1, x2);
    
    return 0;
}