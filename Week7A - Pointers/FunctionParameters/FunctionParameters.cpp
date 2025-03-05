#include <iostream>
#include <string>

//Pass by value // changes the value within the function, as soon as the function ends it goes back to the original value 
//Pass by reference or address // actually changes the value
//Pass by pointer // actually changes the value 

void F1(std::string s)
{
    s = "abc";
}

// Pass by reference to a const
void F2(const std::string& s)
{
    std::cout << "Print s: " << s << "\n";
    // we do this to manage our allocation memory
    // const keeps the string bytes at always 4
}

void F3(int n)  // since int is already 4 bytes we do not need to call const here
{
    std::cout << "Print int n: " << n << "\n";
}

// Pass by pointer to const
void F4(const std::string* sPtr)
{
    if (sPtr != nullptr)
    {
        std::cout << "Print value: " << *sPtr << "\n";
    }
    std::string temp = "abc";
    sPtr = &temp;   // allowed change where the pointer points at

    // Passing by pointer lets us check for nullptr, and if is not nullptr we execute 
}

int main()
{
    const std::string text = "hello world";
    const std::string* texts = &text;
    F1(text); 
    F4(texts);
}
