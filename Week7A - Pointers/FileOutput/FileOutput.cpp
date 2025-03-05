#include <iostream>
#include <fstream>

void WriteFormatted(std::ofstream& file, int value)
{
	for (int i = 0; i < value; i++)
	{
		file << "Value: " << i << "\n"; // Write to a file
	}
}

int main()
{
	std::ofstream outFile("output.txt");	// to read files, ifstream 

	// Coordinate (x, y)

	if (!outFile)
	{
		std::cout << "Error\n";
		return -1;
	}

	int value;
	std::cout << "Enter the number of values to write: ";
	std::cin >> value;

	WriteFormatted(outFile, value);

	outFile.close();

	return 0;
}
