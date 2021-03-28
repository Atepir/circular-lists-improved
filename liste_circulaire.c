/*
 * @Author: nongma.sorgho 
 * @Date: 2021-03-28 11:16:39 
 * @Last Modified by: nongma.sorgho
 * @Last Modified time: 2021-03-28 13:22:35
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
        l->suivant = ln;
        ln->suivant = l;
        ln->element = element;
    }
    return l;
} // adjq

liste* liste_suppression_tete(liste* l){
    // pre : !liste_est_vide(l)
    if (l->suivant){
        l->element = l->suivant->element;
        l->suivant = l->suivant->suivant;
    }else{
        free(l);
        l = liste_vide();
    }
    return l;
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
    liste* lc = malloc(sizeof(liste));
    lc = l;
    while (lc->suivant != l){
        lc = lc->suivant;
    }
    S tmp = l->element;
    l->element = lc->element;
    lc->element = tmp;
    return l;
} // dcg

liste* liste_dcgk(liste* l, size_t k){
    // pre : !liste_est_vide(l)
    for (int i=0; i<k; i++){
        l = liste_dcg(l);
        l = l->suivant;
    }
    return l;
} // dcgk

void print_lst(liste* l){
    liste *lc;
    lc = l;
    while (lc->suivant != l){
        printf("%ld ", liste_tete(lc));
        lc = lc->suivant;
    }
    printf("%ld ", liste_tete(lc));
    printf("\n");
}

int main(){
    // creating an empty list
    liste* l;
    l = liste_vide();
    // filling the empty list with 5
    l = liste_adjonction_queue(l, 5);
    print_lst(l);

    // filling the empty list with 3
    l = liste_adjonction_queue(l, 3);
    print_lst(l);
    
    /*
    // filling the empty list with n values
    S n = 5;
    for (S i=0; i<n; i++) l = liste_adjonction_queue(l, i*i);
    print_lst(l);
    
    // deleting m values from l
    int m = 2;
    for (int i=0; i<m; i++) l = liste_suppression_tete(l);
    print_lst(l);
    
    // shift of the head to the tail
    l = liste_dcg(l);
    print_lst(l);

    // shift of the k first from head to tail
    int k = 2;
    l = liste_dcgk(l, k);
    print_lst(l);
    */
}