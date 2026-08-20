#include <stdio.h>
 
 /*
 Programa cria um vetor de 100 posições, enquanto ele coloca na memo -
 ria sua informação dos 100 numeros, ele compara se aquele numero se -
 ria o maior int possivel dentro do vetor.
 ********************************************************************/
 
int main() {
 
    int vet[100];
    int maxIndex = 0;
    
    for (int i = 0; i < 100; i++) {
        scanf("%i", &vet[i]);
        if (vet[i] > vet[maxIndex]) {
            maxIndex = i;
        }
    }
    
    printf("%i\n%i\n", vet[maxIndex], maxIndex + 1);
 
    return 0;
}
