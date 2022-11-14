/*
 Queue is a collection of elements which follows the first-in and first-out method. Each element in queue which inserted first that will be removed and processed for next operation
*/

#include <iostream>
#include <queue>
using namespace std;

struct Node
{
  int data;
  Node *next;
  // Node* prev;
};

typedef struct Node NODE;

class CustomQueue
{
private:
  NODE *head;
  NODE *tail;
  int numberOfNode;

public:
  CustomQueue(); // construction of Queue
  virtual ~CustomQueue();
  NODE *getHead();
  NODE *getTail();
  int getNumberOfNodes();

  void EnQueue(int value);
  int DeQueue();
  bool isEmpty();
  bool isFull();
  int peek(); // getting the element at beging of the queue
};
