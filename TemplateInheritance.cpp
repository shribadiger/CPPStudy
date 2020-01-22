#include "TemplateInheritance.hpp"

int main() {
	Circle<float> obj1(0.0,0.0, 10.0, white);
	Circle<int> obj2(0.0,0.0, 14.0, green);
	std::cout<<"\n Area : "<<obj1.area();
	std::cout<<"\n Color: "<<obj1.get_str_color();
	std::cout<<"\n Area : "<<obj2.area();
	std::cout<<"\n Color: "<<obj2.get_str_color();
	Circle<double> obj3(0.6,0.5, 14.0, black);
	std::cout<<"\n Area : "<<obj3.area();
	std::cout<<"\n Color: "<<obj3.get_str_color();

	// create the object of sphere
	Sphere obj4(0.5,0.5,0.5,10.0,white);
	std::cout<<"\n Volume: "<<obj4.volume();
	std::cout<<"\n Circumtance: "<<obj4.surfaceArea();
	std::cout<<"\n Color : "<<obj4.get_str_color();

	// create the object of Tsphere
	TSphere<float> obj5(0.5,0.5,0.5,10.0,none);
	std::cout<<"\n Volume: "<<obj5.volume();
	std::cout<<"\n Circumtance: "<<obj5.surfaceArea();
	std::cout<<"\n Color : "<<obj5.get_str_color();


	return 0;
}
