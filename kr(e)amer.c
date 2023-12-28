#include <stdio.h>
#include <stdlib.h>

double calculateDeterminant(int n, double A[][n]);

void solveLinearSystem(int n, double A[][n], double B[], double X[]) {
    double detA = calculateDeterminant(n, A);

    if (detA == 0) {
        printf("—истема уравнений не имеет единственного решени€.\n");
        return;
    }

    double temp[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (k == i) {
                    temp[j][k] = B[j];
                }
                else {
                    temp[j][k] = A[j][k];
                }
            }
        }

        X[i] = calculateDeterminant(n, temp) / detA;
    }
}

double calculateDeterminant(int n, double A[][n]) {
    if (n == 1) {
        return A[0][0];
    }

    double det = 0.0;
    int sign = 1;
    double temp[n - 1][n - 1];

    for (int k = 0; k < n; k++) {
        int i, j;

        for (i = 1; i < n; i++) {
            j = 0;

            for (int l = 0; l < n; l++) {
                if (l == k) {
                    continue;
                }

                temp[i - 1][j] = A[i][l];
                j++;
            }
        }

        det += sign * A[0][k] * calculateDeterminant(n - 1, temp);
        sign = -sign;
    }

    return det;
}

int main() {
    int n;
    printf("¬ведите размерность системы (одно натуральное число): ");
    scanf("%d", &n);

    double A[n][n];
    double B[n];

    printf("¬ведите элементы (построчно и поочерЄдно) матрицы A размером %dx%d:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("¬ведите элементы (построчно и поочерЄдно) вектора B размером %d:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &B[i]);
    }

    double X[n];
    solveLinearSystem(n, A, B, X);

    printf("–ешение системы:\n");
    for (int i = 0; i < n; i++) {
        printf("X[%d] = %lf\n", i, X[i]);
    }

    return 0;
}