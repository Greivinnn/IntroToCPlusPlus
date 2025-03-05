#include <iostream>
#include <array>

struct Player
{
    int playerID;
};

int main()
{
    std::array<int, 5> arr = { 1, 2,3,4,5 };

    std::cout << *(arr.end() - 1);

    int arr2[10];

    for (int val : arr2)
    {

    }

    for (int value : arr)   // Range-based fir loop/foreach loop
    {
        std::cout << value << '\n';
    }

}

