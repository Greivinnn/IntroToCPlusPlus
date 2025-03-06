#include <iostream>
#include <list>

int main()
{
    std::list<int> dataStructure2 = { 1, 2, 3, 2};
    dataStructure2.push_front(0);   // add to the beginning
    dataStructure2.push_back(4);    // add to the end 

    dataStructure2.remove(2); // removes all 2 in the list

    dataStructure2.pop_back(); // deletes the last element
    dataStructure2.pop_front(); // delete the first element

    for (int num : dataStructure2)
    {
        std::cout << num << "\n";
    }
}

