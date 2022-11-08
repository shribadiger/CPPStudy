#include<iostream>
using namespace std;

class DataHandler
{
   private:
      int _memoryCounter;
      char* _allocatedRef;
      char* _fixedAllocatedMemory;
   public:
        //memory setting and getting functions
       int get_memory_counter();
       void set_memory_counter(int memCount);

       /*allocation reference*/
       char* getAllocationReference();
       void setAllocationReference(char* allocRef);

        /* fixed memory allocation */
        char* getFixedMemoryAllocation();
        void setFixedMemoryAllocation(char* fixMemRef);
};

       