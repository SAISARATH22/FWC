#include <stdlib.h>
#include <stdio.h>

double** vectorise(double scalar);
double** createMat(double v1, double v2);
double** matSum(double **mat1, double **mat2);
double** scalarProduct(double scalar, double **mat);
double** sectionFormula(double ratio, double **a, double **b);
void createDatsVertices(double **mat, char *filename); 
void createDatsLengths(double len, char *filename); 

double** vectorise(double scalar) {
    double **vector = (double**) malloc(2 * sizeof(*vector)); 
    for(int i = 0; i < 2; i++)
        vector[i] = (double*) malloc(sizeof(vector));

    vector[0][0] = scalar * 1;
    vector[0][1] = 0;

    return vector;
}

double** createMat(double v1, double v2) {
    double **vector = (double**) malloc(2 * sizeof(*vector)); 
    for(int i = 0; i < 2; i++)
        vector[i] = (double*) malloc(sizeof(vector));

    vector[0][0] = v1;
    vector[0][1] = v2;

    return vector;
}

double** matSum(double **mat1, double **mat2) {
    double **sum = (double**)malloc(2 * sizeof(*sum));
    for(int i = 0; i < 2; i++) {
        sum[i] = (double*)malloc(sizeof(sum));
    }

    sum[0][0] = mat1[0][0] + mat2[0][0];
    sum[0][1] = mat1[0][1] + mat2[0][1];

    return sum;   
}

double** scalarProduct(double scalar, double **mat) {
    double **product = (double**)malloc(2 * sizeof(*product));
    for(int i = 0; i < 2; i++) {
        product[i] = (double*)malloc(sizeof(product));
    }

    product[0][0] = mat[0][0] * scalar;
    product[0][1] = mat[0][1] * scalar;

    return product;
}

double** sectionFormula(double ratio, double** a, double** b) {
    double **preres = matSum(scalarProduct(ratio, a), b);
    double **res = scalarProduct(0.025, preres);

    return res;
}

void createDatsVertices(double **mat, char *filename) {
    FILE *fp = fopen(filename, "w");

    fprintf(fp, "%lf", mat[0][0]);
    fprintf(fp, "\n");
    fprintf(fp, "%lf", mat[0][1]);       
    
    fclose(fp);
}

void createDatsLengths(double len, char *filename) {
    FILE *fp = fopen(filename, "w");

    fprintf(fp, "%lf", len);
    fclose(fp);
}
