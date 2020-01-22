/*
 * This is Prrogram to illustrate about the template class and 
 * other useful functionality of templates
 */
#ifndef _TEMPLATE_CLASS_
#define _TEMPLATE_CLASS_

#include<iostream>
using namespace std;

template < typename T>
class Matrix {
	public:
		Matrix(T t1, T t2, T t3, T t4); //mutliple value initialization
		Matrix(T t[2][2]); //Single Array Passing 
		Matrix(); //Defualt constructor

		void add_2DMatrix(Matrix obj);
		void mutiply_2DMatrix(Matrix obj);
		void print_2DMatrix();

		T t[2][2]; // 2D array member variable
};

template < typename T>
Matrix<T>::Matrix(T t1, T t2, T t3, T t4) {
	t[0][0]=t1;
	t[0][1]=t2;
	t[1][0]=t3;
	t[1][1]=t4;
}

template<typename T>
Matrix<T>::Matrix( T _t[2][2]) {
	t[0][0]=_t[0][0];
	t[0][1]=_t[0][1];
	t[1][0]=_t[1][0];
	t[1][1]=_t[1][1];
}

//Default constructor
template<typename T>
Matrix<T>::Matrix() {
	t[0][0]=0;
	t[0][1]=0;
	t[1][0]=0;
	t[1][1]=0;
}

template<typename T>
void Matrix<T>::add_2DMatrix(Matrix obj) {
	t[0][0]=t[0][0]+obj.t[0][0];
	t[0][1]=t[0][1]+obj.t[0][1];
	t[1][0]=t[1][0]+obj.t[1][0];
	t[1][1]=t[1][1]+obj.t[1][1];
}

template<typename T>
void Matrix<T>::mutiply_2DMatrix(Matrix obj) {
	t[0][0]= t[0][0]*obj.t[0][0]+t[0][1]*obj.t[1][0];
	t[0][1]= t[0][0]*obj.t[0][1]+t[0][1]*obj.t[1][1];
	t[1][0]= t[1][0]*obj.t[0][0]+t[1][1]*obj.t[1][0];
	t[1][1]= t[1][0]*obj.t[0][1]+t[1][1]*obj.t[1][1];
}

template<typename T>
void Matrix<T>::print_2DMatrix() {
	std::cout<<"\n| "<<t[0][0]<<","<<t[0][1]<<"|";
	std::cout<<"\n| "<<t[1][0]<<","<<t[1][1]<<"|";
}

//Define a class with static member variable
template<typename T>
class StaticMemberClass {
	public:
		void printStaticValue();
		static T valuePublic;
	private:
		static T valuePrivate;
};

template<typename T> 
void StaticMemberClass<T>::printStaticValue() {
	std::cout<<"\n valuePrivate: "<<StaticMemberClass::valuePrivate++;
	std::cout<<"\n valuePublic : "<<StaticMemberClass::valuePublic++;
}

//external defition for static variable
template<typename T> T StaticMemberClass<T>::valuePublic = 1;
template<typename T> T StaticMemberClass<T>::valuePrivate = 1.2;


#endif
