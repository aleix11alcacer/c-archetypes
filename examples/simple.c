//
// Created by Aleix Alcacer Sales on 21/07/2020.
//

#include <archetypes.h>
#include <stdlib.h>


int main() {
    archetypes_t *archetypes;
    int n = 5;
    int m = 6;
    int k = 3;
    double data[n * m];
    for (int i = 0; i < n * m; ++i) {
        data[i] = (double) rand() / (double) RAND_MAX;
    }

    archetypes_aa_compute(n, m, k, data, &archetypes);

    archetypes_print_matrix(k, n, archetypes->alpha);
    archetypes_print_matrix(m, k, archetypes->beta);
    archetypes_print_matrix(k, m, archetypes->archetypes);

    archetypes_aa_free(&archetypes);
}