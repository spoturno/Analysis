#include <stdio.h>
#include <stdlib.h>

int main(void){

    //TODO: user input A and B
    int n;

    int i, j, k;

    printf("Enter size of matrix (nxn):");
    scanf("%d", &n);

    //matrix of coheficients declaration A (nxn)
    float A[3][3];
    
    //error of exceeding while declaring  A[n]
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            printf("A[%d][%d]:", i, j);
            scanf("%f", &A[i][j]);
        }
    }

    
    // colum vector declaration B(nx1), X(nx1)
    float X[3];
    float B[3] = {1, 1, 1}; 

    //gaussian elimination (inefficient)
    for (k=0; k<n-1; k++){
        for(i=k+1; i<n; i++){
           float pivot = A[i][k] / A[k][k]; 
           A[i][k] = 0;
           for(j=k+1 ;j<n; j++){
               A[i][k] -= pivot*A[k][j];
           }
        }
    }

    X[n-1] = B[n-1] / A[n-1][n-1];

    for (i=n-2; i>=0; i--){
        float sum = 0;
        for(k=i+1; k<n; k++){
            sum = A[i][j]*X[j];            
        }
        X[i] = (B[i] - sum) / A[i][i];
    }

    //print solutions
    printf("\n");
    for(i=0; i<n; i++){
        printf("X[%d] = %f\n", i, X[i]);
    }

     

}




