#include<iostream>
#include<memory>
#include<vector>
#include<exception>
using namespace std;
class Data {
    private:
        int mAdhaarNumber;
        std::string firtName;
        std::string lastName;
        int dateOfBirth[8]; //ddmmyyyy format
    public:
        Data(int adhaarNo, std::string fName, std::string lName, int dob[]){
            mAdhaarNumber=adhaarNo;
            firtName=fName;
            lastName=lName;
            for(int i=0; i<8;i++){
                dateOfBirth[i]=dob[i];
            }
        }
        Data(const Data& dataObj){
            this->mAdhaarNumber=dataObj.mAdhaarNumber;
            this->firtName=dataObj.firtName;
            this->lastName=dataObj.lastName;
            for(int i=0; i<8;i++){
                this->dateOfBirth[i]=dataObj.dateOfBirth[i];
            }
        }

        void operator=(const Data& dataObj){
            for(int i=0; i<8;i++){
                this->dateOfBirth[i]=dataObj.dateOfBirth[i];
            }
            this->mAdhaarNumber=dataObj.mAdhaarNumber;
            this->firtName=dataObj.firtName;
            this->lastName=dataObj.lastName;
        }

        friend bool operator==(const Data& lhs,const Data& rhs){
            if((lhs.lastName == rhs.lastName) &&
                (lhs.firtName==rhs.firtName) &&
                (lhs.mAdhaarNumber == rhs.mAdhaarNumber)) 
                return true;
            return false;
        }

        friend ostream& operator<<(ostream& os, const Data& obj){
            os<<obj.mAdhaarNumber<<":"<<obj.firtName<<":"<<obj.lastName;
            return os;
        }
};

class DataHandler {
    private:
        std::vector<Data>mDataList;
    public:
        DataHandler() {
            //simple constructor
            std::cout<<"\n[Log]: "<<__FUNCTION__<<" invoked";
        }
        void insertDataToList(const Data& obj){
            cout<<"\n[Log]: "<<__FUNCTION__<<" invoked";
            mDataList.push_back(obj);
        }

        bool isPresentInDataInList(const Data& obj){
            bool isPresent=false;
            for(auto itr:mDataList){
                if(itr==obj){
                    return true;
                }
            }
            return false;
        }

        int getSizeOfDataList(){
            return mDataList.size();
        }

        friend ostream& operator<<(ostream& os, const DataHandler& obj){
            for(int i=0;i<obj.mDataList.size();i++){
                cout<<obj.mDataList[i];
            }
        }
    
};

int main() {
    DataHandler obj;
    int dob[8]={0,8,0,9,1,9,8,8};
    Data obj1(123,"shrikant","badiger",dob);
    Data obj2(234,"shruti","poddar",dob);
    Data obj3(345,"Gauthami","Badiger",dob);

    obj.insertDataToList(obj1);
    obj.insertDataToList(obj2);
    obj.insertDataToList(obj3);

    std::shared_ptr<DataHandler> sharedPtr=std::make_shared<DataHandler>(obj);
    std::weak_ptr<DataHandler> weakPtr(sharedPtr);

    /* Check about the reference count and expire of weak pointer */
    std::cout<<"\n sharedPtr reference count : "<<sharedPtr.use_count();
    std::cout<<"\n weakPtr reference count   : "<<weakPtr.use_count();
    std::cout<<"\n is weakPtr expired        : "<<weakPtr.expired();

    /* Now, We can use weak pointer to reference back to shared pointer and
       check the availability of weakPtr */
    try {
        std::shared_ptr<DataHandler> newSharedPtr = weakPtr.lock();
        std::cout<<"\n newSharedPtr reference count : "<<newSharedPtr.use_count();
        std::cout<<"\n weakPtr reference count      : "<<weakPtr.use_count();
        std::cout<<obj;
    }
    catch(...){
        std::cout<<"\n[Error]: Failed to acquire the weakPtr";
        return -1;
    }

    /* Lets try to reset the weakPtr*/
    weakPtr.reset();


    return 0;
}
