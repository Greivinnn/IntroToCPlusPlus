#include <iostream>

int main()
{
    int a = 10; // memory is allocated on stack
    // BankAccount b; // this is in stack as well
    
    // Stack is the memory partition that is statically allocated
    // Heap is the memory partion that is dynamically allocated

    // In C and can be use in C++ as well // Malloc and free the pointers
    int* var = (int*)malloc(sizeof(int)); // this is allocated in the heap, this is the c way
    free(var);
    var = nullptr;

    //In C++ only // Malloc and free the pointers
    int* cppVar = new int;  // this is allocated in the heap, is the malloc code above but the C++ way
    delete cppVar;
    cppVar = nullptr;

    return 0;
}
