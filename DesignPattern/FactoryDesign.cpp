/*
 Checking the factory desgin patter implementation 
*/

#include<iostream>
#include<string>
using namespace std;

void Log(string str) {
   // Log printing Function
   cout<<"\n Log: "<<str<<"\n";
   
}
class Product {
   public:
      Product() { Log("Product constructor"); }
      virtual ~Product() { Log("Product destruction");}
};

int main() {
   // Testing the product object creation
   Product *prodObj = new Product();
   delete prodObj;
   return 0;
}
