#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec; // dynamic array, no size needed and can put numbers in it

    vec.reserve(20);

    for (int i = 0; i < 4; i++)
    {
        vec.push_back(i);
    }
}