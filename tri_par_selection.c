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

// Programme principal pour tester l'algorithme
int main() {
    int tab[] = {5, 2, 9, 1, 7, 3};   // exemple de tableau à trier
    int n = 6;                        // nombre d'éléments dans le tableau

    printf("Tableau avant tri : ");
    afficherTableau(tab, n);          // on affiche le tableau avant le tri

    triSelection(tab, n);             // on appelle la fonction de tri

    printf("Tableau après tri : ");
    afficherTableau(tab, n);          // on affiche le tableau après le tri

    return 0;                         // fin du programme
}