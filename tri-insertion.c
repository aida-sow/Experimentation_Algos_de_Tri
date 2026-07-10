#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Remplir le tableau aléatoirement
void remplir_tableau(int T[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        T[i] = rand() % 100000;
    }
}

// Tri par insertion
void tri_insertion(int T[], int n)
{
    int i, j, cle;

    for(i = 1; i < n; i++)
    {
        cle = T[i];
        j = i - 1;

        while(j >= 0 && T[j] > cle)
        {
            T[j + 1] = T[j];
            j--;
        }

        T[j + 1] = cle;
    }
}

int main()
{
    int n;

    do
    {
        printf("Donner la taille du tableau (>=10000) : ");
        scanf("%d", &n);
    }
    while(n < 10000);


    int T[n];

    srand(time(NULL));

    remplir_tableau(T, n);

    clock_t debut = clock();

    tri_insertion(T, n);

    clock_t fin = clock();

    double temps = (double)(fin - debut) / CLOCKS_PER_SEC;

    printf("\nTri termine.\n");
    printf("Temps d'execution : %.6f secondes\n", temps);

    return 0;
}