#include <iostream>

int main()
{
    std::string studentName;
    char studentLastName[20];
    int testGrades[2];
    std::cout << "What is your name? \n";
    std::cin >> studentName;
    std::cout << "What is your last name? \n";
    std::cin >> studentLastName;
    std::cout << "What grade did you got on your midterm? ";
    std::cin >> testGrades[0];
    std::cout << "What did you get on your final test? ";
    std::cin >> testGrades[1];
    std::cout << "Your full name is " << studentName << " " << studentLastName << "\n" << "and you got a " << testGrades[0] << " on your midterm and a " << testGrades[1] << " on your final test" << "\n";

    return 0;
}

