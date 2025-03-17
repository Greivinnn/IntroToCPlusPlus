#include <iostream>
#include <vector>

void RemoveDuplicates(std::vector<int>& numbers)
{
    std::vector<int> uniqueNumbers; // make a new vector to store the repeated numbers only once
    for (int number : numbers)  // iterate through the original numbers vector
    {
        bool isDuplicate = false;   // make a bool to check if the number is duplicated or not
        for (int unique : uniqueNumbers)    // iterate through unique number
        {
            if (number == unique)   // if unique == number that means we have a duplicate 
            {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate)   // if not duplicated push it back to the uniqueNumber vector (temporary vector)
        {
            uniqueNumbers.push_back(number);
        }
    }
    numbers = uniqueNumbers;    // finally edit the original vector removing the repeated numbers and only keeping them once
}

void RunCode()
{
    std::vector<int> numbers;

    while (1)
    {
        
        int number;
        std::cout << "Enter numbers (0 to exit): ";
        std::cin >> number;
        if (number == 0)
        {
            break;
        }
        else
        {
            numbers.push_back(number);
        }
    }
    
    RemoveDuplicates(numbers);

    std::cout << "Vector Backwards\n\n";

    for (int num : numbers)
    {
        std::cout << num;
    }
}

int main()
{
    RunCode();
}
