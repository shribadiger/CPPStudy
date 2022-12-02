#include<iostream>
using namespace std;
 

int sumOfDigit(int num)
{
   //base condition
   if(num<10)
      return num;
   int rem=num%10;
   return rem+sumOfDigit(num/10);
}

int main() {
   int num;
   cin>>num;
   cout<<"\n result: "<<sumOfDigit(num);
   return 0;
}
