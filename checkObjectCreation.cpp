#include <iostream>
#include <memory>
using namespace std;

class Base
{
public:
    virtual void f();
};

class Derived : public Base
{
};

void f()
{
    std::unique_ptr<Base> b = std::make_unique<Derived()>();
}

int main()
{
    Base *obj = new Base();
    obj->f();
    return 0;
}
