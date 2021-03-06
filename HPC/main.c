#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sunperf.h>
#include <math.h>

#define min(a,b) (((a)<(b))?(a):(b))

void 
matmult_blk(int m, int n, int l, double **A, double **B, double **C, int bb){
	int i,j,k,ii,jj,kk;
	for ( i = 0; i < m ; i++){
		for ( j = 0; j < n; j++){
			C[i][j]=0;
		}
	}
	double r;
	
	// For block
	for(kk=0;kk<l;kk+=bb){
		// For block
		for(jj=0;jj<n;jj+=bb){
			for(i=0;i<m;i++){
				for(k=kk;k<min(kk+bb,l);k++){
					for(j=jj;j<min(jj+bb,n);j++){
						C[i][j]+=A[i][k]*B[k][j];
					}
				}
			}
		}
	}
}

void
matmult_blk0(int m,int n,int k,int bs,double **A,double **B,double **C) {
	// bs = block size
	int i, j, h, ii, jj, hh;
	double sum, r;	

	// Initialize C
	for (i = 0; i < m; i++) {
		for (j = 0; j<n; j++) {
			C[i][j] = 0.0;
		}
	}
	printf("now here");
	// C(m x n) = A(m x k) * B(k x n) 
	// increase by blocksize
	for (hh=0;hh<k;hh+=bs) {
		// increase by blocksize
		for (jj=0;jj<n;jj+=bs) {
			for (i=0;i<m;i++) {
				for (h=hh;h<min(hh+bs,k);j++) {
					r = A[i][h];
					for (j=jj;j<min(jj+bs,n);j++) {
						C[i][j]+=r*B[h][j];
					}
				}
			}
		}
	}
}

// Run lib with ./matmult_c.studio nat m n k
// Works and returns 0
void 
matmult_lib(int m,int n,int k,double **A,double **B,double **C) {
	// Use BLAS' DGEMM()
	double alpha = 1.0, beta = 0.0;
	cblas_dgemm(CblasRowMajor,CblasNoTrans,CblasNoTrans,m,n,k,alpha,A[0],k,B[0],n,beta,C[0],n);
}

// Manual matrix multiplication
// Works and returns 0
void 
matmult_nat(int m,int n,int k,double **A,double **B,double **C) {
	// move sum above
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

// Works and returns 0
void 
matmult_nmk(int m,int n,int k,double **A,double **B,double **C) {
	int i, j, h;
	double sum = 0;	
		
	for (j = 0; j < n; j++) {
      	for (i = 0; i < m; i++) {
        	for (h = 0; h < k; h++) {
				C[i][j]+=A[i][h]*B[h][j];
        	}
      	}
    }
}

// Segmentation fault
void 
matmult_knm(int m,int n,int k,double **A,double **B,double **C) {
	int i, j, h;
	double sum = 0;	
	
	for ( i = 0; i < m ; i++){
		for ( j = 0; j < n; j++){
			C[i][j]=0;
		}
	}

	for (h = 0; h < k; h++) {
      	for (j = 0; j < n; j++) {
        	for (i = 0; i < m; i++) {
				C[i][j]+=A[i][h]*B[h][j];
        	}
      	}
    }
}

void 
matmult_mkn(int m,int n,int k,double **A,double **B,double **C) {
	int i, j, h;
	double sum = 0;	
	
	for ( i = 0; i < m ; i++){
		for ( j = 0; j < n; j++){
			C[i][j]=0;
		}
	}

	for (i = 0; i < m; i++) {
      	for (h = 0; h < k; h++) {
        	for (j = 0; j < n; j++) {
				C[i][j]+=A[i][h]*B[h][j];
        	}
      	}
    }
}


void 
matmult_nkm(int m,int n,int k,double **A,double **B,double **C) {
	int i, j, h;
	double sum = 0;	
	
	for ( i = 0; i < m ; i++){
		for ( j = 0; j < n; j++){
			C[i][j]=0;
		}
	}
		
	for (j = 0; j < n; j++) {
      	for (h = 0; h < k; h++) {
        	for (i = 0; i < m; i++) {
				C[i][j]+= A[i][h]*B[h][j];
        	}
      	}
    }
}

void 
matmult_kmn(int m,int n,int k,double **A,double **B,double **C) {
	int i, j, h;
	double sum = 0;	
	for ( i = 0; i < m ; i++){
		for ( j = 0; j < n; j++){
			C[i][j]=0;
		}
	}
		
	for (h = 0; h < k; h++) {
      	for (i = 0; i < m; i++) {
        	for (j = 0; j < n; j++) {
				C[i][j]+=A[i][h]*B[h][j];
        	}
      	}
    }
}






