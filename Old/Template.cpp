#include<iostream>
using namespace std;

//C macro also defines the square function but it not performs the type check.
#define SQUARE(X) (X*X)

template<typename T>
T square(T value) {
	//function to get the square value
	return(value*value);
}

//Making the Template class for handle the string separately
/*
 * Template specilization required if we need to handle the specific user type 
 * and perform the different operation from the usual one
 */
template<>
std::string square<std::string>(std::string input) {
	return (input+input);
}
/*
 * multiple templated values for the function
 */
template<typename T1, typename T2>
void printSquare(T1 val1, T2 val2) {
	std::cout<<"\n T1 : "<<(val1*val1);
	std::cout<<"\n T2 : "<<(val2*val2);
	std::cout<<"\n\n\n";
}

/*
 * Template function with non-Type parameter
 */
template<typename T, int count>
void prepareArray(T val) {
	T list[count];
	for(int i=0;i<count;i++) {
		list[i]=val;
		val++;
		std::cout<<"\n List["<<i<<"]:"<< list[i];
	}
	std::cout<<"\n\n";
}

/*
 * Template function with default argument
 */
template<typename T, int count=4> 
void defualtCountPrint(T val) {
	T list[count];
	for(int i=0;i<count;i++) {
		list[i]=val++;
		std::cout<<"\n List ["<<i<<"]:"<<list[i];
	}
	std::cout<<"\n\n";
}

int main() {
	int val1=2;
	float val2=4.4;
	double val3=6789;
	std::string val4="Shri";

	std::cout<<"\n Explicit mention of Type Identifier:";
	std::cout<<"\n Square of Int: "<<square<int>(val1);
	std::cout<<"\n Square of Float: "<<square<float>(val2);
	std::cout<<"\n Square of Double: "<<square<double>(val3);
	std::cout<<"\n Square of String: "<<square<std::string>(val4);

	std::cout<<"\n\n\n Implicit mention of Type Identifier:";
	std::cout<<"\n Square of Int: "<<square(val1);
	std::cout<<"\n Square of Float: "<<square(val2);
	std::cout<<"\n Square of Double: "<<square(val3);
	std::cout<<"\n Square of String: "<<square(val4);

	std::cout<<"\n\n\n C macro function call to identify the square:";
	std::cout<<"\n Square of Int: "<<SQUARE(val1);
	std::cout<<"\n Square of Float: "<<SQUARE(val2);
	std::cout<<"\n Square of Double: "<<SQUARE(val3);
	/* std::cout<<"\n Square of String: "<<SQUARE(val4); */
	/* Above function will get failed due to unable to find the function type with string object
	 * because, std::string act as object of string class, its not a defined type, Hence Error */

	printSquare(val1,val2);
	printSquare(val2,val3);

	//calling the non-type value to template function
	prepareArray<float,4>(val2);

	//calling the non-type value with default count=4 without type specify
	defualtCountPrint<>(val2);

	return 0;
}
