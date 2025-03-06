#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<std::string, int> people = { {"John", 32}, {"Adele", 45}, {"Bo", 29} };

    people["Alice"] = 10;   // the name is the key and the number is the value 

    people.insert({ "Jenny", 22 });

    people.erase("John");   // deletes john 

    people.find("Adele");   // find someone in the Map

    if (people.find("Adele") != people.end())
    {
        // found adele
        std::cout << "Person found!\n";
    }

    for (const std::pair<std::string, int>& pair : people)
    {
        std::cout << pair.first << "\n";
    }
}
