// = = = = = = = = = = = = = = = = = = = = = = = = = = //
// Nome: Ian Alvares de Matos Miranda
// Materia: AED I
// Numero do Problema: 1068
// Judge Run: https://judge.beecrowd.com/pt/runs/code/50203312
// Tentativa: 4
// Codigo Produzido dia: 06/10/2026
// = = = = = = = = = = = = = = = = = = = = = = = = = = //

#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int topo;
    char pila[1001];
} pilha;

void pilhaPush(pilha *c, char valor) {
    if (c->topo >= 1000) {
        return;
    }
    
    c->topo++;
    c->pila[c->topo] = valor;
}

char pilhaPop(pilha *c) {
    if (c->topo == -1) {
        return 'a'; 
    }

    char valor = c->pila[c->topo];
    c->topo--;

    return valor;
}

int main() {
    char string[1001];
    int s;
    pilha cabeca;

    while (scanf(" %[^\n]", string) != EOF) {
        s = 0;
        cabeca.topo = -1;

        for (int j = 0; string[j] != '\0'; j++) {
            if (string[j] == '(') {
                pilhaPush(&cabeca, '(');
            } else if (string[j] == ')') {
                if (pilhaPop(&cabeca) == 'a') { 
                    s = 1;
                    break;
                }
            }
        }

        if (!s && cabeca.topo == -1) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
