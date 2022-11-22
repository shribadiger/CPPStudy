/* Simple C++ code to sort the linked list by using merge sort*/
#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(-1), next(nullptr) {}
    ListNode(int v) : val(v), next(nullptr) {}
};

void printList(ListNode *head)
{
    printf("\n-------------------\n");
    while (head)
    {
        cout << "\t" << head->val;
        head = head->next;
    }
    printf("\n--------------------\n");
}
ListNode *mergeLists(ListNode *list1, ListNode *list2)
{
    ListNode *headPtr = new ListNode(0);
    ListNode *currPtr = headPtr;
    while (list1 && list2)
    {
        cout << "\n checking :" << list1->val << "<=" << list2->val << endl;
        if (list1->val <= list2->val)
        {
            currPtr->next = list1;
            list1 = list1->next;
        }
        else
        {
            currPtr->next = list2;
            list2 = list2->next;
        }
        currPtr = currPtr->next;
    }

    if (list1)
    {
        cout << "\n Last 1:" << list1->val;
        currPtr->next = list1;
        list1 = list1->next;
    }
    if (list2)
    {
        cout << "\n Last 2:" << list2->val;
        currPtr->next = list2;
        list2 = list2->next;
    }
    cout << "\n merge:" << headPtr->next->val;
    return headPtr->next;
}

ListNode *sortList(ListNode *head)
{
    if (head && head->next == nullptr)
    {
        cout << "\n Returning from single node check";
        return head;
    }

    ListNode *prevPtr = nullptr;
    ListNode *slowPtr = head;
    ListNode *fastPtr = head;

    while (fastPtr && fastPtr->next)
    {

        prevPtr = slowPtr;
        cout << "\n Prev Ptr :" << prevPtr->val;
        slowPtr = slowPtr->next;
        cout << "\n Slow Ptr : " << slowPtr->val;
        fastPtr = fastPtr->next->next;
        cout << "\n Moving to next Ptr";
    }
    prevPtr->next = nullptr;

    ListNode *list1 = head;
    ListNode *list2 = slowPtr;
    cout << "\n calling sortList(" << head->val << "," << slowPtr->val << ");";
    sortList(list1);
    printList(list1);
    sortList(list2);
    printList(list2);

    cout << "mergeList(" << list1->val << "," << list2->val << ");" << endl;
    return mergeLists(list1, list2);
}

int main()
{
    // prepare the list
    ListNode *head = new ListNode(4);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    ListNode *headPtr = sortList(head);

    printList(headPtr);

    return 0;
}