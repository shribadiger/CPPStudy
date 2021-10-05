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
 Lamda is a simple way to define a functor. It will reduce the unwanted code from the functor. For STL Algorithms, Lamda functions will helps to use as call back functions.  Checking out the example to use the Lamda functions
 
 ```C++
 //How to use the lamda fucntions in STL  Algorithes,
int main() {
    std::vector<int>  dataList={1,2,3,4};
    std::transform(dataList.begin(), dataList.end(),dataList.begin(),[](const int value){
        return value+1;
    });
    for(int i=0;i<dataList.size();i++){
        cout<<"\t"<<dataList[i];
    }
}
```
Passing the lamda functions as function pointer only in following cases
```C++
int value_checker(const int value, int(*getValue)()){
    return getValue()+value;
}
int main() {
    auto get_value =[]() {
        return 1;
    };
    value_checker(3,get_value);
    return 0;
}
```
### 2. Function Pointers and Usage ###
it helps in interface programming. Creating the local callback pointer and pass to interface funciton. If we need a response or invoke back to callee. Then we can use the Function Pointers for such fucntionalities

```c++
#include<iostream>
using namespace std;
void printer(std::string input) {
    cout<<"\n Callback printing the sting: "<<input;
}

int main() {
    //creating the function pointer
    void (*function_pointer)(std::string input)=&printer;

    //calling the printer function from the funciton pointer
    (*function_pointer)("Hello Callback");

    return 0;
}
```
