/*
 * This is program to illustrate about the binding data members in class level
 * 1. placing all data members first in class declaration to ensure the right binding
 * 2. place all inline functions regardless of thier size , outsize the class declration
 */

#include<iostream>
using namespace std;

extern int value=100;

class Point3D {
        private:
                int value;
        public:
                Point3D():value(300) {
                        cout<<"\n Point3D constructor\n";
                }

                void setValue(int val) {
                        value=val;
                }

                int getValue() const {
                        return value;
                }
};

// case 2: inline functions
class Point2D {
        private:
                int x;
                int y;
        public:
                Point2D();
                void setXY(int xx,int yy);
                int getX();
                int getY();
};

inline Point2D::Point2D() {
        cout<<"\n Point2D constructor\n";
}

inline void Point2D::setXY(int xx, int yy) {
        x=xx;
        y=yy;
}

inline int Point2D::getX() {
        return x;
}

inline int Point2D::getY() {
        return y;
}


int main() {
        cout<<"\n extern value : "<<value<<"\n";

        Point3D obj1;
        cout<<"\n Value at Point3D: "<<obj1.getValue()<<"\n";

        Point2D obj2;
        return 0;
}
