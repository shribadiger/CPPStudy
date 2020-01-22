#include<iostream>
using namespace std;


class CanGoWrong {
	public:
		CanGoWrong(){
			pChar=new char[999999999999];
		}

		virtual ~CanGoWrong() {
			delete [] pChar;
		}
		char* pChar;
};


int main() {
	try {
		CanGoWrong obj;
	}
	catch(...) {
		std::cout<<"\n Failed to allocate memory\n";
	}
}
