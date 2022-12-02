/* calling the remove nodes form the list */
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int v) : val(v), next(nullptr) {}
};

ListNode *RemoveNode(ListNode *list, int value)
{
    if (list == nullptr)
        return list;
    ListNode *returnNode = RemoveNode(list->next, value);
    if (list->val == value)
    {
        return returnNode;
    }
    else
    {
        list->next = returnNode;
        return list;
    }
}

void print_list(ListNode *list)
{
    ListNode *itr = list;
    while (itr)
    {
        cout << "\t" << itr->val;
        itr = itr->next;
    }
    cout << "\n";
}

int main()
{
    ListNode *list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(6);
    list->next->next->next = new ListNode(3);
    list->next->next->next->next = new ListNode(4);
    list->next->next->next->next->next = new ListNode(6);
    print_list(list);
    list = RemoveNode(list, 6);
    print_list(list);
    return 0;
}
