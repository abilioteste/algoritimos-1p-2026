#include <stdio.h>

int main(){
    int valor, i, maior = 0, posicao = 1;
    for(i = 0; i < 5; i++){ 
        scanf("%d", &valor);
        if (valor > maior){ 
            maior = valor;
            posicao = i + 1;
        }
    }
    printf("%d\n%d\n", maior, posicao);

    return 0;
}