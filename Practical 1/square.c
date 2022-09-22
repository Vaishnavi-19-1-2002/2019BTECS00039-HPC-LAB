#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
static int sum =0;
int main()
{
    #pragma omp parallel
    {
        for(int i=1; i<=100;i++)
        {
            if(i%4==omp_get_thread_num())
            {
                printf("thread No. %d Number : %d Square : %d\n", omp_get_thread_num(), i, i * i);  
                sum+=i*i;
        	}
        }
    }
    
        printf("Sum is %d \n",sum);
}
