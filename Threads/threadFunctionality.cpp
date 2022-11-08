#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;

ull oddSum = 0;
ull evenSum = 0;

void findEven(ull start, ull end) {
   for(ull i=start;i<end;i++) {
     if((i & 1) == 0) evenSum++;
   }
}

void findOdd(ull start, ull end) {
   for(ull i=start;i<end; i++) {
       if((i&1) ==1) oddSum++;
   }
}

int main() {
   ull start =  0;
   ull end = 1900000000;
   auto startTime = high_resolution_clock::now();

   std::thread t1(findEven,start,end);
   std::thread t2(findOdd,start,end);

   //joinging the thread
   t1.join();
   t2.join();

  // findOdd(start,end);
   //findEven(start,end);

   auto stopTime = high_resolution_clock::now();

   auto duration = duration_cast<microseconds>(stopTime - startTime);

   cout<<"\n Odd Sum : "<<oddSum;
   cout<<"\n Even Sum : "<<evenSum;
 
   cout<<"\n Execution Time(sec) : "<<duration.count()/1000000<<endl;
   return 0;
} 
