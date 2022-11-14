/*
 * c++ code to implement the priority queue 
 */
#include<iostream>
using namespace std;


//define the structure to hold the data and priority
struct Node {
   int data;
   int priority;
   struct Node* next;
};

typedef struct Node NODE; // define the NODE to use the data structure.

NODE* getNewNode(int iData, int iPriority) {
   NODE* temp = (NODE*)malloc(sizeof(NODE));
   temp->data=iData;
   temp->priority=iPriority;
   temp->next = nullptr;
   return temp;
}

int peek(NODE** head) {
   return (*head)->data;
}

//Function: To pop the element from the priority queue
void pop(NODE** head) {
   NODE* temp = *head;
   (*head) = (*head)->next;
   free(temp);
}

//Function: To push the element into queue and re-order the priority
void push(NODE** head,int iData, int iPriority) {
   NODE* startNode = *head;
   //create new node to insert
   NODE* newNode = getNewNode(iData,iPriority);

   //case1: if the head had lesser priority that the new node add the node at begining of list
   if((*head)->priority >= iPriority) {
      newNode->next = (*head);
      (*head) = newNode;
   } 
   else {
      //case 2: if the priority is need to re-order the list
      while(startNode->next != nullptr && 
            startNode->next->priority < iPriority) {
           //move the node to next element
           startNode=startNode->next;
      }

      newNode->next=startNode->next;
      startNode->next=newNode;
  }
}


//Function: To check the empty queue
bool isEmpty(NODE** head) {
   if((*head)==nullptr) return true;
   return false;
} 


//Main: to call the priorty queue functions
int main() {
   //create the queue and insert the elements in side the list
   NODE* priorityQueue = getNewNode(4,1);
   push(&priorityQueue,5,2);
   push(&priorityQueue,6,3);
   push(&priorityQueue,8,0);
   push(&priorityQueue,1,2);
   push(&priorityQueue,2,3);
   push(&priorityQueue,4,0);

   //display from beginging
   NODE* itr = priorityQueue;
   while(itr != nullptr) {
      cout<<"\t"<<itr->data;
      itr=itr->next;
   }

   cout<<"\n";

   while(!isEmpty(&priorityQueue)) {
      cout<<"\t"<<peek(&priorityQueue);
      pop(&priorityQueue);
   }
   return 0;
}
