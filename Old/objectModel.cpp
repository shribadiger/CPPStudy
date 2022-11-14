#include<iostream>
#include<stdlib.h>
#include<locale>
#include <iomanip>
using namespace std;

class Base {
        friend istream& operator>>( istream&, Base&);
        public:
           Base(int sz=1024) {
                   std::cout<<"\n Base constructor \n";
                   ptr = new char[sz];
           }

        private:
           char *ptr;
};

istream& operator >> (istream& istm, Base& obj) {

        std::cout<<"\n Friend Function is Invokded\n";
        std::cout<<"\n Size of Pointer : "<<sizeof(obj.ptr);
}

/* Global Declration of Object*/
Base obj;

/*
 * Decide a class which indicate the obstract data type which supported
 */
class Point3D {
        public:
                Point3D( float x=0.0, float y=0.0, float z=0.0):_x(x),_y(y),_z(z) {
                        std::cout<<"\n Parametrized constructor\n";
                }

                /* getter functions*/
                float x() const  { return _x; }
                float y() const { return _y; }
                float z() const { return _z; }

                void x(float val) {
                        _x=val;
                }

                void y(float val) {
                        _y=val;
                }

                void z(float val) {
                        _z=val;
                }

        private:
                float _x;
                float _y;
                float _z;

};

inline ostream& operator<<(ostream &out, const Point3D &pt) {
        out<<"("<<pt.x()<<","<<pt.y()<<","<<pt.z()<<")\n";

}

/*
 * Illustation of multilevel of hirarchy in the class level
 */
class Point {
        public:
                Point(float x =0.0):_x(x) {
                        std:cout<<"\n Point Construction\n";}
                float x() { return _x; }
                void x(float val) { _x=val;}
        protected:
                float _x;
};

/* First level of inheritance*/
class Point2d : public Point {
        public:
                Point2d(float x=0.0, float y=0.0) : Point(x),_y(y) {
                        std:cout<<"\n Point2d Construction\n";}
                float y() { return _y;}
                float y(float val) { _y=val;}
        protected:
                float _y;
};

/* Second Level of Inheritance*/
class Point3d : public Point2d {
        public:
                Point3d(float x=0.0, float y=0.0, float z=0.0) :
                        Point2d(x,y),_z(z) {
                        std::cout<<"\n Point3d construction\n"; }
                float z() { return _z; }
                void z(float val) { _z=val;}
        protected:
                float _z;
};

inline ostream& operator<<(ostream &out, Point3d &pt) {
        out<<"("<<pt.x()<<","<<pt.y()<<","<<pt.z()<<")\n";
}

/* Try Strcuture and Inheritance of structure */
struct Data {
        private:
                int val;
        public:
                Data() {
                        std::cout<<"\n Data Constructor\n";
                }
                virtual ~Data() {
                        std::cout<<"\n Data Destructor\n";
                }
        public:
                int getValue();
                void setValue(int);
};

int Data::getValue() {
        return val;
}

void Data::setValue(int input) {
        val=input;
}

struct  SubData:public Data {
        private:
                int subValue;
        public:
                SubData() {
                        std::cout<<"\n Sub Data constructor\n";
                }
                virtual ~SubData() {
                        std::cout<<"\n SubData Destructor\n";
                }
                int getSubValue();
                void setSubValue(int);
};

int SubData::getSubValue() {
        return subValue;
}

void SubData::setSubValue(int val) {
        subValue = val;
}

/* create a class with same name as structure */
class Data ;

/* Checking the template functionality with struct */

//Note:  -- uncomment the code for Error
/*template < struct T>
struct Demo {
        public:
                int values;
                Demo() {
                        std::cout<<"\n Template Demo construtor\n";
                }
}; */

/* checking the template functionality with class type and strcute combination*/
template < class T>
struct Demo {
        public:
                int values;
                Demo() {
                        std::cout<<"\n Template Demo construtor\n";
                }
};

/* Let try to inherit a structure to derived class type */
//Yes. Inheritance is allowed in following way
class InheritStruct : public Data {
        public:
                InheritStruct() {
                        std::cout<<"\n InheritStruct constructor\n";
                }
};

/* Making something crazy inside the class*/
class CPP_Data  {
        public:
                CPP_Data() {
                        std::cout<<"\n CPP_Data constructor\n"; }
                operator Data() {
                        std::cout<<"\n Data() operator fucntion\n";
                        return _data; }
        private:
                struct Data _data;
};


int main() {
        cin>>std::setw(1024)>>obj;

        /* Function to check for Point3D Functionality*/
        Point3D point(12,12,12);
        std::cout<<point;

        Point3d pt(20,20,20);
        std::cout<<pt;

        //calling the structure inplementation
        Data *obj = new Data();
        obj->setValue(100);
        std::cout<<"\n Value: "<<obj->getValue();

        //calling the structutre inheitence value
        SubData *subObj = new SubData;

        InheritStruct *inheritObj=new InheritStruct();

        /* checking the CPPData class functionality*/
        CPP_Data * cppDataObj = new CPP_Data();
        struct Data obj = cppDataObj->Data();

        return 0;
}
