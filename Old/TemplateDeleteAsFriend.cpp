#include<iostream>
using namespace std;

namespace DeleteOperation {
	template<class T> void deleteObject(T* obj) {
		std::cout<<"\n deleteObject operation executed\n";
		delete obj;
	}
}

//Create Dummy class to verify the templete class as friend
class Demo {
	public:
		Demo() {
			std::cout<<"\n Object Get Created\n";
		}
		//Making DeleteOperation as friend
		friend void DeleteOperation::deleteObject<Demo>(Demo* obj);
	private:

		~Demo() {
			std::cout<<"\n Private destructor of Demo get invoked\n";
		}


};

class Dummy {
	public:
		Dummy() {
			std::cout<<"\n Dummy Object get created\n";
		}

		friend void DeleteOperation::deleteObject<>(Dummy* obj);
	private:
		~Dummy() {
			std::cout<<"\n Private destructor of Dummy\n";
		}
};

int main() {
	Demo *obj1 = new Demo();
	DeleteOperation::deleteObject(obj1);
	Dummy *obj2 = new Dummy();
	DeleteOperation::deleteObject(obj2);
	return 0;
}
