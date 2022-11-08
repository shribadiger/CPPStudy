/* exmaple to showcase the data shared */
#include <iostream>
#include <vector>
#include <omp>
using namespace std;

void data_shared()
{
    int i = 10;
#pragma omp parallel for private(i)
    for (int index = 0; index < i; index++)
    {
        printf("Thread %d - i=%d", omp_get_thread_num(), i);
        i = 1000 + omp_get_thread_num();
    }

    printf("\n Final i: %d", i);
    int j = 20;
#pragma omp parallel for firstprivate(j)
    for (int index = 0; index < j; index++)
    {
        printf("Thread %d - j=%d", omp_get_thread_num(), j);
        i = 1000 + omp_get_thread_num();
    }

    printf("\n Final i: %d", j);
    int k = 30;
#pragma omp parallel for lastprivate(k)
    for (int index = 0; index < k; index++)
    {
        printf("Thread %d - k=%d", omp_get_thread_num(), k);
        i = 1000 + omp_get_thread_num();
    }

    printf("\n Final i: %d", j);
}
int main(int argc, char *argv[])
{
    // calling  function to illustrate
    data_shared();
}