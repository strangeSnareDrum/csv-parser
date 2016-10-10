#ifndef CSVPARSER_H
#define CSVPARSER_H

// defines
#define LINE_LENGTH_MAX 100
#define ELEMENT_LENGTH_MAX 10
#define DELIMITER ','

int getDataDimensions(char * fileName, int * m, int * n);
double ** initContainer(int m, int n);
int parseData(char * fileName, double **M, int m, int n);
void deinitContainer(double **M, int m);

#endif // CSVPARSER_H
