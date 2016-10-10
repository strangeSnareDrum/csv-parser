#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH_MAX 100
#define ELEMENT_LENGTH_MAX 10

int main(int argc, char **argv)
{
    char fileName[] = "myFile.csv";
    int m, n, i, j;
    double **M;

    if (getDataDimensions(fileName, &m, &n)) {
        printf("Terminating\n");
        return EXIT_FAILURE;
    }

    printf("m = %i, n = %i\n", m, n);
    M = initContainer(m, n);
    if (M == NULL) {
        printf("NO! Terminating.\n");
        return EXIT_FAILURE;
    }

    if (parseData(fileName, M, m, n)) {
        printf("Not! Terminating.\n");
        return EXIT_FAILURE;
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%.2f, ", M[i][j]);
        }
        printf("\n");
    }

    deinitContainer(M, m);

    return 0;
}
