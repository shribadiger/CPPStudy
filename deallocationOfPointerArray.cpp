#include<iostream>
using  namespace std;

class Base {
   public:
    int value;
    Base() { cout<<"\n Base construction\n";}
    ~Base() { cout<<"\n Base destruction\n";}
};

int main() {
   Base* bp = new Base[10];
   delete[] bp;

   return 0;
}
