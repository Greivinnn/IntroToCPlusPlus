#include <iostream>
#include <set>
#include <string>

int main()
{
    while (1)
    {
        std::string userInput;
        std::cout << "Write a paragraph for us (type 'done' to exit):\n\n";

        // Use getline instead of cin to read the entire paragraph
        std::getline(std::cin, userInput);

        if (userInput == "done")
        {
            break;
        }

        // Create a set to store unique words
        std::set<std::string> words;

        // Process the paragraph 
        std::string word;   // store the word one by one
        for (size_t i = 0; i < userInput.length(); ++i)
        {
            char c = userInput[i];  // gets the first character of the word

            // Check if character is a letter using the ASCII table
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            {
                // Convert uppercase to lowercase
                if (c >= 'A' && c <= 'Z')
                {
                    c = c - 'A' + 'a';  // Convert to lowercase
                }

                word += c;  // make the lower case word 
            }
            // If not a letter, treat as a word separator, this will work for space and numbers
            else if (!word.empty())
            {
                words.insert(word);
                word.clear();
            }
        }

        // Add the last word if there is one
        if (!word.empty())
        {
            words.insert(word);
        }

        system("cls");
        std::cout << "\nTotal number of unique words: " << words.size() << "\n";

        std::cout << "\nUnique words in alphabetical order:" << "\n";
        for (std::string uniqueWord : words)
        {
            std::cout << uniqueWord << "\n";
        }

        std::cout << "\n--------------------------\n" << "\n";
    }

    return 0;
}
