//
// Created by Aleix Alcacer Sales on 21/07/2020.
//

#include <stdlib.h>
#include <stdio.h>
int matrix_init_coeficients(int n, int m, double *data, int dim) {

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            data[i * m + j] = (double) rand() / (double) RAND_MAX;
        }
    }
    if (dim == 1) {
        for (int i = 0; i < n; ++i) {
            double accumulate = 0;
            for (int j = 0; j < m; ++j) {
                accumulate += data[i * m + j];
            }
            for (int j = 0; j < m; ++j) {
                data[i * m + j] /= accumulate;
            }
        }
    } else {
        for (int j = 0; j < m; ++j) {
            double accumulate = 0;
            for (int i = 0; i < n; ++i) {
                accumulate += data[i * m + j];
            }
            for (int i = 0; i < n; ++i) {
                data[i * m + j] /= accumulate;
            }
        }
    }

    return 0;
}

int matrix_matmul(int n, int k, int m, const double *a, const double *b, double *c) {

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            c[i * m + j] = 0;
            for (int l = 0; l < k; ++l) {
                c[i * m + j] += a[i * k + l] * b[l * m + j];
            }
        }
    }
    return 0;
}
