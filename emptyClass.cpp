#include <iostream>
using namespace std;
class Base
{
};

class Data
{
public:
   static int objectCounter;
   void getData();
};

int Data::objectCounter = 0;
void Data::getData()
{
   return;
}
class Employee;
class Employee
{
public:
   enum
   {
      max_object = 100
   };
   static size_t num_objects;
   Employee *emp[max_object];
   // size_t size;
};

struct Salary
{
};
struct Hour
{
};
struct Temp
{
};
// non member function sequence of operations
class HR
{
public:
   void terminate(Salary *sal) { cout << "\n Salary Termination"; }
   void terminate(Hour *hour) { cout << "\n Hour Termination"; }
   void terminate(Temp *temp) { cout << "\n Temp Termination"; }
   void terminate(Salary *sal, Hour *hr, Temp *tmp)
   {
      terminate(sal);
      terminate(hr);
      terminate(tmp);
   }
};
int main()
{
   Base e;
   Data obj1;
   cout << "\n Size of Empty Class : " << sizeof(e);
   cout << "\n Size of class with static member and non virtual functions : " << sizeof(obj1);
   Employee empObj;
   cout << "\n Size of Employee Object: " << sizeof(empObj);
   HR obj;
   Salary s;
   Hour h;
   Temp t;
   obj.terminate(&s, &h, &t);
   return 0;
}
