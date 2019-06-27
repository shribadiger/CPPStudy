/*
    Program to check the async functionality for big production number
 */
#include<chrono>
#include<iostream>
#include<future>
#include<random>
#include<vector>
#include<numeric>

static const int MAX_NUMBER = 100000000;

long long getDotProduct(std::vector<int>& vector1, std::vector<int>& vector2) {

    auto future1 = std::async([&] {
        return std::inner_product(&vector1[0],
                                  &vector1[vector1.size()/4],
                                  &vector2[0],
                                  0LL);
    });

    auto future2 = std::async([&]{
        return std::inner_product(&vector1[vector1.size()/4],
                                  &vector1[vector1.size()/2],
                                  &vector2[vector1.size()/4],
                                  0LL);
    });

    auto future3 = std::async([&]{
        return std::inner_product(&vector1[vector1.size()/2],
                                  &vector1[vector1.size()*3/4],
                                  &vector2[vector1.size()/2],
                                  0LL);
    });
    auto future4 = std::async([&]{
        return std::inner_product(&vector1[vector1.size()*3/4],
                                  &vector1[vector1.size()],
                                  &vector2[vector1.size()*3/4],
                                  0LL);
    });

    return future1.get()+future2.get()+future3.get()+future4.get();
}

int main()
{
    std::cout<<"\n Main Program Execution Started\n";

    //Get the Random number from 0 to 100
    std::random_device seed;

    //call the generator function
    std::mt19937 engine(seed());

    //call distribution
    std::uniform_int_distribution<int> dist(0,100);

    //Fill the vector with all values
    std::vector<int> v1,v2;
    v1.reserve(MAX_NUMBER);
    v2.reserve(MAX_NUMBER);

    for(int i=0; i<MAX_NUMBER; i++) {
        v1.push_back(dist(engine));
        v2.push_back(dist(engine));
    }

    //measure the execution time
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
    std::cout<<"\n Getting call the getDotProduct(V1,V2) :"<<getDotProduct(v1,v2)<<"\n";
    std::chrono::duration<double> dur = std::chrono::system_clock::now() - start;
    std::cout<<"\n Parallel Execution : "<<dur.count() <<"\n";

    return 0;
}
