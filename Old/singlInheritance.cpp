/*
 * checking the single inheritance
 */
#include <iostream>
using namespace std;

class Base
{
public:
    Base() : _integerNumber(0) {}
    virtual int getIntegerNumber();
    virtual void setIntegerNumber(int);

private:
    int _integerNumber;
};

int Base::getIntegerNumber()
{
    return _integerNumber;
}

void Base::setIntegerNumber(int input)
{
    this->_integerNumber = input;
}

class Derived : public Base
{
private:
    int _IntNumber;

public:
    int getIntegerNumber() { return _IntNumber; } // overrides Base::getIntegerNumber()
    void displayInteger() { cout << "\n Integer : " << _IntNumber; }
};

class Shape
{
private:
    int _x_axis;
    int _y_axis;

public:
    Shape() : _x_axis(0), _y_axis(0) { cout << "\nShape::Shape()"; }
    Shape(int x) : _x_axis(x), _y_axis(x) { cout << "\nShape::Shape(int)"; }
    Shape(int x, int y) : _x_axis(x), _y_axis(y) { cout << "\n Shape::Shape(int,int)"; }
    int get_x_axis() { return _x_axis; }
    int get_y_axis() { return _y_axis; }
};

class Subject
{
private:
    string _name;

public:
    Subject() : _name("") { cout << "\nSubject::Subject()"; }
    Subject(string name) : _name(name) { cout << "\nSubject::Subject(string)"; }
    string getShapeName() { return _name; }
};

class ObservedShape : public Shape, public Subject
{
private:
    int _calculateArea;

public:
    ObservedShape() : Shape(100, 100), Subject("Reactangle") { cout << "\n Observed::Observed()"; }
    int getArea() { return (this->get_x_axis() * this->get_y_axis()); }
};
int main()
{
    Base *basePtr = new Base();
    basePtr->setIntegerNumber(100);

    basePtr = new Derived();
    basePtr->setIntegerNumber(800);                       // invoke base call function
    cout << "\n Derived:" << basePtr->getIntegerNumber(); // invoke derived class function

    // mutliple Inheritance Object
    ObservedShape *obs = new ObservedShape();
    Shape *shape = obs;
    Subject *subj = obs;

    cout << "\n X axis : " << obs->get_x_axis();
    cout << "\n Y axis : " << obs->get_y_axis();
    cout << "\n Area : " << obs->getArea();
    cout << "\n Name : " << obs->getShapeName();

    // Let compare the object Shape and ObservedShape object
    if (obs == shape)
    {
        cout << "\n Compiler comparision Successful" << endl;
    }

    // static cast comparision
    ObservedShape *obsPtr = new ObservedShape();
    Shape *shapePtr = obsPtr; // no delta
    Subject *subPtr = obsPtr; // delta

    obsPtr = static_cast<ObservedShape *>(shapePtr); // no delta
    obsPtr = static_cast<ObservedShape *>(subPtr);   // delta

    obsPtr = (ObservedShape *)shape;
    obsPtr = (ObservedShape *)subPtr;
    return 0;
}