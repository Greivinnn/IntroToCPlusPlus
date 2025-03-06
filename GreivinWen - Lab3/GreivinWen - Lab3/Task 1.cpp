#include <iostream>
#include <vector>

void CalculateAvg(std::vector<int> numbers)
{
	int total = 0;
	int size = numbers.size();
	size -= 1;
	for (int num : numbers)
	{
		total += num ;
	}
	
	double newTotal;
	newTotal = total / size;
	std::cout << "The average is: " << newTotal << "\n";
	
	for (int num : numbers)
	{
		if (num > newTotal)
		{
			std::cout << "These number(s) are bigger than the average: " << num << "\n";
		}
	}
}

int main()
{
	std::vector<int> numbers;

	while (1)
	{
		int userInput;
		std::cout << "Enter number (-1 to exit): ";
		std::cin >> userInput;

		numbers.push_back(userInput);

		if (userInput == -1)
		{
			break;
		}
	}
	CalculateAvg(numbers);
}