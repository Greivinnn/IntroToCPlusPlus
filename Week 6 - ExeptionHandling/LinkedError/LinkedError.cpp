#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers;

    try
    {
        std::cout << "Attemptin to access beyond the vector size...\n";
        numbers.resize(numbers.max_size() + 1);
    }
    catch (std::length_error ex)
    {
        std::cout << "Caught an exption " << ex.what();
    }
}
