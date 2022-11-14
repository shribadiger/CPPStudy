#include "stdafx.h"

void intrinsics()
{
    auto a = _mm_set_ps(1, 2, 3, 4);
    auto b = _mm_set_ps(4, 3, 2, 1);
    auto result = _mm_add_ps(a, b); // getting the addition value

    // if we wish to get the first indexed values
    float f = result.m128_f32[0]; // it will give first value after addition
}

void simple_mad(float *a, float *b, float *c, float *result, int length)
{
    for (size_t i = 0; i < length; i++)
    {
        result[i] = a[i] * b[i] + c[i];
    }
}
void optimization()
{
    const int length = 1024 * 1024 * 64;
    float *a = new float[length];
    float *b = new float[length];
    float *c = new float[length];
    float *result = new float[length];

    mt19937_64 rng(random_device{}());
    uniform_real_distribution<float> dist(0, 1);

    for (size_t i = 0; i < length; i++)
    {
        a[i] = dist(rng);
        b[i] = dist(rng);
        c[i] = dist(rng);
    }

    // let call the custom simple_mad() funcltion
    // to find out the time calculation

    using std::namespace ::chrono;
    auto begin = high_resolution_clock::now();
    simple_mad(a, b, c, resutl, length);
    auto end = high_resolution_clock::now();
    cout << "\n Time : " << duration_cast<milliseconds>(end - begin);
    // delete the allocated space
    delete[] a;
    delete[] b;
    delete[] c;
    delete[] result;
}