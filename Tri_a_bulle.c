#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void TriBulle (int n, int T[]) {
    int i, j, temp;
    for (i = n - 1; i >= 1; i--) {
        for (j = 0; j < i; j++) {
            if (T[j] > T[j + 1]) {
                temp = T[j];
                T[j] = T[j + 1];
                T[j + 1] = temp;
            }
        }
    }
}

int main () {
    srand (time(NULL));
    int tab[10000], i;
    clock_t debut, fin;
    double temps;
    for (i = 0; i < 10000; i++) 
        tab [i] = rand() % 10000;
    debut = clock();
    TriBulle (10000, tab);
    fin = clock();
    temps = (double)(fin - debut) / CLOCKS_PER_SEC;
    printf("Temps d'execution : %f secondes\n", temps);
    return 0;
}