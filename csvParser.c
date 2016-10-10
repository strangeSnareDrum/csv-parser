#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csvParser.h"

int getDataDimensions(char * fileName, int * m, int * n) {
    char c;
    FILE * fd = fopen(fileName,"r");

    if (fd != NULL) {
        printf("File %s successfully opened.\n", fileName);
    } else {
        printf("Open file failed, terminating.\n");
        return EXIT_FAILURE;
    }

    // count number of columns
    *m = 0;
    *n = 0;
    c = fgetc(fd);
    while (c != EOF) {
        if (c == DELIMITER)
            (*n)++;
        if (c == '\n') {
            (*m)++;
            break;
        }
        c = fgetc(fd);
    }
    (*n)++;

    // count number of rows
    c = fgetc(fd);
    while (c != EOF) {
        if (c == '\n')
            (*m)++;
        c = fgetc(fd);
    }

    fclose(fd);
    return EXIT_SUCCESS;
}

double ** initContainer(int m, int n) {
    int i;

    // allocate memory: m x n
    double **M = (double **) malloc(m * sizeof(double *));
    for (i = 0; i < m; i++) {
        M[i] = (double *) malloc(n * sizeof(double));
    }
    return M;
}

int parseData(char * fileName, double **M, int m, int n) {
    char c;
    char * cp;
    int i, j, k;
    char line[LINE_LENGTH_MAX];
    char * start, * stop;
    char temp[ELEMENT_LENGTH_MAX];

    FILE * fd = fopen(fileName,"r");
    if (fd != NULL) {
        ;
    } else {
        printf("Open file failed, terminating.\n");
        return EXIT_FAILURE;
    }

    // parse the data
    for (i = 0; i < m; i++) {
        cp = fgets(line, LINE_LENGTH_MAX, fd);

        for (j = 0; j < n - 1; j++) {
            stop = strchr(cp, DELIMITER);

            k = 0;
            temp[k++] = *cp++;
            while (cp != stop) {
                temp[k++] = *cp++;
            }
            temp[k] = '\n';
            M[i][j] = atof(temp);
            cp = ++stop;
        }
        M[i][j] = atof(cp);
    }
    return EXIT_SUCCESS;
}

void deinitContainer(double **M, int m) {
    int i;
    for (i = 0; i < m; i++) {
        free(M[i]);
    }
    free(M);
}
