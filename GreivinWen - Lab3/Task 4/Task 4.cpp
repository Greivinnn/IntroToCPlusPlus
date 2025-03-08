#include <iostream>
#include <map>
#include <string>

void DisplayInfo(std::map<std::string, int>& people)
{
    system("cls");
    for (const std::pair<std::string, int>& pair : people)
    {
        std::cout << pair.first << " score: " << pair.second << "\n";
    }
    std::cout << "\n";
    system("pause");
}

void EditPlayer(std::map<std::string, int>& people)
{
    system("cls");

    std::string playerName;
    int newScore;

    std::cout << "Which player would you like to edit? (enter key): ";
    std::cin >> playerName;

    if (people.find(playerName) != people.end())
    {
        std::cout << playerName << " current score: " << people[playerName] << "\n\n";

        std::cout << "Enter new score for " << playerName << ": ";
        std::cin >> newScore;

        people[playerName] = newScore;

        std::cout << "Score updated successfully.\n\n";
    }
    else
    {
        std::cout << "Player not found.\n\n";
    }
    system("pause");
}

void AddPlayer(std::map<std::string, int>& people)
{
    system("cls");

    std::string newName;
    int score;

    while (1)
    {
        std::cout << "Enter New Player name: ";
        std::cin >> newName;

        // Check if the name already exists
        if (people.find(newName) != people.end())
        {
            std::cout << "Player name already exists. Please enter a different name.\n";
        }
        else
        {
            break;
        }
    }

    std::cout << "Enter New Score for " << newName << ": ";
    std::cin >> score;

    people.insert({ newName, score });
    std::cout << "Successfully created new player\n";
    system("pause");
} 

void StartMenu(std::map<std::string, int>& people)
{
    while (1)
    {
        system("cls");
        std::cout << "Task 4\n\n";

        int choice;

        std::cout << "1. Add new player\n";
        std::cout << "2. Update existing player info\n";
        std::cout << "3. Display all players\n";
        std::cout << "4. Exit\n\n";
        std::cout << "choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            AddPlayer(people);
        }
        else if (choice == 2)
        {
            EditPlayer(people);
        }
        else if (choice == 3)
        {
            DisplayInfo(people);
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            std::cout << "\nInvalid choice\n";
            continue;
        }
    }
    
}

int main()
{
    std::map<std::string, int> people = { {"John", 32}, {"Adele", 45}, {"Bob", 29} };
    StartMenu(people);
}
