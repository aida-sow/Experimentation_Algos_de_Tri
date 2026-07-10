#include <stdio.h>
#include <stdlib.h> // pour malloc (allocation dynamique) et rand()
#include <time.h>   // pour time(), sert à "varier" les nombres aléatoires à chaque exécution

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

// Remplit le tableau avec des valeurs aléatoires entre 1 et 100
void remplirAleatoirement(int tab[], int n)
{
    int idx;
    for (idx = 1; idx <= n; idx++)
    {
        tab[idx] = rand() % 100 + 1; // rand()%100 donne 0 à 99, on ajoute 1 pour avoir 1 à 100
    }
}

int main(void)
{
    int n;
    int *tab; // le tableau, on va l'allouer une fois qu'on connait n

    // On initialise le générateur aléatoire avec l'heure actuelle,
    // sinon on aurait toujours les mêmes "nombres aléatoires" à chaque exécution
    srand((unsigned int)time(NULL));

    printf("Combien d'elements voulez-vous dans le tableau ? ");
    scanf("%d", &n);

    // On alloue n+1 cases, vu que notre tableau utilise les indices de 1 a n (tab[0] inutilise)
    tab = (int *)malloc((n + 1) * sizeof(int));
    if (tab == NULL) // toujours verifier que malloc n'a pas echoue (manque de memoire par exemple)
    {
        printf("Erreur : impossible d'allouer la memoire.\n");
        return 1;
    }

    remplirAleatoirement(tab, n);

    printf("Avant le tri : ");
    afficherTableau(tab, n);

    triBulleBoustrophedon(tab, n);

    printf("Apres le tri : ");
    afficherTableau(tab, n);

    free(tab); // on libere la memoire allouee, sinon ca reste occupe pour rien

    return 0;
}