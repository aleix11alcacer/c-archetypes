#ifndef C_ARCHETYPES_ARCHETYPES_H
#define C_ARCHETYPES_ARCHETYPES_H

typedef struct archetypes_s {
    double rss;
    int n;
    int m;
    int k;
    double *archetypes;
    double *alpha;
    double *beta;
} archetypes_t;

int archetypes_aa_compute(int n, int m, int k, double* data, archetypes_t **archetypes);
int archetypes_aa_free(archetypes_t **archetypes);



int archetypes_print_matrix(int n, int m, double* data);

#endif //C_ARCHETYPES_ARCHETYPES_H
