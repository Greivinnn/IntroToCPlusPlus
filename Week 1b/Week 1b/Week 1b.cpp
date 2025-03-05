#include <iostream>

// switch notes

int main()
{
    int num1, num2, option;

    std::cout << "Enter a number: ";
    std::cin >> num1;
    std::cout << "Enter another number: ";
    std::cin >> num2;
    std::cout << "Choose an operation sign: \n1. Addition \n2. Substraction\n3. Multiplication\n4.Division\n";
    std::cin >> option;

    switch (option)
    {
    case 1:
    {
        std::cout << "Result: " << num1 + num2 << "\n";
        break;
    }
    case 2:
    {
        std::cout << "Result: " << num1 - num2 << "\n";
        break;
    }
    case 3:
    {
        std::cout << "Result: " << num1 * num2 << "\n";
        break;
    }
    case 4:
    {
        if (num2 != 0)
        {
            std::cout << "Result: " << num1 / num2 << "\n";
        } 
        else
        {
            std::cout << "Division by zero not allowed";
        }
        break;
    }
    default:
    {
        std::cout << "Invalid selection";
    }
    }
    
}