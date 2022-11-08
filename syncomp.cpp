/* Synchronozation example */
#include <iostream>
#include <omp>
#include <vector>
using namespace std;

void sync_example()
{
    // case 1: critical exmaple is already shown in previous example
    //  case 2: atomic operation approach
    printf("\n ATOMIC OPERATION");
    int sum = 0;
#pragma omp parallel for num_threads(128)
    for (int i = 0; i < 100; i++)
    {
#pragma omp atomic
        // if we  add  the atomic , sum will not execute 100 times and value will not become
        // 100, after adding to atomic, you see the output write atomic operations
        ++sum;
    }
    cout << "\n Sum " << sum;

    printf("\n Exmaple for order");
    // case 3: ordered appraoch
    std::vector<int> result;
#pragma omp parallel for
    for (int i = 0; i < 20; i++)
    {
        printf("\n %d", omp_get_thread_num());
        int j = i * i;
#pragma omp ordered
        // if we execute without ordered, vector will be having different order
        // with order pragma, order of index is maintained. try it out by commenting order pragma
        result.push_back(j);
    }

    printf("\n Pringint all elements from vector");
    for (auto val : result)
        printf("%d\t", val);
}

void single_master()
{
#pragma omp parallel
    {
// case 4: nowait approach
#pragma omp single nowait
        // check with and without nowait option.
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
    // calling the synchrnozation example
    sync_exmaple();
}