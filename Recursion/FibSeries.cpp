/* calling same function untill base condition reaches*/
#include<iostream>
#include<vector>
using namespace std;

int fib_series(int num) {

   //base condition
   if(num<2)
      return num;
   return fib_series(num-1)+fib_series(num-2);
}

int main() {
   int n=6;
   cout<<"\t"<<fib_series(n);
   return 0;
}
