/*
 * This is program to illustrate some sprintf questions
 */
#include<iostream>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;

/*
 * void PrettyFormat(int i, char* buf) {
	sprintf(buf, "%4d", i);
} */

/*
 * its very hard to prepare the template function for sprintf
 */

/*
template<typename T>
void PrettyFormat(T i, char* buf) {
	sprintf(buf, "what need to fill here?", i);
} 
*/

template<typename T>
void PrettyFormat(T value, char* s) {
	ostringstream temp;
	temp<<setw(4)<<value;
	s=const_cast<char*>(temp.str().c_str());
}

int main() {
	int x=42;
	char* smallBuf;
	PrettyFormat(x,smallBuf);
	assert(x==42);
	int value=12345678;
	PrettyFormat(value,smallBuf);
	assert(value==12345678);
	//sprintf(smallBuf,"%4ld",x);
	//std::cout<<"\n val: "<<smallBuf;
	printf("\n Data : %s",smallBuf);
}
