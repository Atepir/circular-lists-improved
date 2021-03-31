/*
 * @Author: nongma.sorgho 
 * @Date: 2021-03-28 11:16:39 
 * @Last Modified by: nongma.sorgho
 * @Last Modified time: 2021-03-31 13:22:35
 */

#include <stdlib.h>
#include "liste_circulaire.h"

liste* liste_vide(void){
    liste* listenouv = malloc(sizeof(liste));
    return listenouv;
} // listenouv

liste* liste_adjonction_queue(liste* l, S element){
    if (liste_est_vide(l)){
        l->element = element;
        l->suivant = l;
    }else{
        liste* ln = liste_vide();
        ln->suivant = l;
        ln->element = element;
        liste* lc = l;
        while(lc->suivant != l){
            lc = lc->suivant;
        }
        lc->suivant = ln;
    }
    return l;
} // adjq

liste* liste_suppression_tete(liste* l){
    // pre : !liste_est_vide(l)
    liste* lc = l;
    while (lc->suivant != l){
        lc = lc->suivant;
    }
    lc->suivant = l->suivant;
    free(l);
    lc = lc->suivant;
    return lc;
} // supt

S liste_tete(const liste* l){
    // pre : !liste_est_vide(l)
    return l->element;
} // tete

bool liste_est_vide(const liste* l){
    if (!l->suivant) return 1;
    return 0;
} // vide

liste* liste_dcg(liste* l){
    // pre : !liste_est_vide(l)
    return l->suivant;
} // dcg

liste* liste_dcgk(liste* l, size_t k){
    // pre : !liste_est_vide(l)
    for (int i=0; i<k; i++){
        l = liste_dcg(l);
    }
    return l;
} // dcgk

void print_lst(liste* l){
    // pre : !liste_est_vide(l)
    liste *lc = l;
    printf("\033[0;31m"); // print in red
    printf(">>> ");
    printf("\033[0m"); // back to default
    printf("%ld ", liste_tete(lc));
    while (lc->suivant != l){
        lc = lc->suivant;
        printf("%ld ", liste_tete(lc));
    }
    printf("\n");
}

int main(){
    // creating an empty list
    liste* l;
    l = liste_vide();

    // filling the empty list with v at tail
    S v = 5;
    l = liste_adjonction_queue(l, v);
    printf("\033[0;32m");
    printf(">>> Ajout %ld : \n", v);
    printf("\033[0m");
    print_lst(l);

    // filling the list with v at tail
    v = 3;
    l = liste_adjonction_queue(l, v);
    printf("\033[0;32m");
    printf(">>> Ajout %ld : \n", v);
    printf("\033[0m");
    print_lst(l);

    // filling the list with v at tail
    v = 90;
    l = liste_adjonction_queue(l, v);
    printf("\033[0;32m");
    printf(">>> Ajout %ld : \n", v);
    printf("\033[0m");
    print_lst(l);
    
    // filling the list with n values at tail
    S n = 5;
    for (S i=0; i<n; i++) l = liste_adjonction_queue(l, i);
    printf("\033[0;32m");
    printf(">>> Ajout des nombres de 0 a %ld : \n", n-1);
    printf("\033[0m");
    print_lst(l);

    // deleting at head a first value from list
    l = liste_suppression_tete(l);
    printf("\033[0;32m");
    printf(">>> Suppression de la tete : \n");
    printf("\033[0m");
    print_lst(l);

    // deleting at head a second value from list
    l = liste_suppression_tete(l);
    printf("\033[0;32m");
    printf(">>> Suppression de la tete : \n");
    printf("\033[0m");
    print_lst(l);
    
    // deleting m values from l at head
    int m = 2;
    for (int i=0; i<m; i++) l = liste_suppression_tete(l);
    printf("\033[0;32m");
    printf(">>> Suppression des %d premiers elements a partir de la tete : \n", m);
    printf("\033[0m");
    print_lst(l);
    
    // shifting the head to the tail
    l = liste_dcg(l);
    printf("\033[0;32m");
    printf(">>> Decalage de la tete a la queue : \n");
    printf("\033[0m");
    print_lst(l);

    // shift of the k first from head to tail
    int k = 2;
    l = liste_dcgk(l, k);
    printf("\033[0;32m");
    printf(">>> %d decalages de la tete a la queue : \n", k);
    printf("\033[0m");
    print_lst(l);

    // is list empty ?
    printf("\033[0;32m");
    printf(">>> La liste est-elle vide ? : \n");
    printf("\033[0m");
    printf("\033[0;31m");
    printf(">>> ");
    printf("\033[0m");
    printf("%s\n", liste_est_vide(l) ? ("Oui") : ("Non"));

    // list head
    printf("\033[0;32m");
    printf(">>> La tete de la liste : \n");
    printf("\033[0m");
    printf("\033[0;31m");
    printf(">>> ");
    printf("\033[0m");
    printf("%ld\n",liste_tete(l));
}