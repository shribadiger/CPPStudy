#include<iostream>
using namespace std;


//base class interfaces 
class Base {
   public:
	virtual int getBaseObject()=0;
        virtual void printBaseInformation()=0;
        virtual void reduceInformationSection()=0;
};

class Derived: public Base {
    public:
        int getDerivedInfo();
        void printDerivedInfo();
    private:
        int referenceCount;
};

Derived::Derived() {
     cout<<"\n Derived::Derived() invoke";
     referenceCount = 0;
}

int Derived::getDerivedInfo() {
    cout<<"\n Derived::getDerivedInfo() invoke";
    return referenceCount;
}

void Derived::printDerivedInfo() {
    cout<<"\n Derived::printDerivedInfo()  invoke";
    cout<<"\n Reference Count: "<<referenceCount;
}

int main() {
   cout<<"\n Main Invoke Function\n";
   Derived* object = new Derived();
   object->printDerivedInfo();
   return 0;
}
