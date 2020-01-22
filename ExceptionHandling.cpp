#include<iostream>
using namespace std;

int main(int argc,  char* argv[]) {
	std::cout<<"\n Handling the system generated exceptions\n";
	try {
		int _readValue;
		std::cin>>_readValue;
		if(_readValue > 100 ) {
			throw std::string("Exception at Reading value");
		}
		else {
			throw std::string("Exception at Writing value");
		}
	}
	catch(std::string exp) {
		std::cout<<"\n Handle: "<<exp<<"\n";
	}
	catch(...) {
		std::cout<<"\n Handle the Generic Exception\n";
	}

	return 0;
}
