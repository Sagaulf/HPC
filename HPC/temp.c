#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sunperf.h>

// Run lib with ./matmult_c.studio nat m n k

void 
matmult_lib(int m,int n,int k,double **A,double **B,double **C) {
	// Use BLAS' DGEMM()
	
}


// Manual matrix multiplication
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

void 
matmult_nkm(int m,int n,int k,double **A,double **B,double **C) {
	int i, j, h;
	double sum = 0;	
		
	for (j = 0; j < n; j++) {
      	for (h = 0; h < k; h++) {
        	for (i = 0; i < m; i++) {
				sum = sum + A[i][h]*B[h][j];
        	}
        C[i][j] = sum;
        sum = 0;
      	}
    }
}

void 
matmult_kmn(int m,int n,int k,double **A,double **B,double **C) {
	int i, j, h;
	double sum = 0;	
		
	for (h = 0; h < k; h++) {
      	for (i = 0; i < m; i++) {
        	for (j = 0; j < n; j++) {
				sum = sum + A[i][h]*B[h][j];
        	}
        C[i][j] = sum;
        sum = 0;
      	}
    }
}

void 
matmult_knm(int m,int n,int k,double **A,double **B,double **C) {
	int i, j, h;
	double sum = 0;	
		
	for (h = 0; h < k; h++) {
      	for (j = 0; j < n; j++) {
        	for (i = 0; i < m; i++) {
				sum = sum + A[i][h]*B[h][j];
        	}
        C[i][j] = sum;
        sum = 0;
      	}
    }
}

void 
matmult_mkn(int m,int n,int k,double **A,double **B,double **C) {
	int i, j, h;
	double sum = 0;	
		
	for (i = 0; i < m; i++) {
      	for (h = 0; h < k; h++) {
        	for (j = 0; j < n; j++) {
				sum = sum + A[i][h]*B[h][j];
        	}
        C[i][j] = sum;
        sum = 0;
      	}
    }
}

void 
matmult_nmk(int m,int n,int k,double **A,double **B,double **C) {
	int i, j, h;
	double sum = 0;	
		
	for (j = 0; j < n; j++) {
      	for (i = 0; i < m; i++) {
        	for (h = 0; h < k; h++) {
				sum = sum + A[i][h]*B[h][j];
        	}
        C[i][j] = sum;
        sum = 0;
      	}
    }
}

