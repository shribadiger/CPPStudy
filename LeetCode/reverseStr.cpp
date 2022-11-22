/* Merge list checker*/
#include <iostream>
#include <map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int v) : val(v), next(nullptr) {}
};

ListNode *getMergeNode(ListNode *headA, ListNode *headB)
{
    map<ListNode *, int> AddressCounter;
    while (headA)
    {
        AddressCounter[headA]++;
        headA = headA->next;
    }
    while (headB)
    {
        if (AddressCounter[headB] == 1)
            return headB;
        headB = headB->next;
    }
    return nullptr;
}
int main()
{
    ListNode *headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    ListNode *headB = new ListNode(4);
    headB->next = headA->next;

    ListNode *res = getMergeNode(headA, headB);
    cout << "\n Node: " << res->val;
}