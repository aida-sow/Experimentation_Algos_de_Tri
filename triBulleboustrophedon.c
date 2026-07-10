#include <stdio.h>

/*
 * Tri à bulle "boustrophédon" (ou tri cocktail).
 * Le principe (si j'ai bien compris) : au lieu de toujours parcourir
 * le tableau dans le même sens comme le tri à bulle classique, on fait
 * un coup vers la droite, puis un coup vers la gauche, et ainsi de
 * suite. Ça fait un peu comme le bœuf qui laboure un champ en
 * zigzag (d'où le nom "boustrophédon").
 *
 * Le tableau est utilisé ici avec des indices de 1 à n (comme dans le
 * pseudo-code), donc la case tab[0] ne sert à rien, on l'ignore juste.
 */
void triBulleBoustrophedon(int tab[], int n)
{
    // Déclaration des variables, rien de spécial ici
    int i, j, k, temp;
    int trie; // on utilise un int comme "booléen" (0 = faux, 1 = vrai), en C classique on n'a pas de type booléen direct

    trie = 0;    // faux au départ, comme ça on rentre dans la boucle au moins une fois
    j = n + 1;   // borne de droite, un peu au-delà du tableau (comme dans le pseudo-code)
    i = 0;       // borne de gauche

    // Tant que le tableau n'est pas trié ET qu'il reste des éléments à comparer
    while ((!trie) && (j > i))
    {
        trie = 1; // on suppose que c'est trié, on va le contredire si besoin plus bas

        // --- Passage vers la droite (comme un tri à bulle classique) ---
        for (k = i + 1; k <= j - 2; k++)
        {
            if (tab[k] > tab[k + 1])
            {
                // On échange tab[k] et tab[k+1]
                temp = tab[k];
                tab[k] = tab[k + 1];
                tab[k + 1] = temp;

                trie = 0; // on a fait un échange donc ce n'est pas encore trié
            }
        }

        j = j - 1; // on réduit la borne de droite, vu que le plus grand élément est maintenant tout à droite

        // --- Passage vers la gauche (le "retour" du boustrophédon) ---
        for (k = j - 1; k >= i + 2; k--)
        {
            if (tab[k] < tab[k - 1])
            {
                // On échange tab[k] et tab[k-1]
                temp = tab[k];
                tab[k] = tab[k - 1];
                tab[k - 1] = temp;

                trie = 0; // encore un échange, donc pas fini
            }
        }

        i = i + 1; // on augmente la borne de gauche, vu que le plus petit élément est maintenant tout à gauche
    }
}

// Petite fonction pour afficher le tableau, juste pour tester
void afficherTableau(int tab[], int n)
{
    int idx;
    for (idx = 1; idx <= n; idx++)
    {
        printf("%d ", tab[idx]);
    }
    printf("\n");
}

int main(void)
{
    // On met un élément "bidon" en tab[0] vu que le tableau commence à l'indice 1
    int tab[] = {0, 5, 2, 9, 1, 5, 6, 3, 8, 4, 7};
    int n = 10; // nombre d'éléments réels (sans compter tab[0])

    printf("Avant le tri : ");
    afficherTableau(tab, n);

    triBulleBoustrophedon(tab, n);

    printf("Apres le tri : ");
    afficherTableau(tab, n);

    return 0;
}