 /*************************************************
 * Filename: ls.c
 * Author: Tomas Spoturno
 * Copyright: 
 * Disclaimer: This code is presented "as is" without any guarantees.
 * Details: General solution of system of linear equations (AX = B) using Gaussian elimination,
 *          note that this implementation has O(n^3) time complexity
 *************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void){
        
    //TODO: user input A and B
    const int n = 3;

    //matrix of coheficients declaration A (nxn)
    float A[n][n] = {
        {3, 2, 1}, 
        {1, 1, 5}
    };
    
    // colum vector declaration B(nx1), X(nx1)
    float X[n];
    float B[n] = {1, 1, 1}; 

    int i, j, k;

    //gaussian elimination (inefficient)
    for (k=1; k<n; k++){
        for(i=k+1; i<=n; i++){
           float pivot = A[i][k] / A[k][k]; 
           A[i][k] = 0;
           for(j=k+1 ;j<=n; j++){
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
}




