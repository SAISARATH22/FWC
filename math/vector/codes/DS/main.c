#include "lib.h"
#include <math.h>

int main() {
    double **D, **C, **A, **B, **E, **F;
    double a = 10.0, b = 8.0, c = 16.0, d, theta, r, xco, yco;

    D = vectorise(0.0, 0.0);
    node* vertexD = constructLinkedMatrix(D, 2, 1);
    createDatMat("D.dat", vertexD);
    
    C = vectorise(c, 0);
    node* vertexC = constructLinkedMatrix(C, 2, 1);
    createDatMat("C.dat", vertexC);

    theta = asin(a / c);
    r = b / sin(theta);
    xco = r * cos(theta);
    yco = r * sin(theta);

    A = vectorise(xco, yco);
    node* vertexA = constructLinkedMatrix(A, 2, 1);
    createDatMat("A.dat", vertexA);

    node *vertexB = vertexA;
    matSum(vertexB, vertexC);
    createDatMat("B.dat", vertexB);

    d = r * cos(theta);
    E = vectorise(d, 0.0);
    node* vertexE = constructLinkedMatrix(E, 2, 1);
    createDatMat("E.dat", vertexE);

    node* vertexF = constructLinkedMatrix(vectorise(xco, yco), 2, 1);
    sectionFormula(39.0, vertexF, vertexD);
    createDatMat("E.dat", vertexE);

    createDatsLengths("c_len.dat", c);
    createDatsLengths("d_len.dat", d);  
    createDatsLengths("r_len.dat", d); 
    createDatsLengths("theta.dat", theta); 
    
    return 0;
}