/*
There are five different ways to create threads in c++.
 Note: If we create the mutiple threads, then there is no guarantee
which one will start first execution. It difficult to synchronize the execution */
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;

// case 1: By using the function pointer

void thread_function_ptr(int input)
{
   cout << "\n Thread by function pointer\n";
   while (input-- > 0)
   {
      cout << "\n Input: " << input;
   }
}

// case 2: lamda function implementation

int main()
{
   // creating the thread
   std::thread t1(thread_function_ptr, 10);
   t1.join();
   return 0;
}
