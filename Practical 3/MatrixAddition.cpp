#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<algorithm>
int main()
{
    int tid;
    int i,j;
    int rows=250,cols=250;

    int a[250][250];
    int b[250][250];
    int c[250][250]={0};
    
    std::fill(*a, *a + 62500, 1);
    std::fill(*b, *b + 62500, 1);
    
    double start,end;
    start=omp_get_wtime();

    //Concurrent or parallel matrix addition

    for(int i=0;i<rows;i++)
    {
        #pragma omp parallel for reduction(+:c) num_threads(8)
        for(j=0;j<cols;j++)
        {
            printf("Thread %d executing this\n",omp_get_thread_num());
            c[i][j]=a[i][j]+b[i][j];
        }
    }

    printf("Values of Resultant Matrix C are as follows:\n");

    for(i=0;i<rows;i++) {
        for(j=0;j<cols;j++)
        {
            printf("Value of C[%d][%d]=%d\n",i,j,c[i][j]);
        }
    }
     
    end=omp_get_wtime();

    printf("\n-------------------------\n Time Parallel= %f",(end-start));
    return 0;
}