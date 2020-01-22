#include "TemplateClass.h"
#include<iostream>

int main()
{
	Matrix<int> X(1,2,3,4);
	Matrix<int> Y(4,3,2,1);

	X.print_2DMatrix();
	Y.print_2DMatrix();
        
	std::cout<<"\n Addition of Matrix\n";
	X.add_2DMatrix(Y.t);
	X.print_2DMatrix();

	std::cout<<"\n Mutliplaction of Matrix\n";
	X.mutiply_2DMatrix(Y.t);
	X.print_2DMatrix();

	//Note: each version of Specilization of Template class will have
	//static member variable. but each instace of specilization will share
	//each static member veriable across.
	std::cout<<"\n Creating the Object of StaticMemberClass\n";
	StaticMemberClass<int> intClassObj;
	StaticMemberClass<float> floatClassObj;
	StaticMemberClass<double> doubleClassObj;

	intClassObj.printStaticValue();
	floatClassObj.printStaticValue();
	doubleClassObj.printStaticValue();

	return 0;
}
