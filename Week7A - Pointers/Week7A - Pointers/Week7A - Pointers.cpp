#include <iostream>
#include "BankAccount.h"

void Dummy()
{
    BankAccount bankAccount;

    BankAccount* b = &bankAccount;
}

int main()
{
    //Basic Pointers Stuff

    int a = 10;
    
    int* ptr = &a;
    
    std::cout << a << "\n"; //this prints the number 10
    
    std::cout << ptr << "\n"; // this prints the address where 10 is store

    std::cout << *ptr << "\n"; // this prints whatever ptr is pointing at
    
    Dummy();

    return 0;
}