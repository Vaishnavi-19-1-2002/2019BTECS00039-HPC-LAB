#include <stdio.h>
#include <omp.h>

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10] = {0};
    int i, c = 5;
#pragma omp parallel for shared(a, b) firstprivate(c) num_threads(5)
    for (i = 0; i < 10; i++)
    {
        b[i] = a[i] + c;
    }
    printf("Vector Scalar Addition\n");
    for (int i = 0; i < 10; i++)
    {
        printf("b[%d] = %d\n", i, b[i]);
    }
    return 0;
}
