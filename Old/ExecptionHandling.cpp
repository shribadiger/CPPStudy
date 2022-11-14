#include<iostream>
using namespace std;

void itMightGoWrong() {
	std::cout<<"\n Function which creates the error while execution\n";
	bool error1 = false;

	bool error2 = false;

	bool error3 = true;

	bool error = false;
	
	//check if error occures and throw an exception
	if(error){
		throw(8);
	}
	if(error2) {
		throw "Error-2: Handle Failure of App";
	}
	if(error1) {
		throw "Error-1: Handle Failure of App";
	}

	if(error3) {
		throw string("String Exception Handled");
	}
}

int main() {
	try {
		itMightGoWrong();
	}
	catch(int e) {
		std::cout<<"\n Exeception Code: "<<e<<std::endl;
	}
	catch(const char* e) {
		std::cout<<"\n Exception Message: "<<e<<std::endl;
	}
	catch(string &e) {
		std::cout<<"\n String Exception :"<<e<<std::endl;
	}

	std::cout<<"\n After Exection. Still Running the application\n";
	return 0;
}
