#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// allocate a double-prec m x n matrix
double **
dmalloc_2d(int m, int n) {
	int i;
	if (m <= 0 || n <= 0) return NULL;
 	// Allocate memory
 	double **A = malloc(m * sizeof(double *));
 	if (A == NULL) return NULL;
 	A[0] = malloc(m*n*sizeof(double));
 	if (A[0] == NULL) {
 		free(A);
 		return NULL;
 	}
 	for (i = 1; i < m; i++) {
 		A[i] = A[0] + i * n;
 	}
 	return A;
}

// de-allocting memory, allocated with
// dmalloc_2d
void
dfree_2d(double **A) {
	free(A[0]);
	free(A);
}

int main(void) {
	const int m = 2, n = 2, k = 2;
	int i, j, h, count;
	double sum = 0;
	clock_t start_t, end_t, total_t;

	// Allocating memory
	printf("Allocating memory\n");
	double **A = dmalloc_2d(m,k);
	double **B = dmalloc_2d(k,n);
	double **C = dmalloc_2d(m,n);

	// Matrix A
	for (i=0; i<m; ++i) {
		for (j=0; j<k; ++j) {
			A[i][j] = 1;
		}
	}

	// Matrix B
	for(i=0; i<k; ++i) {
		for(j=0; j<n; ++j) {
			B[i][j] = 1;
			//printf("%f\n", B[i][j]);
		}
	}

	printf("Size of matrix: %d x %d \n", n, m);
	//Do operation
	start_t = clock();
	printf("Begin operation: %ld\n", start_t);

	for (i = 0; i < m; i++) {
      	for (j = 0; j < n; j++) {
        	for (h = 0; h < k; h++) {
				sum = sum + A[i][h]*B[h][j];
        	}
        C[i][j] = sum;
        sum = 0;
      	}
    }

	end_t = clock();
	printf("End: %ld\n", end_t);
	//total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	total_t = end_t - start_t;
	printf("Total time: %ld\n", total_t);

	// verify
	for (i = 0; i < m; i++) {
	 	for (j = 0; j < n; j++) {
	 		printf("C[%d][%d]: %f\n", i,j,C[i][j]);
	 	}
	}

	// Freeing up memory
	dfree_2d(A);
	dfree_2d(B);
	dfree_2d(C);

	return 0;
}
