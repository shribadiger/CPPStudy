# CPPStudy
Repository for CPP understanding and Experiments.

1.  For Memory debug function. we have to follow the steps as mentioned below

    a. compile the program : gcc -g -o memoryDebug memoryDebug.c

    b. export MALLOC_TRACE=./mem_trace.log

    c. ./memoryDebug

    d. It will generate the memory related files, thats need to be analysed for memory leaks or memory related issue

    
    output: .
    ````
    root@sbadiger:/home/sbadiger/Program/C++# cat MemoryTraceFile.
    = Start.
    @ ./memoryDebug:[0x56284a5577b4] + 0x56284bed4450 0x118.
    @ /lib/x86_64-linux-gnu/libc.so.6:(_IO_file_doallocate+0x72)[0x7f9e92ba7a62] + 0x56284bed4570 0x400.
    = End.
    
    ````
    
    ``````
    ### Customized Memory Allocation :
    
    The Program to illustrate about customized memory allocation.
    
    
    
   ````
   Link for reference : http://www.tantalon.com/pete/cppopt/asyougo.htm
   
   ````
