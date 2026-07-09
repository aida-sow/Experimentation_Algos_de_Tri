#include <stdio.h>

/* Echange les valeurs situees aux positions i et j dans le tableau. */
void Permuter (int tab[], int i, int j) {
    int temp;
    temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}

/* Partitionne le tableau entre les indices i et j autour du pivot tab[i]. */
int PartitionnementV2 (int tab[], int i, int j) {
    /* l parcourt le tableau depuis la gauche, k depuis la droite. */
    int l = i + 1, k = j;

    /* On cherche les elements mal places par rapport au pivot. */
    while (l <= k) {
        /* Deplacement de k vers la gauche tant que l'element est superieur au pivot. */
        while (tab[i] < tab[k]) {
            k = k - 1;
        }

        /* Deplacement de l vers la droite tant que l'element est inferieur ou egal au pivot. */
        while (tab[i] >= tab[l]) {
            l = l + 1;
        }

        /* Si les deux indices ne se sont pas croises, on echange les elements mal places. */
        if (l < k) {
            Permuter (tab, l, k);
            k--;
            l++;
        }
    }

    /* Placement du pivot a sa position definitive dans la partition. */
    Permuter (tab, i, k);

    /* Retourne l'indice final du pivot. */
    return k;
}
