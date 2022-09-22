#include <stdio.h>
#include <omp.h>

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i, c[10] = {0};
#pragma omp parallel for shared(a, b, c) num_threads(5)
    for (i = 0; i < 10; i++)
    {
        c[i] = b[i] + a[i];
    }
    printf("Vector Scalar Addition\n");
    for (int i = 0; i < 10; i++)
    {
        printf("c[%d] = %d\n", i, c[i]);
    }
    return 0;
}
