# Interview Preparation #

 ### 1.Lamda Expression: ###
 Lamda function works similar way like functor in c++. Its very good feature introduced in C++11. It removes the lots of boiler plate code from functor.
 ```c++
 #include<iostream>
#include<assert.h>
using namespace std;

//Functor for adding the value
class add_one {
    public:
        int operator() (const int val) const {
            return val+1;
        }
};

class addition {
    public:
        addition(int val):_value(val) { }
        int operator() (int input) { return input+_value;}
    private:
        int _value;
};

// Lamda expression to add value to 1
auto plus_one=[data=1](const int value){
    return value+data;
};

int main() {
    add_one my_adding_functor;
    assert(my_adding_functor(2) ==3);

    //Calling by different value
    addition addOne(1);
    assert(addOne(4) ==5 );
    addition addTwo(2);
    assert(addTwo(4) == 6 );
    assert(plus_one(4)==5);
    return 0;
}
 ```
 Lamda is a simple way to define a functor. It will reduce the unwanted code from the functor. 
