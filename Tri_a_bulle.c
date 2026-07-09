#include <stdio.h> /*bibliotheque standard contenant les fonctions de base*/
#include <stdlib.h> /*C'est la bibliotheque contenant les fonctions srand et rand*/
#include <time.h> /*bibliotheque contenant les outils neccessaires pour mesurer le temps d'execution*/

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
} /*Procedure du tri a bulle*/

int main () {
    srand (time(NULL));
    int n;
    printf ("Taille du tableau : ");
    scanf ("%d", &n);
    int tab[n], i;
    clock_t debut, fin;
    double temps;
    for (i = 0; i < n; i++) 
        tab [i] = rand() % n;
    debut = clock();
    TriBulle (n, tab);
    fin = clock();
    temps = (double)(fin - debut) / CLOCKS_PER_SEC;
    printf("Temps d'execution : %f secondes\n", temps);
    return 0;
}