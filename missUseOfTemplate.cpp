#include<iostream>
using namespace std;

class Color {
	public:
		void fun() {
			cout<<"\n Color fun started\n";
		}

		void foo() {
			cout<<"\n color foo started\n";
		}
};

class Paint {
	public:
		void fun() {
			cout<<"\n Paint fun started\n";
		}

		void foo() {
			cout<<"\n Paint foo started\n";
		}
};

template<class T>
void run(T& obj) {
	obj.fun();
	obj.foo();
}

int main() {
	Color obj1;
	Paint obj2;

	std::cout<<"\n Calling Color Functions\n";
	run(obj1);
	std::cout<<"\n Calling Paint Functions\n";
	run(obj2);

	return 0;
}
