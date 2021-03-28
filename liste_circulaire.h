#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sorte.h"

struct liste {
    S element;
    struct liste* suivant;
};

typedef struct liste liste;
liste* liste_vide(void); // nouv
liste* liste_adjonction_queue(liste* l, S element); // adjq
liste* liste_suppression_tete(liste* l); // supt
S liste_tete(const liste* l); // tete
bool liste_est_vide(const liste* l); // vide
liste* liste_dcg(liste* l); // dcg
liste* liste_dcgk(liste* l, size_t k); // dcgk