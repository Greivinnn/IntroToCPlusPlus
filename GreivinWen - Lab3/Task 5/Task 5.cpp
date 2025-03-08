#include <iostream>
#include <queue>
#include <string>

struct Customer
{
    std::string customerName;
    std::string customerIssue;
};

void AddCustomer(std::queue<Customer>& customerQueue)
{
    system("cls");

    Customer newCustomer;
    std::cout << "Enter your name: ";
    std::cin >> newCustomer.customerName;
    std::cin.ignore(); // ignores the blank line made by the cin above so we can execute the getline below
    std::cout << "\nWhat is the current issue you are having with us?\n";
    std::getline(std::cin, newCustomer.customerIssue);  // use a getline instead of a cin when working with spaces

    customerQueue.push(newCustomer);    // push the new customer we made to the queue
    std::cout << "Customer added successfully.\n\n";
    system("pause");
}

void ServeNextCustomer(std::queue<Customer>& customerQueue)
{
    system("cls");

    try
    {
        if (customerQueue.empty())
        {
            throw std::out_of_range("No customers in the queue at the moment.\n\n");
        }

        Customer nextCustomer = customerQueue.front();
        customerQueue.pop();
        std::cout << "Serving customer: " << nextCustomer.customerName << "\n";
        std::cout << "Issue: " << nextCustomer.customerIssue << "\n";
    }
    catch (std::out_of_range error)
    {
        std::cout << error.what() << "\n";
    }

    system("pause");
}

void DisplayRemainingCustomers(const std::queue<Customer> customerQueue)
{
    system("cls");

    if (customerQueue.empty())   //always check if the queue is empty or not
    {
        std::cout << "No remaining customers.\n\n";
    }
    else
    {
        std::queue<Customer> tempQueue = customerQueue; // Create a copy of the queue to iterate through
        while (!tempQueue.empty())
        {
            Customer currentCustomer = tempQueue.front();
            std::cout << "Name: " << currentCustomer.customerName << ", Issue: " << currentCustomer.customerIssue << "\n";
            tempQueue.pop();
        }
    }
    system("pause");
}

int main()
{
    std::queue<Customer> customerQueue; // make a queue of our Customer struct 

    while (1)
    {
        system("cls");
        int choice;
        std::cout << "Baller Customer Service\n\n";

        std::cout << "1. Add an inquiery\n";
        std::cout << "2. Serve next customer\n";
        std::cout << "3. Display remaining customers\n";
        std::cout << "4. Exit\n\n";

        std::cout << "choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            AddCustomer(customerQueue);
        }
        else if (choice == 2)
        {
            ServeNextCustomer(customerQueue);
        }
        else if (choice == 3)
        {
            DisplayRemainingCustomers(customerQueue);
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            continue;
        }
    }
    
}
