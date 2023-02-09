/*
Code to check the functional call back for the specific functional loader 
*/
#include<iostream>
using namespace std;

int callingAllocation(int first, int second) {
    cout<<"\n Calling Allocation from "<<first<<" -- "<<second<<endl;
    return 0;
}

int callingDeallocation(int first=0,int second=0) {
    cout<<"\n Calling Deallocaiton from "<<first<<"---"<<second<<endl;
    return 0;
}

// Passing the function Pointer as input to another function
void functionInvoke(int (*funcPtr)(int x,int y)) {
   cout<<"\n Calling the function from functionInvoke"<<endl;
   funcPtr(x,y);
}

int main() {
 
   // defining the functional pointer
   /* <return Type> (*<function pointer name>(param1, param2, param.....) */
   int (*funcPtr)(int,int); 

   //assign the function to function pointer
   funcPtr=callingAllocation;

   int retValue=funcPtr(10,11);

   cout<<"\n After completion of the function pointer invoke";

   cout<<"\n Invoke the function from the function invoker"<<endl;
  
   functionInvoke(funcPtr(12,13));

   funcPtr=callingDeallocation;

   functionInvoke(funcPtr());

   return 0;
}
