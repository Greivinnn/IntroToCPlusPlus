#include <iostream>
#include <queue>

int main()
{
    std::queue<int> dataStructure4;

    //adding elements
    dataStructure4.push(10);
    dataStructure4.push(20);
    dataStructure4.push(30);
    dataStructure4.push(40);

    dataStructure4.pop(); //this will remove the first element in this case 10

    dataStructure4.back(); // this is 10 because we stack the numbers 
    dataStructure4.front(); // this is 40, 40 is our new front
}
