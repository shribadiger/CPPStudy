#include<iostream>
#include<vector>

/* class to illustrate the vector functionality*/
class Base
{
        public:
                Base():val(0) {
                //      std::cout<<"\n Base constructor\n";
                }
                Base(int inVal):val(inVal) {
                        //std::cout<<"\n Base parametrized constructor\n";
                }

                Base(const Base& obj){
                        this->val=obj.val;
                        //std::cout<<"\n Base copy constructor\n";
                }
                 ~Base() {
                        //std::cout<<"\n Base Destructor\n";
                }
                int get() {
                        return val;
                }
                void set(int iVal) {
                        val=iVal;
                }
        private:
                int val;
};

void printBaseVector(std::vector<Base> inVector) {
        std::cout<<"\n +------ BEGIN PRINT BASE VECTOR --------+\n";
        std::vector<Base>::iterator itr=inVector.begin();
        while(itr != inVector.end()) {
                std::cout<<"\t"<<itr->get();
                itr++;
        }
        std::cout<<"\n";
        std::cout<<"\n +------ END PRINT BASE VECTOR --------+\n";
}



void printVector(std::vector<int> myVector) {
        std::vector<int>::iterator itr=myVector.begin();
        while(itr != myVector.end()) {
                std::cout<<"\t"<<*itr;
                itr++;
        }
        std::cout<<"\n";
}

int main() {
        std::vector<int> myVector; //vector which is not not initialized any size
        try {
                myVector.at(1000) = 0; // trying to assign a value zero at index 1000
        }
        catch(std::out_of_range obj) { // catch the out of range exeception
                std::cout<<"\n Exception:"<<obj.what()<<"\n";
        }
        //Vector to reserve the memory after empty initialization
        std::vector<char> charVector; //Empty vector
        charVector.reserve(10);  //This will reserve the 10 memory blocker for char
        char c=0;
        while(c != 'x') {
                std::cin>>c;
                charVector.push_back(c);
        }

        std::cout<<"\n char Vector containt:";
        std::vector<char>::iterator itr=charVector.begin();
        while(itr != charVector.end()) {
                std::cout<<*itr<<"\t";
                itr++;
        }
        //reserve will not strick the vector which already initialised with more values
        std::vector<int> IntVector(10);
        std::cout<<"\n Capacity of IntVecor befor reserve: "<<IntVector.capacity()<<"\n";
        //IntVector.reserve(90);
        std::cout<<"\n Capacity of IntVector after reserve:"<<IntVector.capacity()<<"\n";

        /* check if any data loose will happen after reserve*/
        /*IntVector[0]=100;
        IntVector[1]=100;
        IntVector[2]=100;
        IntVector[3]=100;
        IntVector.reserve(1);*/
        IntVector.push_back(100);
        IntVector.push_back(100);
        IntVector.push_back(100);
        IntVector.push_back(100);

        std::vector<int>::iterator it=IntVector.begin();
        std::cout<<"\n size of vector:"<<IntVector.size();
        while(it != IntVector.end()) {
                std::cout<<"\n Value at IntVector:"<<*it;
                it++;
        }

        /* checking the resize functionality in vector*/
        std::vector<int> myIntVector;  // create the empty array
        myIntVector.reserve(3); // reserve 3 memory blocks
        myIntVector.push_back(100);
        myIntVector.push_back(101);
        myIntVector.push_back(102);
        printVector(myIntVector);
        std::cout<<"\n Resizing the integer vector to 5\n";
        myIntVector.resize(5);
        printVector(myIntVector);
        myIntVector.resize(15,5);
        printVector(myIntVector);


        /* check the vector functionality with class */
        std::vector<Base> baseVector; // Empty  Base class object vector initilization;
        baseVector.reserve(2);
        printBaseVector(baseVector);
        for(int i=0; i<2;i++)
        {
                baseVector.push_back(Base(i));
        }
        printBaseVector(baseVector);

        /* TRY VECTOR REALLOCATION AND INVALIDATE THE POINTER FUCNTIONALITY*/
        std::vector<int> relVector;
        relVector.resize(10,4);
        int* ptr=&relVector[3];
        std::cout<<"\n Value at Ptr : "<<*ptr;
        relVector.push_back(200);
        relVector.resize(1000000,5);
        std::cout<<"\n Value at Ptr : "<<*ptr; // Warning:- this pointer will get invalidated after push_back, bcz its allocates the memory
        return 0;
}
