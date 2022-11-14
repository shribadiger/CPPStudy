/*
    Code for finding the lazy initialization and early 
    initialization methods in C++.
 */
#include<iostream>
#include<chrono>
#include<future>

int main() {
    std::cout<<"\n Started Lazy Initialization Scenario \n";

    //Begin of the Lazy Initialization time
    auto begin = std::chrono::system_clock::now();

    //creating the lamda function for lazy initialization
    auto async_lazy = std::async(std::launch::deferred,[] {
        return std::chrono::system_clock::now();
    });

    //creating the lamda function for eager initialization
    auto async_eager= std::async(std::launch::async,[] {
        return std::chrono::system_clock::now();
    });

    std::this_thread::sleep_for(std::chrono::seconds(1));

    auto lazy_start = async_lazy.get() - begin;
    auto eager_start = async_eager.get() - begin;

    auto lazy_duration = std::chrono::duration<double>(lazy_start).count;
    auto eager_duration = std::chrono::duration<double>(eager_start).count;

    std::cout<<"\n ASYNC LAZY TIME : "<< lazy_duration<<"\n";
    std::cout<<"\n ASYNC EAGER TIME : "<<eager_duration<<"\n";
    return 0;
}
