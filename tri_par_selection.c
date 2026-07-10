#include <stdio.h>

// Fonction qui trie un tableau d'entiers par la méthode du tri par sélection
// tab : le tableau à trier
// n   : le nombre d'éléments du tableau
void triSelection(int tab[], int n) {
    int i, j, pg, temp;   // déclaration des variables : i et j pour les boucles, pg pour la position du plus grand, temp pour l'échange

    i = n - 1;            // i démarre à la dernière position du tableau (indice n-1 car en C on commence à 0)

    while (i > 0) {                     // tant qu'il reste plus d'un élément à trier
        pg = 0;                          // on suppose au départ que le plus grand élément est en position 0

        for (j = 1; j <= i; j++) {       // on parcourt le tableau du début jusqu'à la position i
            if (tab[j] > tab[pg]) {      // si l'élément courant est plus grand que celui repéré comme le plus grand
                pg = j;                  // alors on met à jour la position du plus grand élément
            }
        }                                 // fin du parcours : pg contient la position du plus grand élément trouvé

        temp = tab[pg];      // on sauvegarde temporairement le plus grand élément trouvé
        tab[pg] = tab[i];    // on met à sa place l'élément qui était à la position i
        tab[i] = temp;       // on place le plus grand élément trouvé à la position i (sa position définitive)

        i = i - 1;           // on réduit la zone à trier en passant à l'élément précédent
    }                        // fin de la boucle tant que
}

// Fonction utilitaire pour afficher le tableau (pas obligatoire mais pratique pour tester)
void afficherTableau(int tab[], int n) {
    for (int k = 0; k < n; k++) {   // on parcourt tout le tableau
        printf("%d ", tab[k]);      // on affiche chaque élément suivi d'un espace
    }
    printf("\n");                   // saut de ligne à la fin de l'affichage
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
        tab [i] = rand() % n;

    /* Mesure du temps pris uniquement par le tri. */
    debut = clock();
    TriBulle (n, tab);
    fin = clock();

    /* Conversion du temps processeur en secondes. */
    temps = (double)(fin - debut) / CLOCKS_PER_SEC;

    /* Affichage du temps d'execution du tri. */
    printf("Temps d'execution : %f secondes\n", temps);
    
    return 0;                         // fin du programme
}
