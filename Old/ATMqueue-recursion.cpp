#include <iostream>
using namespace std;

struct Person
{
    struct Person *nextInLine;
};

typedef struct Person PERSON;

PERSON *getPersonList(int numbers)
{
    if (numbers == 0)
        throw "Zero person not allowed";
    PERSON *head = nullptr;
    PERSON *itr;
    while (numbers > 0)
    {
        if (head == nullptr)
        {
            head = (PERSON *)malloc(sizeof(PERSON));
            head->nextInLine = nullptr;
            itr = head;
            numbers--;
            continue;
        }
        itr->nextInLine = (PERSON *)malloc(sizeof(PERSON));
        itr = itr->nextInLine;
        numbers--;
    }
    return head;
}

int getPositionInList(PERSON *personObj)
{
    // break condition of recursion program
    if (personObj->nextInLine == nullptr)
    {
        return 1;
    }

    return 1 + getPositionInList(personObj->nextInLine);
}
int main()
{
    PERSON *head1 = getPersonList(10);
    cout << "\n Number of Positions  = " << getPositionInList(head1);
    PERSON *head2 = getPersonList(5);
    cout << "\n Number of Positions  = " << getPositionInList(head2);
    return 0;
}