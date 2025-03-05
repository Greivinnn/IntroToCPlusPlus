#include <iostream>
#include <array>

int main()
{
    std::array<int, 10> arr;

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = i * 2;
    }
    for (int val : arr)
    {
        std::cout << val << '\n';
    }
}