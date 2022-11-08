/*
 * checking the bulk operations
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Preference
{
private:
    int contactNumber;
    bool isNotificationStatus;

public:
    // setter functions
    void setContactNumber(int num)
    {
        contactNumber = num;
        std::cout << "\n Contact No:" << this->contactNumber;
    }
    void setNotificationStatus(bool value) { isNotificationStatus = value; }

    // getter functions
    int getContactNumber() { return contactNumber; }
    bool getNotificationStatus() { return isNotificationStatus; }
};

class User
{
private:
    int userID;
    string name;
    Preference mPreference;

public:
    // setter function
    void setUserID(int ID) { this->userID = ID; }
    void setName(string name) { this->name = name; }
    void setPreference(Preference pref) { this->mPreference = pref; }

    // getter functions
    int getUserID() { return this->userID; }
    string getName() { return this->name; }
    Preference getPreference() { return this->mPreference; }
};

std::vector<std::string> names = {"Ramesh", "suresh", "mahesh", "girish", "jagadish"};

std::vector<User> userList;
void generateUserList()
{
    int initialID = 1;
    int initialContact = 1111;
    for (int i = 0; i < names.size(); i++)
    {
        User obj;
        Preference pref;
        obj.setName(names[i]);
        obj.setUserID(initialID);
        pref.setContactNumber(initialContact);
        pref.setNotificationStatus(false);
        if (initialID % 2 == 0)
            pref.setNotificationStatus(true);
        obj.setPreference(pref);
        initialID++;
        initialContact++;
        userList.push_back(obj);
    }
}

void printUserList()
{
    std::cout << "\nName\t ID\t Contact\t Notification";
    for (int i = 0; i < userList.size(); i++)
    {
        std::cout << "\n"
                  << userList[i].getName() << "\t " << userList[i].getUserID()
                  << "\t " << userList[i].getPreference().getContactNumber()
                  << "\t " << userList[i].getPreference().getNotificationStatus();
    }
}

void sendNotification(int contactNumber)
{
    std::cout << "\n --> Sending Message to : " << contactNumber;
}

int main()
{
    generateUserList();
    printUserList();

    // trying without batch operation
    for (std::vector<User>::iterator itr = userList.begin(); itr != userList.end(); itr++)
    {
        Preference pref = itr->getPreference();
        if (pref.getNotificationStatus())
        {
            sendNotification(pref.getContactNumber());
        }
    }

    return 0;
}