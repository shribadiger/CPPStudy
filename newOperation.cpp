/*
 * This code is to illustate different memory allocation and management approaches
 */

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<memory>
using namespace std;

class MyClass  {
        public:
                int value;
                MyClass() {
                        std::cout<<"\n MyClass Constructor\n";
                }
                ~MyClass() {
                        std::cout<<"\n MyClass Destructor\n";
                }
                void printInfo() {
                        std::cout<<"\n Print Info function invoked\n";
                }
};

struct Data {
        Data() {
                cout<<"\n Construction of Data \n";
        }

        ~Data() {
                cout<<"\n Destruction of Data\n";
        }

        Data(const Data& ) {
                cout<<"\n Copy Initialization \n";
        }

        Data& operator=(const Data&) {
                cout<<"\n Copy Assignment \n";
        }

};

Data* foo() {
        return new Data;
}

unique_ptr<Data> goo() {
        return make_unique<Data>();
}




int main() {
        try {
                MyClass *obj1 = (MyClass*)malloc(sizeof(MyClass()));

                /* Placement new function which return same memory,
                 * the below comparision will helps for this*/
                MyClass *obj2 = new(obj1)MyClass();
                if(obj1 == obj2) {
                        std::cout<<"\n Obj1 == Obj2\n";
                }
                obj1->printInfo();
                obj2->printInfo();

                /* calling the destructor from the object*/
                obj2->~MyClass();
                free(obj1);

                /*Delete function actually deletes the memory from heap else it still holds
                 * good calls a printinfo fucntion in below line. if you call delete obj2, then
                 * it not allow to call printinfo function*/

                //delete obj2;
                //delete obj1;

                /* Trying to access the memory again after calling the destrctor */
                //obj1->printInfo();
                //obj2->printInfo();
        }
        catch(...) {
                std::cout<<"\n Exception Hanlded while allocation of memory\n";
                return -1;
        }

        cout<<"\n Enter the string white space separated\n";
        /* vector<string> vtr;
        string str;
        while(cin>>str) {
                vtr.push_back(str);
        }
        sort(vtr.begin(), vtr.end());

        string cat;
        for(auto & s:vtr) {
                cat += s+"+";
        }

        cout<<"n Final string: "<<cat<<"\n";*/

        /* unique_ptr usage for data*/
        Data* ptr1 = foo();
        cout<<"\n After calling foo and call goo\n";
        unique_ptr<Data> ptr2=goo();

        /* Perform a delete operation on same pointer*/
        delete ptr1;
        //below delete opeation will throw the code dump for double deletion of same pointer
        //delete ptr1;

        return 0;
}
