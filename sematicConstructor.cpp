/*
 * This is Program to illustate about the sematic constructor functionality
 * Following the sematic constructor section in c++ inside Book.
 * Refer the book for more clarity
 */
#include<iostream>
#include<string>
#include<stdlib.h>
#include<string.h>
using namespace std;

class Node {
        public:
                Node(int inVal) {
                        std::cout<<"\n Node Parameterized constructor\n";
                        value = inVal;
                }

                int value;
};

class Base {
        public:
                //Default constructor which initilize all
                //values to Zero
                Base() {
                        std::cout<<"\n Base Constructor \n";
                }
                int val;
                Base* basePtr;
};

class Derived : public Base {
        public:
                int derivedInt;
};

class OuterNode {
        /* this class is not defined any default constructor and
         * contains the member of the Node class */
        public:
                int OuterInt;
                Node nodeObj;
};

//sythesize the base class if it has the virtual function
class Widget {
        public:
                virtual void flip() =0 ; // pure virtual function
};

// class bell is inherit the Widget
class Bell : public Widget {
        public:
                void flip() {
                        std::cout<<"\n Bell flip\n";
                }
};

class Whisle : public Widget {
        public:
                void flip() {
                        std::cout<<"\n Whisle flip\n";
                }
};

//global function to call the flip operation
void flip(Widget& widget) {
        widget.flip();
}

/* verify the functionality of constructor in virtual derivations */
class X {
        public:
                X() { std::cout<<"\n X constructor\n"; }
                int i;
};

class A: public virtual X {
        public:
                A() { std::cout<<"\n A constructor\n"; }
                int j;
};

class B: public virtual X {
        public:
                B() { std::cout<<"\n B constructor\n"; }
                double k;
};

class C : public A, public B {
        public:
                C() { std::cout<<"\n C constructor\n"; }
                int l;
};

void setter(A* pa) {
        std::cout<<"\n Global value setter function\n";
        pa->i=1000; //--> error: read-only member
}

/*
 * Understanding of the copy-constructor functionality
 */
class User {
        public:
                User() {
                        std::cout<<"\n User Construction\n";
                }

                User(User& obj) {
                        std::cout<<"\n User Copy-Constructor\n";
                        value=obj.value;
                }

                /* trying to send extra params*/
                User(User& obj, int extraInt) {
                        std::cout<<"\n User Copy-Constructor with exta Int\n";
                        value=extraInt;
                }
                int value;
};

/*
 * Understanding of the default memberwise initialization
 */

class Number {
        public:
                int _number;
                void setNumber(int val) {
                        _number=val;
                }
                int getNumber(){ return _number; }

                Number() {
                        _number=100;
                }
};

class Word {
        public:
                int getLength() { return _length;}
                std::string getWord() { return _containt; }
                Word(std::string word) {
                        _length=static_cast<int>(word.length());
                        _containt=word;
                        numPtr = new Number();
                }
                Number* getNumPointer() { return numPtr; }
        private:
                int _length;
                std::string _containt;
                Number* numPtr;
};




int main() {
        Base obj;
        if(obj.val || obj.basePtr) {
                cout<<"\n Reached for inner condition\n";
        }

        /* defining the outerNode object*/
        /* Error: Below line of the code will fail with default constructor
         * problem, to solve you have to add a default constructor definition
         * in Node class */
//      OuterNode outObj;

        //checking the base constructor sythesize in derived class
        Bell bell;
        Whisle whisle;
        flip(bell);
        flip(whisle);

        /* fucntion invoke for virtual inheritance example*/
        setter(new A());
        setter(new C());

        /* Code to understand the copy constructor*/
        User usr1;
        User usr2(usr1);

        /* memberwise initialization*/
        Word letter("Shrikant");
        std::cout<<"\n Length: "<<letter.getLength();
        std::cout<<"\n Containt: "<<letter.getWord();
        std::cout<<"\n Number :"<<letter.getNumPointer()->getNumber();

        Word letter1=letter;
        std::cout<<"\n Length: "<<letter.getLength();
        std::cout<<"\n Containt: "<<letter.getWord();
        std::cout<<"\n Number :"<<letter.getNumPointer()->getNumber();
        cout<<"\n returning Zero\n";
        return 0;
}
