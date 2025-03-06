#include <iostream>
#include <vector>

int main()
{
	std::vector<int> dataStructure1;
	dataStructure1.push_back(10);
	dataStructure1.push_back(20);
	dataStructure1.push_back(30);

	for (int num : dataStructure1)
	{
		std::cout << num << "\n";
	}

	//first element
	std::cout << "first element " << dataStructure1[0] << "\n";

	dataStructure1.pop_back(); // delete the last element

	for (int num : dataStructure1)
	{
		std::cout << num << "\n";
	}
}