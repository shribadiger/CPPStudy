/* preparing the singleton class and monitoring the object */
#include<iostream>
using namespace std;
 

class Singleton {
    private:
     int _basicIdentity;
     int _rapicCheck;
     bool isValidData;
     Singleton():_basicIdentity(0),_rapicCheck(0),isValidData(false) {}
   public:
     static Singleton* instance;
     static Singleton* getInstance() {
         if(instance ==nullptr) {
            instance=new Singleton();
         }
         return instance;
      }
};

Singleton* Singleton::instance = nullptr;

int main() {
   //checking the sinle object present for class instance
   Singleton* myInst = Singleton::getInstance();
   return 0;
}
       
