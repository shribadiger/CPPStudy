/*
 * This is program to illustrate about the custom Heap allocation
 */
#include <iostream>
#include <iomanip>
using namespace std;

struct MemoryInformation
{
    struct MemoryInformation *next;
    size_t size; // size of allocation
    bool isFree; // checking flag whether it free or busy in allocation status
};

class CustomHeap
{
private:
    struct MemoryInformation *root; // root node of memory informaiton handler
    char *EndOfCustomMemory;
    CustomHeap();                           // private constructor to handle the single object
    static void *operator new(size_t size); // custom new opeation to handle allocation
    void setupRootNode();

public:
    ~CustomHeap();
    void clearCustomHeap();
    void *acquireCustomMemory(size_t size);       // utility to acquire memory from the custom location
    bool releaseCustomMemory(void *memoryObject); // utility to release allocated memory back to free store
    void customMemoryDump();                      // utility to provide the custom memory information in readble format
    static CustomHeap *getCustomHeapInstance();   // singleton class object to handle acquire and release operations
};

static const size_t MAX_CUSTOM_HEAP_SIZE = 10240;
static char customMemoryLayout[MAX_CUSTOM_HEAP_SIZE];
static char customMemoryObject[sizeof(CustomHeap)];

void CustomHeap::setupRootNode()
{
    this->root = reinterpret_cast<MemoryInformation *>(&customMemoryLayout[0]);
    this->root->next = nullptr;
    this->root->isFree = true;
    this->root->size = MAX_CUSTOM_HEAP_SIZE;
    this->EndOfCustomMemory = &customMemoryLayout[MAX_CUSTOM_HEAP_SIZE - 1];
}
CustomHeap::CustomHeap()
{
    cout << "\n CustomHeap::CustomHeap() started";
    // step1: clear the pre-allocated memory
    clearCustomHeap();
    setupRootNode();
    cout << "\n CustomHeap::CustomeHeap() completed";
}

CustomHeap::~CustomHeap()
{
    clearCustomHeap(); // de-allocate before deleting the singleton object
    cout << "\nCustomHeap::~CustomHeap()";
}

void CustomHeap::clearCustomHeap()
{
    for (auto &itr : customMemoryLayout)
    {
        itr = static_cast<char>(0); // assign the allocation memory to zero in CustomMemoryLayout
    }
    return;
}

void *CustomHeap::acquireCustomMemory(size_t requiredSize)
{
    // acquiring the memory layout
    char *_memory = nullptr;
    MemoryInformation *memoryBlockInfo = root; // assign the first root to iterate
    do
    {
        // This check helps to identify the block size and free locations
        if (memoryBlockInfo->isFree && memoryBlockInfo->size >= requiredSize)
        {
            // 1. found the free location to store values into memory - allocate memory block
            _memory = reinterpret_cast<char *>(memoryBlockInfo + 1);
            // 2. updating the memory block informations
            memoryBlockInfo->size = requiredSize;
            memoryBlockInfo->isFree = false;

            // 3. Now, need to update the next memory block information and update the memory list
            if (memoryBlockInfo->next != nullptr)
            {
                MemoryInformation *temp = reinterpret_cast<MemoryInformation *>(memoryBlockInfo->next);
                // checking the memory size that can fit inbetween the list
                size_t remainingSize = size_t(((size_t)temp) - (((size_t)(_memory + requiredSize)) + ((size_t)1)));
                if (remainingSize > sizeof(MemoryInformation))
                {
                    MemoryInformation *newMemObj = reinterpret_cast<MemoryInformation *>(_memory + requiredSize);
                    newMemObj->next = temp;
                    newMemObj->isFree = true;
                    newMemObj->size = remainingSize - sizeof(MemoryInformation);
                    memoryBlockInfo->next = newMemObj;
                }
                // if not we can allocate the memory block here to acquire
            }
            else if (size_t(_memory) + requiredSize < size_t(EndOfCustomMemory))
            {
                // checking the future custom memory end location
                size_t remaingEndSize = size_t(EndOfCustomMemory) - (size_t(_memory) + requiredSize) + size_t(1);
                if (remaingEndSize > sizeof(MemoryInformation))
                {
                    MemoryInformation *newMemObj = reinterpret_cast<MemoryInformation *>(_memory + requiredSize);
                    newMemObj->next = nullptr;
                    newMemObj->isFree = true;
                    newMemObj->size = remaingEndSize - sizeof(MemoryInformation);
                    memoryBlockInfo->next = newMemObj;
                }
            }
            break;
        }
        memoryBlockInfo = memoryBlockInfo->next;
    } while (memoryBlockInfo != nullptr);

    return reinterpret_cast<void *>(_memory);
}

bool CustomHeap::releaseCustomMemory(void *_memory)
{
    char *mem = reinterpret_cast<char *>(_memory);
    bool releaseStatus = false;
    if ((unsigned int)(mem) < (unsigned int)(customMemoryLayout))
    {
        std::cout << "\n[Error]: Invalid memory access";
        return releaseStatus;
    }

    MemoryInformation *memoryBlockInfo = root;
    MemoryInformation *requiredMemoryBlock = reinterpret_cast<MemoryInformation *>(mem) - 1;
    do
    {
        if (memoryBlockInfo == requiredMemoryBlock)
        {
            cout << "\n[Log]: Found the release memory slot";
            memoryBlockInfo->isFree = true;
            for (int i = 0; i < memoryBlockInfo->size; i++)
            {
                mem = char(0); // assign the zero's to memory block
            }
            releaseStatus = true;
            break;
        }
        memoryBlockInfo = memoryBlockInfo->next;
    } while (memoryBlockInfo != nullptr);
}

void CustomHeap::customMemoryDump()
{
    int index;
    cout << "\n Custom Memory Layout Details:";
    for (auto byte : customMemoryLayout)
    {
        cout << "\n Byte - " << dec << index << ":" << hex << "0x" << (0xFF & (unsigned int)byte) << endl;
    }
    cout << "\n";
}

void *CustomHeap::operator new(size_t size)
{
    return reinterpret_cast<void *>(customMemoryObject);
}

CustomHeap *CustomHeap::getCustomHeapInstance()
{
    static bool init = false;
    static CustomHeap *heapObj = nullptr;
    if (init == false)
    {
        heapObj = new CustomHeap();
        init = true;
    }

    return heapObj;
}
