#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
 
int processarMatriz() {
    int **m = (int **) malloc(9 * sizeof(int *));
    if (m == NULL) return 3;

    for (int i = 0; i < 9; i++){
        m[i] = (int *) malloc(9 * sizeof(int));
        if (m[i] == NULL) return 1;
    }

    int nums[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    for (int i = 0; i < 9; i++) {
        scanf("%i %i %i %i %i %i %i %i %i", &m[i][0], &m[i][1], &m[i][2], &m[i][3], &m[i][4], &m[i][5], &m[i][6], &m[i][7], &m[i][8]);
    }
    
    int somaV, somaH;
    int resultado = 0;
    
    for (int i = 0; i < 81; i++) {
        nums[m[i/9][i%9] - 1] += 1;
    }

    for (int i = 0; i < 9; i++) {
        if (nums[i] != 9) {
            resultado = 1;
        }
    }

    for (int i = 0; i < 9; i++) {
        somaV = 0;
        somaH = 0;
        for (int j = 0; j < 9; j++) {
            somaV += m[i][j];
            somaH += m[j][i];
        }
        
        if (somaV != 45 || somaH != 45) {
            resultado = 1;
        }
    }
    
    int somaQ;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            somaQ = 0;
            for (int w = 0; w < 3; w++) {
                for (int n = 0; n < 3; n++) {
                    somaQ += m[(3*i + w)][(3*j + n)];
                }
            }
            if (somaQ != 45) {
                resultado = 1;
            }
        }
    }
    
    for (int i = 0; i < 9; i++) {
        free(m[i]);
    }
    free(m);
    m = NULL;
    
    return resultado;
}
 
int main() {
 
    int value;

    scanf("%i", &value);

    int results[value];

    for (int i = 0; i<value; i++) {
        results[i] = processarMatriz();
    }
    
    for (int i = 0; i<value; i++) {
        if (results[i]) {
            printf("Instancia %i\nNAO\n\n", i + 1);
        } else {
            printf("Instancia %i\nSIM\n\n", i + 1);
        }
    }

    return 0;
}
