/*
Illustate some specific functionality about omp
*/
#include <iostream>
#include <omp>
using namespace std;
void print_omp()
{
#pragma omp parallel
    {
#pragma omp critical
        cout << "\n OpenMP" << omp_get_thread_num() << "\n"
             << omp_get_num_threads() << endl;
    }
}

void for_loop()
{
    const int length = 1024 * 1024 * 64;
    float *a = new float[length];
    float *b = new float[length];
    float *c = new float[length];
    float *result = new float[length];
#pragma omp parallel for
    for (int i = 0; i < length; i++)
    {
        result[i] = a[i] + b[i] * erff(c[i]);
    }

    delete[] a;
    delete[] b;
    delete[] c;
    delete[] result;
}

void sections()
{
#pragma omp parallel sections
    {
#pragma omp section
        // limitation, size_t is can not be used in omp secitons for indexing the elements
        {
            for (int i = 0; i < 1000; i++)
            {
                cout << "\t" << i;
            }
        }
#pragma omp seciton
        {
            for (int i = 0; i < 100; i++)
            {
                cout << static_cast<char>('a' + (i % 26)); // print a to z repeatedly
            }
        }
    }
}

void single_master()
{
#pragma omp parallel
    {
#pragma omp single
        {
            printf("getther some input from external system= %d", omp_get_thread_num());

            printf(" in parallel on %d", omp_get_thread_num());
#pragma omp master
            printf("\n Output on master : %d", omp_get_thread_num());
        }
    }
}
int main(int argc, char *argv[])
{
    // main execution
    print_omp();
    // Approach 1: for loop parallelizm
    for_loop();
    // Approach 2: sections
    sections();
    // approach 3/4: single and master
    getchar();
    return 0;
}