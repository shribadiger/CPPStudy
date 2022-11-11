/* code to per the two sorted list into single list*/

#include <iostream>
using namespace std;

struct Node
{
    int val;
    struct Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int input) : val(input), next(nullptr) {}
};

typedef struct Node NODE;

NODE *mergeList(NODE *fisrtList, NODE *secondList)
{
    NODE *start = nullptr, *last = nullptr;
}

int main()
{
    // prepare the list A
    struct Node *firstList = nullptr;
    firstList = new Node(1);
    firstList->next = new Node(3);
    firstList->next->next = new Node(5);

    // prepare the list B
    struct Node *secondList = nullptr;
    secondList = new Node(2);
    secondList->next = new Node(4);
    secondList->next->next = new Node(6);
}