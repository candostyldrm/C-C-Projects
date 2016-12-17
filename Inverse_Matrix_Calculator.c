#include  <stdio.h>
#include <stdlib.h>
#include   <math.h>

void setInputMatrix(double *pMatrix, const int N);
double *setIdentityMatrix(const int N);
double *gaussElimination(double *pMatrix,const int N);
void printMatrix(double *pMatrix,const int N);
double determinant(double *pMatrix,const int N);
double *getMinor(double *mat, double *min,const int N, int i);


int main(void) {
    int N = 0;

    do{
        printf("Enter the value N, of NxN matrix: ");
        scanf("%d",&N);/**/
    }while( !(N>0&&N<11));

    double *pMatrix = malloc(sizeof(double)*N*N); // input matrix
    setInputMatrix(pMatrix,N);

    double det = determinant(pMatrix,N);
    printf("determinand: %.12lf\n",det);
    if(fabs(det) <= 0.000000000001){
        printf("The determinand is too small to calculate inverse of the matrix.\n");
        return -1;
    }

    pMatrix = gaussElimination(pMatrix,N);

    printf("Inverse of the matrix is:\n");
    printMatrix(pMatrix,N);

    return 0;
} /*end main*/


double determinant(double *mat, const int N) {
    double det = 0;
    double *minor = malloc(sizeof(double)*N*N);
    if(N == 1) {
        det = mat[0];
    }
    else if(N == 2) {
        det = mat[0]*mat[3]-mat[1]*mat[2];
    }
    else{
        int i = 0;
        for(i;i<N;i++){ // sutunları sayar
            getMinor(mat,minor,N,i);
            det += mat[0*N+i]*((i&1)==0?1:-1)*( determinant(minor,N-1) );
        }
     }
    return det;
}


double *getMinor(double *mat,double *min, const int N, int k) {
    int i = 0;
    int j = 0;
    int counter = 0;
    for(j ;j<N;j++){
        i = 0;
        for(i ;i<N;i++){
            if(!(j == 0 || i == k)){
               min[counter] = mat[j*N+i];
               counter++;
            }
        }
    }
}

void printMatrix(double *pMatrix,const int N) {
    int j = 0;
    for(j = 0;j<N;j++){// j for rows
        int i = 0;
        for(i = 0;i<N;i++){// i for columns
            printf("%6.3lf ",pMatrix[N*j+i]);
        }
        printf("\n");
    }
}


double *gaussElimination(double *pMatrix, const int N){
    int j = 0;
    double *const eye = setIdentityMatrix(N);

    for( j = 0;j < N;j++) {
        int i = 0;
        int swap = 0;
        double max = -0.1;

        for(i;i<N;i++){
            if( fabs(pMatrix[j*N+i]) > max){
                max = fabs(pMatrix[j*N+i]);
                swap = i;
            }
        }

        double tol = 0.000001;
        if(max <= tol  ) {
            printf("Tolerance value exceeded.\n");
            return 0;
        }

        if(swap!=j){
            int k = i;
            for(k;k<=N;k++){
                int temp = pMatrix[k*N+i];
                pMatrix[k*N+i] = pMatrix[k*N+swap];
                pMatrix[k*N+swap] = temp;
            }
        }
        i = 0;
        for(i;i<N;i++){
            if(i!=j){
                double k = 0;
                int m = 0;
                k = -1*pMatrix[i*N+j]/pMatrix[j*N+j]; // k deðeri alýnýyor

                for(m; m<N;m++){ // m iþlem yapýlacak sütunlarý temsil eder.
                    pMatrix[i*N+m] += k*pMatrix[j*N+m];
                    eye[i*N+m] += k*eye[j*N+m];
                }
            }
        }
    }
    j = 0;
    for(j;j<N;j++){
        double k = pMatrix[j*N+j];
        int i = 0;
        for(i;i<N;i++){
            pMatrix[j*N+i] /= k;
            eye[j*N+i] /= k;
        }
    }
    return eye;
}

void setInputMatrix(double *pMatrix,const int N){
    int j = 0;
    for(j = 0;j<N;j++){// j for rows
        int i = 0;
        for(i = 0;i<N;i++){// i for columns
            printf("Enter the element (%d,%d): ",j+1,i+1);
            scanf("%lf",&pMatrix[N*j+i]);
        }
    }
}

double *setIdentityMatrix(const int N){
    double *const eye=malloc(sizeof(double)*N*N);
    int j = 0;
    for(j = 0 ;j<N;j++){
        eye[j*N+j] = 1;
    }
    return eye;
}

