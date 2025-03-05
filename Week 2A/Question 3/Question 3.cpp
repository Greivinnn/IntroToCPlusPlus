#include <iostream>
#include <array>

struct Person
{
    std::string name;
    int age;
    std::string address;
    std::string hobby;
};

void printEverything(std::array<Person, 3> persons)
{
    std::cout << "Array Elements:" << "\n\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Name: " << persons[i].name << "\n" << "Age: " << persons[i].age << "\n" << "Address: " << persons[i].address;
        std::cout << "\n-------------------------------------------------------------------------------------------------------\n";
    }
}

void averageAge(std::array<Person, 3> persons)
{
    int average;
    int sum = 0;
    
    for (int i = 0; i < 3; i++)
    {
        sum = sum + persons[i].age;
    }
    average = sum / 3;

    std::cout << "The age average in here is: " << average;
}

int main()
{
    Person personOne;
    Person personTwo;
    Person personThree;

    personOne.age = 40;
    personTwo.age = 66;
    personThree.age = 18;

    personOne.name = "Carlos";
    personTwo.name = "Juan";
    personThree.name = "Santi";

    personOne.address = "Miami";
    personTwo.address = "Vancouver";
    personThree.address = "Cancun";

    personOne.hobby = "Skateboard";
    personTwo.hobby = "Snowboard";
    personThree.hobby = "Surf";

    std::array<Person, 3> persons = { personOne, personTwo, personThree };

    printEverything(persons);
    averageAge(persons);
}
