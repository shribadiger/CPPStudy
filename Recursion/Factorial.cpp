/* factorial of number*/
#include<iostream>
using namespace std;


int fact(int num) {
   if(num==1)
     return 1;
   return num*fact(num-1);
}

int main() {
   int num;
   cin>>num;
   cout<<"\n Fact: "<<fact(num);
   return 0;
}
