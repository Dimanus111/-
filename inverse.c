#include <stdio.h>

void printMatrix(int n, double matrix[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int inverseMatrix(int n, double matrix[][n], double inverse[][n]) {
    double augmented[2 * n][2 * n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            augmented[i][j] = matrix[i][j];
            augmented[i][j + n] = (i == j) ? 1.0 : 0.0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (augmented[i][i] == 0.0) {
            int row = i + 1;
            while (row < 2 * n && augmented[row][i] == 0.0) {
                row++;
            }

            if (row == 2 * n) {
                printf("Матрица вырожденная. Обратная матрица не существует.\n");
                return 0;
            }

            for (int j = 0; j < 2 * n; j++) {
                double temp = augmented[i][j];
                augmented[i][j] = augmented[row][j];
                augmented[row][j] = temp;
            }
        }

        double pivot = augmented[i][i];

        for (int j = 0; j < 2 * n; j++) {
            augmented[i][j] /= pivot;
        }

        for (int row = 0; row < 2 * n; row++) {
            if (row != i) {
                double factor = augmented[row][i];

                for (int col = 0; col < 2 * n; col++) {
                    augmented[row][col] -= factor * augmented[i][col];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverse[i][j] = augmented[i][j + n];
        }
    }

    return 1;
}

int main() {
    int n;
    printf("Введите размерность матрицы (одно натуральное число): ");
    scanf("%d", &n);

    double matrix[n][n];
    printf("Введите элементы матрицы (каждый построчно, поочерёдно):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    double inverse[n][n];
    if (inverseMatrix(n, matrix, inverse)) {
        printf("Обратная матрица:\n");
        printMatrix(n, inverse);
    }

    return 0;
}