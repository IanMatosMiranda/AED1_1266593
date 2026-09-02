#include <stdio.h>
#include <stdlib.h>w

/*
* Utiliza listas encadiadas e alocação dinâmica para determinar
* o menor valor informado.
*/

typedef struct TValor {
    int valor;
    struct TValor *pointer;
} TValor;

TValor cabeca = {0, NULL};

void main() {
    
    for (int i = 0; i<100; i++) {
        TValor *ponteiro = &cabeca;
        while (ponteiro->pointer != NULL) {
            ponteiro = ponteiro->pointer;
        }

        TValor *novo = (TValor *) malloc(sizeof(TValor));
        if (novo == NULL) return 1;

        scanf("%d", &novo->valor);
        novo->pointer = NULL;

        ponteiro->pointer = novo;
    }

    TValor *No = cabeca.pointer;
    int maior = No->valor;
    int index = 1;
    int i = 1;

    while (No != NULL) {
        if (No->valor > maior) {
            maior = No->valor;
            index = i;
        }
        i++;
        No = No->pointer;
    }

    printf("%d\n", maior);
    printf("%d\n", index);

    No = cabeca.pointer;
    while (No != NULL) {
        TValor *temp = No;
        No = No->pointer;
        free(temp);
    }

    return 0;

}
