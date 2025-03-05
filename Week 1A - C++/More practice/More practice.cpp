#include <iostream>

int main()
{
    /*int num1, num2;

    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;
    std::cout << "\n";

    std::cout << "Addition of " << num1 << " and " << num2 << " is: " << num1 + num2;
    std::cout << "\n";
    std::cout << "Subtraction of " << num1 << " and " << num2 << " is: " << num1 - num2;
    std::cout << "\n";
    std::cout << "Multiplication of " << num1 << " and " << num2 << " is: " << num1 * num2;
    std::cout << "\n";
    std::cout << "Division of " << num1 << " and " << num2 << " is: " << num1 / num2;
*/

    float orangePrice = 2.59;
    float totalPrice;

    std::cout << "Oranges are 2.59 dollars each \n" << "You bought 10 oranges, here is your receipt \n\n";
    
    totalPrice = orangePrice * 10;

    std::cout << "-------------------------------------------- \n";
    std::cout << "Save-ON-Foods \n\n";
    std::cout << "Amount    Items       Total \n\n";
    std::cout << "10        Orange      " << totalPrice << "\n\n";
    std::cout << "---------------------------- \n";
    std::cout << "Amount due:           " << totalPrice << "\n\n";
    std::cout << "-------------------------------------------- \n";
    

}

