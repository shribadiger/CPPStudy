/*
 * This Program illustrate about the memory pool and how we can
 * customize the memory allocation mechanism in c++ application
 */
#include<iostream>
#include<cstdlib>
#include<new>
#include <cassert>
#include<string>

class MemoryPool {
        public:
                /* Constrution of Memory Block*/
                MemoryPool(std::size_t sz ,std::string name);

                /*Destruction of Memory Block*/
                ~MemoryPool();

                /* Check and return the current memory Block*/
                static MemoryPool& current() {
                        return *_curr;
                }

                /* Function to allocate the Memory Block with proper allignment*/
                void* allocate(std::size_t sz, std::size_t allignment);

        private:
                /* Memory Pointer to handle allocation*/
                char* _memory; // char pointer enable the pointer aithmentic :)
                char* _free;  // holds the pointer in which memory should be deleted
                char* _end;   // End of the address space which is used for allocation
                std::string _name;

                MemoryPool *_prev;  // Pointer which points to previouly allocated memory to extend the next allocation
                static MemoryPool* _curr; // Current address where the MemoryBlock is allocated

                /* Prohibiting the memory copy by non-implemented functions*/
                MemoryPool(MemoryPool const&);
                MemoryPool& operator=(MemoryPool const&);
};

/* Declare the static _curr member variable*/
MemoryPool* MemoryPool::_curr=0;

/* Constructor Defintion*/
MemoryPool::MemoryPool(std::size_t size , std::string name) :
        _memory(static_cast<char*>(::operator new (size))),
        _free(_memory),
        _end(_memory+size)
{
        std::cout<<"\n _MemoryPool_ constrution\n";
        _prev=_curr;
        _curr=this;
        _name=name;
        std::cout<<"\n Total Memory Pool Size: "<<size <<" & Name: "<<name;
}

/* Destruction Definition*/
MemoryPool::~MemoryPool() {
        std::cout<<"\n _MemoryPOol_ destruction of "<<_name<<"\n";
        ::operator delete (_memory);
        _curr=_prev;
}

/* Allocation of Mmeory*/
void* MemoryPool::allocate(std::size_t size, std::size_t alignment) {
        std::cout<<"\n Allcation of memory with size : "<<size<<"from name:"<<_name<<"\n";
        char* start = _free;

        /* Align the Pointer*/
        std::size_t extra = (start - _memory)%alignment;
        if(extra != 0 ) {
                extra = alignment + extra;
        }

        /* check whether we allocate proper memory */
        if((_end - _free) < (size + extra))
                throw std::bad_alloc();


        // free menory will start after the allocation of memory
        _free = start + size + extra;
        return start;
}

/* Simple structure to show the example of allocation function*/
struct simpleStruct  {
        int member;
        void* operator new (std::size_t );
        void operator delete (void*) {}
};

void* simpleStruct::operator new (std::size_t size) {
        return MemoryPool::current().allocate(size, size);
}



int main() {
        MemoryPool myMemoryPool(3*sizeof(simpleStruct), "firstBlock");


        simpleStruct* p1 = new simpleStruct;

        simpleStruct* p2 = new simpleStruct;

        simpleStruct* p3 = new simpleStruct;

        delete p3;

        MemoryPool secondMemoryPool(100*sizeof(simpleStruct),"secondBlock");

        try {
                simpleStruct* p4 = new simpleStruct;
        }
        catch (...) {
                std::cout<<"\n Exception catched\n";
        }

        simpleStruct* p5 = new simpleStruct[10];


        simpleStruct* p6 = new simpleStruct;
        simpleStruct* p7 = new simpleStruct;

        return 0;
}
