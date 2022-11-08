#include <iostream>
using namespace std;

class Base1
{
public:
    Base1() { cout << "\n Base1::Base1()" << endl; }
    virtual void print1() { cout << "\n Base1::print1()" << endl; }
    virtual void print2() { cout << "\n Base1::print2()" << endl; }
};

class Base2
{
public:
    virtual void print2() { cout << "\n Base2::print2()" << endl; }
    virtual void print3() { cout << "\n Base2::print3()" << endl; }
    virtual void print4() { cout << "\n Base2::print4()" << endl; }
};

class Derived : public Base1, public Base2
{
public:
    void print2() override
    {
        cout << "\n Derived::print2()" << endl;
    }

    void print3() override
    {
        cout << "\n Derived::print3()" << endl;
    }

    virtual void print5()
    {
        cout << "\n Derived::print5()" << endl;
    }
};

class Derived1 : public Base1
{
public:
    string _name;
    Derived1() { cout << "\nDerived1::Derived1()" << endl; }
    string get_name() { return _name; }
    void set_name(string name) { _name = name; }
};

class Derived2 : public Base1
{
public:
    string _name;
    Derived2() { cout << "\nDerived2::Derived2()" << endl; }
    string get_name() { return _name; }
    void set_name(string input) { _name = input; }
};

class Derived3 : public Derived1, public Derived2
{
public:
    string _name;
    Derived3() { cout << "\nDerived3::Derived3()" << endl; }
    string get_name() { return _name; }
    void set_name(string input) { _name = input; }
};

int main()
{
    Base2 *base2Ptr = new Derived();
    base2Ptr->print2();

    void *ptr = base2Ptr;
    Base2 *convtPtr = static_cast<Base2 *>(ptr); // Its working, sometimes its a undefined behavior
    convtPtr->print2();

    // checking subobject level
    Derived3 obj;
    obj.set_name("Derived3");
    cout << "\n Name : " << obj.get_name() << endl;
    return 0;
}