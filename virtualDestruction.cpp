#include<iostream>
using namespace std;

class Base 
{
  public:
      static int base_counter;
      Base() { base_counter++; cout<<"\n Base class construction\n"; }
      virtual ~Base() { base_counter--; cout<<"\n Base class Destruction\n"; }
       void foo() { cout<<"\n Base::foo() \n"; }
};

int Base::base_counter = 0;

class Derived: public Base {
    public:
       static int derived_counter;
       Derived() { derived_counter++; cout<<"\n Derived class construction\n"; }
       virtual ~Derived() { derived_counter--; cout<<"\n Derived class Destruction\n"; }
       void foo() { cout<<"\n Derived::foo() \n"; }
};

int Derived::derived_counter = 0;

int main() {
    Base* obj = new Base();
    Base* derObj = new Derived();
 
    cout<<"\n Base Counter : "<<Base::base_counter;
    cout<<"\n Derived Counter : "<<Derived::derived_counter;
    delete obj;
    delete derObj;
    cout<<"\n Base Counter : "<<Base::base_counter;
    cout<<"\n Derived Counter : "<<Derived::derived_counter;
    
    return 0;
}
