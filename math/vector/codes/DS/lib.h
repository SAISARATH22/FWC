#include <stdio.h>
#include<stdlib.h>

typedef struct node {
    double data;
    struct node *right, *down;
}node;
 
double** vectorise (double v1, double v2);
node* newNode(double d);
void display(node* head);
void matScalarProduct(node* h1, double scalar);
void matSum(node* h1, node* h2);
void sectionFormula(double ratio, node* m1, node* m2);
node* constructLinkedMatrix(double** mat, int m, int n);

double** vectorise (double v1, double v2) {
    double** vector = (double**)malloc(2 * sizeof(*vector));
    for(int i = 0; i < 2; i++)
        vector[i] = (double*)malloc(2 * sizeof(vector));

    vector[0][0] = v1;
    vector[1][0] = v2;

    return vector;
}

node* newNode(double d) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = d;
    temp->right = temp->down = NULL;
    return temp;
}

void display(node* head) {
    node *rp, *dp = head;

    while (dp) {
        rp = dp;       
        while (rp) {
            printf("%lf ",rp->data);
            rp = rp->right;
        }
        printf("\n");
        dp = dp->down;
    }
}

void matScalarProduct(node* h1, double scalar) {
    node *rp1, *dp1 = h1;
    
    while(dp1) {
        rp1 = dp1;
        while(rp1) {
            rp1->data = rp1->data * scalar;    
            rp1 = rp1->right;            
        }
        dp1 = dp1->down;        
    }
}

void matSum(node* h1, node* h2) {
    node *rp1, *rp2, *dp1 = h1, *dp2 = h2;
    
    while(dp1 && dp2) {
        rp1 = dp1;
        rp2 = dp2;
        while(rp1 && rp2) {
            rp1->data = rp1->data + rp2->data;    
            rp1 = rp1->right;
            rp2 = rp2->right;
        }
        dp1 = dp1->down;
        dp2 = dp2->down;
    }
}

void sectionFormula(double ratio, node* m1, node* m2) {
    matScalarProduct(m1, ratio);
    matSum(m1, m2);
    matScalarProduct(m1, 0.025);
}
 
node* constructLinkedMatrix(double** mat, int m, int n) {
    node* mainhead = NULL; 
    node* head[m];
    node *righttemp, *newptr;
 
    for (int i = 0; i < m; i++) { 
        head[i] = NULL;
        for (int j = 0; j < n; j++) {
            newptr = newNode(mat[i][j]); 
            if (!mainhead)
                mainhead = newptr; 
            if (!head[i])
                head[i] = newptr;
            else
                righttemp->right = newptr; 
            righttemp = newptr;
        }
    }
 
    for (int i = 0; i < m - 1; i++) { 
        node *temp1 = head[i], *temp2 = head[i + 1];
 
        while (temp1 && temp2) { 
            temp1->down = temp2;
            temp1 = temp1->right;
            temp2 = temp2->right;
        }
    } 
    return mainhead;
}

void createDatMat(char* filename, node* head) {
    FILE *fp = fopen(filename, "w");
    node *rp, *dp = head;
    
    while (dp) {
        rp = dp;       
        while (rp) {
            fprintf(fp, "%lf" ,rp->data);
            rp = rp->right;
        }
        fprintf(fp, "\n");
        dp = dp->down;
    }
}

void createDatsLengths(char *filename, double len) {
    FILE *fp = fopen(filename, "w");

    fprintf(fp, "%lf", len);
    fclose(fp);
}
 
