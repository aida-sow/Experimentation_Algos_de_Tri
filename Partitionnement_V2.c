#include <stdio.h>

void Permuter (int tab[], int i, int j) {
    int temp;
    temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}

int PartitionnementV2 (int tab[], int i, int j) {
    int l = i + 1, k = j;
    while (l <= k) {
        while (tab[i] < tab[k]) {
            k = k - 1;
        }
        while (tab[i] >= tab[l]) {
            l = l + 1;
        }
        if (l < k) {
            Permuter (tab, l, k);
            k--;
            l++;
        }
    }
    Permuter (tab, i, k);
    return k;
}