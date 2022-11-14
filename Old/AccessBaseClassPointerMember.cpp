#include<iostream>
using namespace std;

class Point {
	private:
	int x;
	int y;
};

class Base {
	public:
		void print();
	private:
		Point *pPtr;
};

void Base::print() {
	std::cout<<"\n Base Printer\n";
}

class Derived: public Base {
	public:
		void setBasePointer();
};

void Derived::setBasePointer() {
	Point *ptr = new Point();
	static_cast<Base*>(this)->pPtr=ptr;
}

int main() {
	Derived* dPtr = new Derived();
	dPtr->setBasePointer();
}
