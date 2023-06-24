#include "lib.h"
#include <math.h>

void printMat(double **mat, int row, int col) {
    for(int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            printf("%lf ", mat[i][j]);

        printf("\n");       
    }
}

int main() {
    double **vertexD, **vertexC, **vertexA, **vertexB, **vertexE, **vertexF; 
    double a = 10.0, b = 8.0, c = 16.0, d, theta, r, xco, yco;

    vertexD = vectorise(0.0);
    vertexC = vectorise(c);
    
    theta = asin(a / c);
    r = b / sin(theta);

    xco = r * cos(theta);
    yco = r * sin(theta);

    vertexA = createMat(xco, yco);

    vertexB = matSum(vertexA, vertexC);

    d = r * cos(theta);
    vertexE = vectorise(d);
    
    vertexF = sectionFormula(39.0, vertexA, vertexD);
    
    createDatsVertices(vertexA, "A.dat");
    createDatsVertices(vertexB, "B.dat");
    createDatsVertices(vertexC, "C.dat");
    createDatsVertices(vertexD, "D.dat");
    createDatsVertices(vertexE, "E.dat");
    createDatsVertices(vertexF, "F.dat");

    createDatsLengths(c, "c_len.dat");
    createDatsLengths(d, "d_len.dat");  
    createDatsLengths(r, "r_len.dat"); 
    createDatsLengths(theta, "theta.dat"); 

    return 0;
}
