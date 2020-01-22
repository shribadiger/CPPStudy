/*
 * This is Program to illustrate about the template inheritance
 */
#ifndef _TEMPLATE_IMHERITANCE
#define _TEMPLATE_IMHERITANCE

#include<iostream>
#include<string>
#include<math.h>

/* ENUM for handling the different colors */
enum eColor{
	none =0,
	red,
	white,
	blue,
	yellow,
	green,
	black
};

class Color {
	public:
		eColor  m_color;
	        Color(eColor c);
		void set_color(eColor e);
	        eColor get_color();
	        std::string get_str_color();
};

Color::Color(eColor clr) {
	m_color=clr;
}

void Color::set_color(eColor e) {
	m_color = e;
}

eColor  Color::get_color() {
	return m_color;
}

std::string Color::get_str_color() {
	switch(get_color()) {
		case none:
			return "none";
		case red:
			return "red";
		case white:
			return "white";
		case blue:
			return "blue";
		case yellow:
			return "yellow";
		case green:
			return "green";
		case black:
			return "black";
		default: 
			std::cout<<"\n Error: Unable to find the proper color\n";
			return "none";
	}
}

//Inheritance of Color class to template class
template<typename T>
class Circle : public Color {
	public:
		Circle(T x, T y, T radius, eColor color);
		Circle(T x, T y, T radius);
		Circle(T radius);

		T area();
		T circumtance();

		T getX();
		T getY();
		T getRadius();
	protected:
		T _x;
		T _y;
		T _radius;
};

template<typename T>
Circle<T>::Circle(T x, T y, T radius, eColor clr):Color(clr) {
	_x=x;
	_y=y;
	_radius=radius;
}

template<typename T>
Circle<T>::Circle(T x, T y, T radius):Color(none) {
	_x=x;
	_y=y;
	_radius=radius;
}

template<typename T>
Circle<T>::Circle(T radius):Color(none) {
	_radius=radius;
}

template<typename T>
T Circle<T>::getX() { return _x; }

template<typename T>
T Circle<T>::getY() { return _y; }

template<typename T>
T Circle<T>::getRadius() { return _radius; }

template<typename T>
T Circle<T>::area() {
	return M_PI*_radius*_radius;
}

template<typename T>
T Circle<T>::circumtance() {
	return 2*M_PI*_radius;
}

/*
 * Inheritance of the Non Template class by template class
 */
class Sphere : public Circle<float> {
	public:
		Sphere(float x, float y, float z, float radius, eColor clr);
		Sphere(float radius);
		Sphere();

		float surfaceArea();
		float volume();
		float getZ();

	private:
		float _z;
};

Sphere::Sphere(float x, float y, float z, float radius, eColor clr):Circle(x,y,z,clr) {
	std::cout<<"\n Sphere constructor\n";
	_z=z;
}

Sphere::Sphere(float radius):Circle(radius) {
	this->_x=static_cast<float>(0);
	this->_y=static_cast<float>(0);
	this->_z=static_cast<float>(0);
	this->_radius=static_cast<float>(0);
}

Sphere::Sphere():Circle(0){
	this->_x=static_cast<float>(0);
	this->_y=static_cast<float>(0);
	this->_z=static_cast<float>(0);
	this->_radius=static_cast<float>(0);
}

float Sphere::surfaceArea() {
	return ((4 * M_PI * (this->_radius * this->_radius))) ;
}

float Sphere::volume() {
	return ((4 * M_PI * (this->_radius * this->_radius * this->_radius)) / 3) ;
}

template<typename T>
class TSphere : public Circle<T> {
	public:
		TSphere(T x, T y, T z, T radius, eColor clr);
		TSphere(T radius);
		TSphere();

		T surfaceArea();
		T volume();
		T getZ();

	private:
		T _z;
};

template<typename T>
TSphere<T>::TSphere(T x, T y, T z, T radius, eColor clr):Circle<T>(x,y,z,clr) {
	std::cout<<"\n Sphere constructor\n";
	_z=z;
}

template<typename T>
TSphere<T>::TSphere(T radius):Circle<T>(radius) {
	this->_x=static_cast<float>(0);
	this->_y=static_cast<float>(0);
	this->_z=static_cast<float>(0);
	this->_radius=static_cast<float>(0);
}
template<typename T>
TSphere<T>::TSphere():Circle<T>(0){
	this->_x=static_cast<float>(0);
	this->_y=static_cast<float>(0);
	this->_z=static_cast<float>(0);
	this->_radius=static_cast<float>(0);
}

template<typename T>
T TSphere<T>::surfaceArea() {
	return ((4 * M_PI * (this->_radius * this->_radius))) ;
}

template<typename T>
T TSphere<T>::volume() {
	return ((4 * M_PI * (this->_radius * this->_radius * this->_radius)) / 3) ;
}
#endif
