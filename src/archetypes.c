#include <archetypes.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "common.c"

int archetypes_print_matrix(int n, int m, double* data) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%0.3f\t", data[i * m + j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}


int archetypes_aa_init(int n, int m, int k, archetypes_t **archetypes) {
    *archetypes = (archetypes_t *) malloc(sizeof(archetypes_t));

    (*archetypes)->rss = INFINITY;

    (*archetypes)->n = n;
    (*archetypes)->m = m;
    (*archetypes)->k = k;

    (*archetypes)->archetypes = (double *) malloc(sizeof(double) * k * m);

    (*archetypes)->alpha = (double *) malloc(sizeof(double) * k * n);
    (*archetypes)->beta = (double *) malloc(sizeof(double) * n * k);

    return 0;
}

int archetypes_aa_compute(int n, int m, int k, double* data, archetypes_t **archetypes) {
    archetypes_aa_init(n, m, k, archetypes);
    archetypes_t *arch = *archetypes;

    // Init the coefficients
    matrix_init_coeficients(k, n, arch->alpha, 1);
    matrix_init_coeficients(m, k, arch->beta, 1);

    // Compute the archetypes
    matrix_matmul(k, n, m, arch->beta, data, arch->archetypes);

    return 0;
}

int archetypes_aa_free(archetypes_t **archetypes) {
    free((*archetypes)->archetypes);

    free((*archetypes)->alpha);
    free((*archetypes)->beta);

    free(*archetypes);

    return 0;
}
