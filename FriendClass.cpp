
/*
 * Program to Illustrate about the friend class
 */
#ifndef _FRIEND_CLASS_
#define _FRIEND_CLASS_
#include<iostream>

class Global;
class Base {
        private:
                int value;
        public:
                Base();
                virtual ~Base();
                void displayValue();
                friend class Global; /* Global class is a friend of Base*/

};

Base::Base() {
        value=100;
}

Base::~Base() {
        std::cout<<"\n Deletion of Base Object\n";
}

void Base::displayValue() {
        std::cout<<"\n Value: "<<value<<std::endl;
}

/* Global Class definition and Implementation of Functions*/
class Global {
        private:
                int globeEntry;
        public:
                Global();
                virtual ~Global();
                void displayGlobeEntry(Base* obj);
};

Global::Global() {
        globeEntry=200;
}

Global::~Global() {
        std::cout<<"\n Deletion of Global Object\n";
}

void Global::displayGlobeEntry(Base* obj) {
        std::cout<<"\n Base Value: "<<obj->value;
        std::cout<<"\n GlobeEntry: "<<globeEntry;
}

int main(int argc, char* argv[]) {
        std::cout<<"\n Allocation of Base Object\n";
        Base* obj0 = new Base();
        obj0->displayValue();

        std::cout<<"\n Allocation of Globe Object\n";
        Global* obj1 = new Global();
        obj1->displayGlobeEntry(obj0);
        delete obj0;
        delete obj1;
        return 0;
}
#endif
