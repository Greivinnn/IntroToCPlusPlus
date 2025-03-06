#include <iostream>
#include <set>

int main()
{
    std::set<int> dataStructure6 = { 44, 23, 1, 4, 2 };

    dataStructure6.insert(33);

    for (int num : dataStructure6)
    {
        std::cout << num << "\n";
    }

    std::set<std::string> cars = { "BMW", "Volvo", "Ferrari", "Kia" };
    for (std::string name : cars)
    {
        std::cout << name << "\n";
    }

    if (dataStructure6.find(29) != dataStructure6.end())    // will look for 29 in the list if not found then it will not run
    {
        std::cout << "Element found";
    }
}
