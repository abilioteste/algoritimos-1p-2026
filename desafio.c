#include <stdio.h>

int main(){
    double num1, num2, media;
    scanf("%lf %lf", &num1, &num2);
    media = (num1 * 0.35) + (num2 * 0.75);
    printf("MEDIA = %.5lf\n", media);

    return 0;
}