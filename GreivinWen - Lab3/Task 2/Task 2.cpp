#include <iostream>
#include <stack>
#include <string>

void PrintStack(std::stack<std::string> stack)  // this is how you print a stack
{
    // Transfer elements to a temporary stack and print them
    while (!stack.empty())  //while original stack is not empty, we will proceed with: 
    {
        std::string word = stack.top(); // gets the first word of the stack and stores it in a string
        std::cout << "\n" << word;  // prints that string, current stack.top
        stack.pop();    // erase the current stack.top so the next one is the next element 
    }
    std::cout << "\n";
    system("pause");
}

int main()
{
    std::stack<std::string> words;

    while (1)
    {
        system("cls");
        std::cout << "Text editor (done to exit)\n\n";

        std::string userInput;
        std::cin >> userInput;
        if (userInput == "undo")
        {
            if (!words.empty())
            {
                words.pop();
            }
            else
            {
                std::cout << "Warning: nothing to undo yet.\n\n";
            }
        }
        else if (userInput == "done")
        {
            break;
        }
        else
        {
            words.push(userInput);
        }
        PrintStack(words);
    }
}