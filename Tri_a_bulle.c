#include <stdio.h> /*bibliotheque standard contenant les fonctions de base*/
#include <stdlib.h> /*C'est la bibliotheque contenant les fonctions srand et rand*/
#include <time.h> /*bibliotheque contenant les outils neccessaires pour mesurer le temps d'execution*/

/* Procedure qui trie le tableau T de taille n avec l'algorithme du tri a bulle. */
void TriBulle (int n, int T[]) {
    int i, j, temp;

    /* A chaque passage, le plus grand element restant remonte vers la fin. */
    for (i = n - 1; i >= 1; i--) {
        /* Comparaison des elements voisins jusqu'a la partie deja triee. */
        for (j = 0; j < i; j++) {
            /* Si deux elements voisins sont dans le mauvais ordre, on les echange. */
            if (T[j] > T[j + 1]) {
                temp = T[j];
                T[j] = T[j + 1];
                T[j + 1] = temp;
            }
        }
    }
}

int main () {
    /* Initialisation du generateur de nombres aleatoires avec l'heure actuelle. */
    srand (time(NULL));

    int n;

    /* Lecture de la taille du tableau a trier. */
    printf ("Taille du tableau : ");
    scanf ("%d", &n);

    int tab[n], i;
    clock_t debut, fin;
    double temps;

    /* Remplissage du tableau avec des valeurs aleatoires entre 0 et n - 1. */
    for (i = 0; i < n; i++) 
        tab [i] = rand();

    /* Mesure du temps pris uniquement par le tri. */
    debut = clock();
    TriBulle (n, tab);
    fin = clock();

    /* Conversion du temps processeur en secondes. */
    temps = (double)(fin - debut) / CLOCKS_PER_SEC;

    /* Affichage du temps d'execution du tri. */
    printf("Temps d'execution : %f secondes\n", temps);
    return 0;
}
