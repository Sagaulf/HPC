#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void 
matmult_nat(int m,int n,int k,double **A,double **B,double **C) {
	int i, j, h;
	double sum = 0;	
		
	for (i = 0; i < m; i++) {
      	for (j = 0; j < n; j++) {
        	for (h = 0; h < k; h++) {
				sum = sum + A[i][h]*B[h][j];
        	}
        C[i][j] = sum;
        sum = 0;
      	}
    }
}
