#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class User;
// global set of users
std::vector<User> listOfusers;
std::vector<string>
    usersList = {"shrikant", "badiger", "shruti", "gauthami", "shriyansh", "tanvi", "shradha", "santosh", "ganesh", "satish"};

class Preference
{
private:
    bool isNotificationActive;
    bool contactNumber;

public:
    // setter funcitons
    void setNotification(bool value) { isNotificationActive = value; }
    void setContactNumber(int number) { contactNumber = number; }

    // getter functions
    bool getNotificationStatus() { return isNotificationActive; }
    int getContactNumber() { return contactNumber; }
};
class User
{
private:
    string name;
    Preference mPreference;
    int userID;

public:
    // parameterized constructor
    User(int id);
    //  setter functions
    void setName(std::string inName);
    void setNumber(int inNumber);
    void enableNotification();
    void disableNotification();

    // getter functions
    string getName();
    int getUserID();
    bool getPreference();
};

User::User(int id)
{
    this->userID = id;
}

void User::setName(string inName) { this->name = inName; }

void User::setNumber(int inNumber) { this->mPreference.setContactNumber(inNumber); }

void User::enableNotification() { this->mPreference.setNotification(true); }

void User::disableNotification() { this->mPreference.setNotification(false); }

string User::getName() { return this->name; }

int User::getUserID() { return this->userID; }

Preference User::getPreference() { this->mPreference; }

// utility function to prepare the list of contacts

std::vector<User> getWhatsAppContacts()
{
    std::vector<User> contactList;
    int initialNumber = 1111;
    int userID = 1;
    std::vector<string>::iterator itr = usersList.begin();
    bool odd = true;
    while (itr != usersList.end())
    {
        User newUser(userID);
        newUser.setName(*itr);
        newUser.setNumber(initialNumber);
        if (odd)
        {
            newUser.enableNotification();
            odd = false;
        }
        else
        {
            newUser.disableNotification();
            odd = true;
        }

        // increment itr and userID;
        itr++;
        userID++;
        initialNumber++;

        // insert the user object to contact list
        contactList.push_back(newUser);
    }
    return contactList;
}

void printContactDetials(std::vector<User> contacts)
{
    std::vector<User>::iterator itr = contacts.begin();
    std::cout << "\nUser ID \t User Name \t User Contact \t Notification\n";
    while (itr != contacts.end())
    {
        std::cout << itr->getUserID() << "\t" << itr->getName() << "\t" << itr->getPreference().getContactNumber() << "\t" << itr->getPreference().getNotificationStatus() << "\n";
        itr++;
    }
}

std::vector<int> getNotifyingUserList(std::vector<int> userIDs)
{
    std::vector<int> notifyingUserList;
    std::vector<int>::iterator itr = userIDs.begin();
    std::vector<User>::iterator userItr = listOfusers.begin();
    while (itr != userIDs.end())
    {
        // cout << "\n [log]: Checking the userList in main group - " << *itr;
        if (*itr == userItr->getUserID())
        {
            // cout << "\n[Log]: Pushing the contact - " << userItr->getContactNumber();
            notifyingUserList.push_back(userItr->getPreference().getContactNumber());
            itr++;
        }
        userItr++;
    }
    return notifyingUserList;
}

std::vector<bool> sendNotification(std::vector<int> notifyingUsers)
{
    std::vector<bool> statusList;
    std::vector<int>::iterator itr = notifyingUsers.begin();
    while (itr != notifyingUsers.end())
    {
        cout << "\n Sending Notifcation --> " << *itr;
        itr++;
        statusList.push_back(true);
    }
    return statusList;
}

bool isNotificationEnabled(User &obj)
{
    return obj.getNotificationStatus();
}

int main()
{
    listOfusers = getWhatsAppContacts();
    printContactDetials(listOfusers);

    // calling without bulk operations
    std::vector<int> userIDs = {1, 3, 4};
    std::vector<int> notifyingUsers = getNotifyingUserList(userIDs);
    std::vector<bool> result = sendNotification(notifyingUsers);

    // trying to implement the bulk operation
    std::vector<int> customUsers;
    std::transform(listOfusers.begin(), listOfusers.end(),
                   back_inserter(customUsers),
                   [](User &user)
                   { return user.getUserID(); });

    vector<int> contactList = getNotifyingUserList(customUsers);

    remove_if(listOfusers.begin(), listOfusers.end(),
              [](User & obj)); // print the user after removal
    for (std::vector<User>::iterator itr = listOfusers.begin();
         itr != removedUsers; ++itr)
    {
        std::cout << "\nUser: " << itr->getName();
    }
    return 0;
}