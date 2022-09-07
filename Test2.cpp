#include<iostream>
using namespace std;

//code to check the size of the structure and resetting the memory

struct Node {
   int year_of_birth;
   int aadhar_number;
   int current_salary;
   char gender;
};


Node* get_new_node() {
    Node* new_node_ptr = (Node*)malloc(sizeof(Node));
    //assign the default params
    new_node_ptr->year_of_birth=1988;
    new_node_ptr->aadhar_number=12345678;
    new_node_ptr->current_salary=23400;
    new_node_ptr->gender='M';
    cout<<"\n Before checking the size of the node: "<<sizeof(Node);
    return new_node_ptr;
}

void display_node(const Node* ptr) {
   cout<<"\n User Information:";
   cout<<"\n Birth Year: "<<ptr->year_of_birth;
   cout<<"\n Aadhar Number: "<<ptr->aadhar_number;
   cout<<"\n Current Salary : "<<ptr->current_salary;
   cout<<"\n Gender : "<<ptr->gender;
   cout<<"\n";
}

int main(int argc, char** argv) {
   Node* temp_ptr = get_new_node();
   Node* userPtr[10];
   for(int i=0;i<10;i++) {
     userPtr[i]=get_new_node();
   }
   display_node(temp_ptr);
   for(int i=0;i<10;i++) {
      display_node(userPtr[i]);
   }
   
   //checking with double pointer
   Node** ptr;
   for(int i=0;i<5;i++) {
       *ptr=get_new_node();
       ptr++;
    }
   for(int i=0;i<5;i++) {
      display_node(ptr[i]);
    }


   return 0;
}
