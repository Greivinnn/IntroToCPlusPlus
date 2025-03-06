#include <iostream>
#include <deque>

int main()
{
    std::deque<int> dataStructure5;

    dataStructure5.push_back(10);
    dataStructure5.push_back(20);
    dataStructure5.push_back(30);
    dataStructure5.push_back(40);

    dataStructure5.pop_back();

    for (int num : dataStructure5)
    {
        std::cout << num << "\n";
    }
}
