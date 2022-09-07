#include "QueueImplementation.h"
using namespace std;

#define max_queue_size 1024
// Maximum number of nodes are defined is 1024
const string enqueError = " Failed to EnQueue data";
const string dequeueError = " Failed to DeQueue data";
CustomQueue::CustomQueue()
{
    cout << "\n[Log]: Initialization of Custom Queue";
    this->head = nullptr;
    this->tail = this->head;
    this->numberOfNode = 0;
}

CustomQueue::~CustomQueue()
{
    delete head;
    delete tail;
}

NODE *CustomQueue::getHead()
{
    return head;
}

NODE *CustomQueue::getTail()
{
    return tail;
}

int CustomQueue::getNumberOfNodes()
{
    return numberOfNode;
}

void CustomQueue::EnQueue(int data)
{
    try
    {
        if (tail != nullptr)
        {
            tail->next = (NODE *)malloc(sizeof(NODE));
        }
        else
        {
            tail = (NODE *)malloc(sizeof(NODE));
            head = tail;
        }
        tail->data = data;
        tail->next = nullptr;
        numberOfNode++;
    }
    catch (...)
    {
        throw enqueError;
    }
}

int CustomQueue::DeQueue()
{
    try
    {
        if (head == nullptr)
            return -1;
        int retValue = head->data;
        NODE *temp = head;
        head = head->next;
        delete temp;
    }
    catch (...)
    {
        throw dequeueError;
    }
}

bool CustomQueue::isEmpty()
{
    if (numberOfNode == 0)
        return true;
    return false;
}

bool CustomQueue::isFull()
{
    if (numberOfNode == 1024)
    {
        return true;
    }
    return false;
}
