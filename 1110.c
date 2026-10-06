// = = = = = = = = = = = = = = = = = = = = = = = = = = //
// Nome: Ian Alvares de Matos Miranda
// Materia: AED I
// Numero do Problema: 1110
// Judge Run: https://judge.beecrowd.com/pt/runs/code/50166235
// Tentativa: 3
// Codigo Produzido dia: 02/10/2026
// = = = = = = = = = = = = = = = = = = = = = = = = = = //

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int valor;
    struct node *p;
} node;

typedef struct cabeca {
    node *inicio;
    node *fim;
} cabeca;

void AddFila(cabeca *c, int n) {
    node *nd = (node *) malloc(sizeof(node));
    if (nd == NULL) return;

    nd->valor = n;
    nd->p = NULL;

    if (c->inicio == NULL) {
        c->inicio = nd;
        c->fim = nd;
    } else {
        c->fim->p = nd;
        c->fim = nd;
    }
}

int RemoveFila(cabeca *c) {
    node *v = c->inicio;

    if (v == NULL) {
        return -1;
    }

    c->inicio = v->p;
    int i = v->valor;

    if (c->inicio == NULL) {
        c->fim = NULL;
    }

    free(v);

    return i;
}

void run(cabeca *c, int n) {
    c->inicio = NULL;
    c->fim = NULL;

    for (int i = 0; i < n; i++) {
        AddFila(c, i + 1);
    }

    printf("Discarded cards:");
    int primeiro = 1;

    while (c->inicio != NULL && c->inicio->p != NULL) {
        int p = RemoveFila(c);
        
        if (primeiro) {
            printf(" %i", p);
            primeiro = 0;
        } else {
            printf(", %i", p);
        }

        int movida = RemoveFila(c);
        AddFila(c, movida);
    }

    printf("\n");

    int restante = RemoveFila(c);
    printf("Remaining card: %i\n", restante);
}

int main() {
    int n; 

    cabeca *c = (cabeca *) malloc(sizeof(cabeca));
    c->inicio = NULL;
    c->fim = NULL;

    while (scanf("%i", &n) == 1 && n != 0) {
        run(c, n);
    }

    free(c);
    return 0;
}
