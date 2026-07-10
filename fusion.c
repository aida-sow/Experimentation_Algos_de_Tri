#include <stdio.h>   
#include <stdlib.h>   
#include <time.h>     
 

/* ===========================================================
   FONCTION : fusion
   Role : fusionner deux sous-tableaux tries T[i..k] et T[k+1..j]
   en un seul sous-tableau trie T[i..j].
   =========================================================== */

void fusion(int T[], int i, int k, int j) {

    int Tab[150000] = {0};

    int s = i;      

    int t = k + 1; 

    int r = i;     

    while (s <= k && t <= j) {          // tant qu'il reste des elements des deux cotes

        if (T[s] <= T[t]) {             // si l'element de gauche est plus petit ou egal

            Tab[r] = T[s];              // on le copie dans Tab

            s++;                        // on avance le curseur gauche

            r++; 
            }                       // on avance le curseur d'ecriture

        else {                        // sinon, l'element de droite est plus petit

            Tab[r] = T[t];              // on le copie dans Tab

            t++;                        // on avance le curseur droit

            r++;                        // on avance le curseur d'ecriture
        }

    }                                    // fin de la boucle : un des deux cotes est epuise

    if (s > k) {                                 // si la partie gauche est entierement copiee

        for (int u = t; u <= j; u++) {           // on copie le reste de la partie droite

            Tab[r] = T[u];

            r++;
        }
    } else {                                      // sinon, c'est la partie droite qui est epuisee

        for (int u = s; u <= k; u++) {           // on copie le reste de la partie gauche

            Tab[r] = T[u];

            r++;
        }
    }

    for (int u = i; u <= j; u++) {   // on recopie le tableau temporaire trie

        T[u] = Tab[u];               // dans le tableau original T, a la bonne position
    }

   
}

/* ===========================================================
   FONCTION : tri_fusion (Merge Sort)
   Role : trier recursivement le tableau T entre les indices
   deb et fin, en coupant le tableau en deux a chaque appel.
   =========================================================== */


void tri_fusion(int T[], int deb, int fin) {

    if (deb < fin) {           

        int k = (deb + fin) / 2;  

        tri_fusion(T, deb, k); 

        tri_fusion(T, k + 1, fin);  
              
        fusion(T, deb, k, fin);           
    }                                      
}

/* ===========================================================
   FONCTION : afficherTableau
   Role : afficher les n premiers elements d'un tableau
   =========================================================== */

void afficherTableau(int T[], int n) {
    for (int i = 0; i < n; i++) {  
        printf("%d ", T[i]);        
    }
    printf("\n");                  
}

/* ===========================================================
   FONCTION : estTrie
   Role : verifier que le tableau est correctement trie
   (utile pour valider le resultat sur un grand tableau
   qu'on ne peut pas afficher entierement)
   =========================================================== */

int estTrie(int T[], int n) {
    for (int i = 0; i < n - 1; i++) {   
        if (T[i] > T[i + 1]) {         
            return 0;                  
        }
    }
    return 1;                          
}

/* ===========================================================
   FONCTION PRINCIPALE : main
   Role : generer un tableau de nombres aleatoires de taille
   TAILLE_MAX, le trier avec tri_fusion, puis verifier le resultat.
   =========================================================== */

int main() {
    srand(time(NULL));   // initialise le generateur de nombres aleatoires avec l'heure courante
    clock_t debut, fin;                            // deux "horodatages"
    double temps;                                  // durée en secondes (nombre à virgule)

    int n ;                          
    int T[150000] ;  
   
  printf ("entrer le nombre d/'elements du tableau ");
   scanf("%d",&n );

    for (int i = 0; i < n; i++) {                 // on remplit le tableau avec des valeurs aleatoires
        T[i] = rand() % 1000000;                  // valeurs entieres comprises entre 0 et 999 999
    }

    printf("Taille du tableau : %d elements\n\n", n);   // rappel de la taille du tableau

    printf("les elements AVANT tri :\n");
    afficherTableau(T, n);                      

    debut = clock();                                // top chrono : ON démarre

    tri_fusion(T, 0, n - 1);                       

    fin = clock();                                   // top chrono : ON arrête

    temps = (double)(fin - debut) / CLOCKS_PER_SEC; // calcul de la durée en secondes

   

    printf("\n les  elements APRES tri :\n");

    afficherTableau(T, n);                        // on affiche l'extrait trie pour verification visuelle

     printf("\nTemps d'execution du tri fusion : %f secondes\n", temps);

    if (estTrie(T, n)) {                            // verification complete et automatique du tri
        printf("\nLe tableau est correctement trie (%d elements).\n", n);
    } else {
        printf("\nERREUR : le tableau n'est pas trie.\n");
    }

    return 0;                                        // fin normale du programme
}