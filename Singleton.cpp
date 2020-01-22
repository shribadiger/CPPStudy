/*
 * This is Program to illutrate about the singleton Design pattern
 * and advantage and disadvantages
 */
#ifndef _singleton_
#define _singleton_

#include<iostream>
#include<stdio.h>
#include<stdlib.h>

/*
 * List of applicaiton interfaces that user allowed to login 
 */
class SalaryLogin {
	public:
		SalaryLogin();
		virtual ~SalaryLogin();
}

class LeaveLogin {
	public:
		LeaveLogin();
		virtual ~LeaveLogin();
}

/* Class to handle the single user sign in */
class SingleSignIn {
	public:
		/*
		 * Static function to get the Single Object from constructor
		 */
		static auto getInstance();

	private:
		SingleSignIn() {
			std::err<<"[LOG] : construction of Object"<<std:endl;
		}

		SingleSignIn(SingleSignIn& obj) {
			std::err<"[LOG] : Copy Constructor "<<std::endl;
		}
};

/* Class Member Defintions*/

auto SingleSignIn::getInstance() {
	static auto _instance = std::unique_ptr<SingleSignIn>{nullptr}
	if(!_instance) {
		_instance.reset(new SingleSignIn);
	}
	return *_instance.get();
}


#endif


