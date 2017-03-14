#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH_MAX 100
#define ELEMENT_LENGTH_MAX 11

int main(int argc, char **argv)
{
    char fileName[] = "myFile.csv";
    int m, n;    // m: number of rows, n: number of columns.
    double **M;  // M: an m x n matrix to be filled with numbers.
    int i, j;

    // Get the dimensions of the csv data.
    if (getDataDimensions(fileName, &m, &n)) {
        printf("Terminating\n");
        return EXIT_FAILURE;
    }

    // Allocate memory for M.
    printf("m = %i, n = %i\n", m, n);
    M = initContainer(m, n);
    if (M == NULL) {
        printf("NO! Terminating.\n");
        return EXIT_FAILURE;
    }

    // Parse the csv file and store the numbers in M.
    if (parseData(fileName, M, m, n)) {
        printf("Not! Terminating.\n");
        return EXIT_FAILURE;
    }

    // Print the data.
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%.2f, ", M[i][j]);
        }
        printf("\n");
    }

    // Release memory.
    deinitContainer(M, m);

    return 0;
}
