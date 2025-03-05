#include <iostream>
#include <string>
#include <vector>

//Structs and Constructors
struct Customer
{
    Customer(int id, std::string name, std::string email, int phone);
    int customerId;
    std::string customerName;
    std::string customerEmail;
    int customerPhone;
};
struct Product
{
    Product(int id, std::string name, double price);
    int productId;
    std::string productName;
    double productPrice;
};
struct Basket
{
    std::vector<std::string> productNames;
    std::vector<double> productPrice;
    std::vector<int> productAmount;
    std::string customerName;
};

Product::Product(int id, std::string name, double price)
    :productId(id), productName(name), productPrice(price)
{
}

Customer::Customer(int id, std::string name, std::string email, int phone)
    : customerId(id), customerName(name), customerEmail(email), customerPhone(phone)
{
}
// --------------------------------------------------------------------------------

//  ACSII Art 
void PrintDoorArt()
{
    std::cout << "            __________\n";
    std::cout << "           |  __  __  |\n";
    std::cout << "           | |  ||  | |\n";
    std::cout << "           | |  ||  | |\n";
    std::cout << "           | |__||__| |\n";
    std::cout << "           |  __  __()|\n";
    std::cout << "           | |  ||  | |\n";
    std::cout << "           | |  ||  | |\n";
    std::cout << "           | |  ||  | |\n";
    std::cout << "           | |  ||  | |\n";
    std::cout << "           | |__||__| |\n";
    std::cout << "           |__________|\n";
}

void PrintAdminArt()
{
    system("cls");
    std::cout << "   __    ____  __  __  ____  _  _    ____   __    ___  ____ \n";
    std::cout << "  /__|  (  _ |(  |/  )(_  _)( |( )  (  _ | /__|  / __)( ___)\n";
    std::cout << " /(__)|  )(_) ))    (  _)(_  )  (    )___//(__)|( (_-. )__) \n";
    std::cout << "(__)(__)(____/(_/|/|_)(____)(_)|_)  (__) (__)(__)|___/(____)\n\n";
}

void PrintStoreArt()
{
    system("cls");
    std::cout << " ____  ____  ____  ___  _   _    __  __    __    ____   _  _  ____  ____ \n";
    std::cout << "( ___)(  _ |( ___)/ __)( )_( )  (  |/  )  |__|  (  _ | ( )/ ) |___)(_  _)\n";
    std::cout << " )__)  )   / )__) |__ | ) _ (    )    (  |(__)|  )   /  )  (  |)__)  )(  \n";
    std::cout << "(__)  (_)|_)(____)(___ ( (_) )  (_/|/|_)(__)|(_)(_)||_)(_)|_) |||_) (__) \n\n";
}
// --------------------------------------------------------------------------------

// Print functions
void PrintProductList(Product products)
{
    std::cout << products.productId << "  " << products.productName << "   $" << products.productPrice << "\n";
}

void PrintCustomerList(Customer customers)
{
    std::cout << customers.customerId << "  " << customers.customerName << "  " << customers.customerEmail << " / " << customers.customerPhone << "\n";
}

void PrintProductListInAdmin(std::vector<Product> products)
{
    PrintAdminArt();
    for (Product list : products)
    {
        PrintProductList(list);
    }
    std::string choice;
    std::cout << "\n\nPress any key to go back. ";
    std::cin >> choice;
}

void PrintCustomerListInAdmin(std::vector<Customer> customers)
{
    PrintAdminArt();
    for (Customer list : customers)
    {
        PrintCustomerList(list);
    }
    std::string choice;
    std::cout << "\n\nPress any key to go back. ";
    std::cin >> choice;
}
// --------------------------------------------------------------------------------

// Product Functions (ADD, DELETE, EDIT)
void AddNewProduct(std::vector<Product>& products)
{
    std::string choice;
    std::cout << "\n-----------------------------------------------------------";

    int productID;
    std::string productName;
    double productPrice;

    std::cout << "\n\nAdding a product...";
    std::cout << "\n\nEnter the product ID: ";
    std::cin >> productID;

    std::cout << "\nEnter the poducts name: ";
    std::cin >> productName;

    std::cout << "\nEnter the products price: ";
    std::cin >> productPrice;

    products.push_back(Product(productID, productName, productPrice));

    std::cout << "\n\nProduct added successfully!\n";

    for (Product list : products)
    {
        PrintProductList(list);
    }

    std::cout << "\n\nPress any key to go back. ";
    std::cin >> choice; // this is so the user can see the message after doing anything in the admin page, since system("cls") clears too fast for us to know if the implementation was made or not
}

void DeleteStoreProduct(std::vector<Product>& products)
{
    std::string choice;
    bool found = false;

    for (Product list : products)
    {
        PrintProductList(list);
    }

    int productID;

    std::cout << "\n-----------------------------------------------------------\n\n";
    std::cout << "What product would you like to delete? (enter productID) ";
    std::cin >> productID;

    for (int i = 0; i < products.size(); i++) 
    {
        if (products[i].productId == productID)
        {
            products.erase(products.begin() + i);
            std::cout << "\nProduct deleted successfully.\n\n";
            found = true;
            break;  // Stop searching after deletion
        }
    }
    if (!found)
    {
        std::cout << "ProductID not found.";
    }

    for (Product list : products)
    {
        PrintProductList(list);
    }

    std::cout << "\n\nPress any key to go back. ";
    std::cin >> choice;
}

void EditStoreProducts(std::vector<Product>& products)
{
    std::string choice;
    bool found = false;

    for (Product list : products)
    {
        PrintProductList(list);
    }

    int productID;

    std::cout << "\n-----------------------------------------------------------\n\n";
    std::cout << "What product would you like to edit? (enter productID) ";
    std::cin >> productID;

    for (int i = 0; i < products.size(); i++)
    {
        if (products[i].productId == productID)
        {
            found = true;
            std::cout << "Editing product with ID: " << productID << "\n";
            std::cout << "Current Product Name: " << products[i].productName << "\n";
            std::cout << "Enter new name: ";

            std::string newProductName;
            std::cin >> newProductName;

            if (!newProductName.empty())    // if not empty then edit name
            {
                products[i].productName = newProductName;
            }

            double newProductPrice;

            std::cout << "\nCurrent Product Price: $" << products[i].productPrice << "\n";
            std::cout << "Enter new price: ";
            std::cin >> newProductPrice;

            if (newProductPrice != -1)
            {
                products[i].productPrice = newProductPrice;
            }
            std::cout << "\nProduct updated successfully!\n\n";
            break;
        }
    }
    if (!found)
    {
        std::cout << "ProductID not found.";
    }

    for (Product list : products)
    {
        PrintProductList(list);
    }

    std::cout << "\n\nPress any key to go back. ";
    std::cin >> choice;
}
// --------------------------------------------------------------------------------

// Customers functions (ADD, DELETE,EDIT)
void AddNewCustomer(std::vector<Customer>& customers)
{
    std::string choice;
    std::cout << "\n-----------------------------------------------------------";

    int customerID;
    std::string customerName;
    int customerNumber;
    std::string customerEmail;

    std::cout << "\n\nAdding a new member...\n\n";
    std::cout << "Enter members ID: ";
    std::cin >> customerID;

    std::cout << "\nEnter members name: ";
    std::cin >> customerName;

    std::cout << "\nEnter members email: ";
    std::cin >> customerEmail;

    std::cout << "\nEnter members phone number: ";
    std::cin >> customerNumber;

    customers.push_back(Customer(customerID, customerName, customerEmail, customerNumber));

    std::cout << "\n\nNew member added successfully!\n";

    for (Customer list : customers)
    {
        PrintCustomerList(list);
    }

    std::cout << "\n\nPress any key to go back. ";
    std::cin >> choice;
}

void DeleteCustomer(std::vector<Customer>& customers)
{
    bool found = false;
    std::string choice;
    std::cout << "\n-----------------------------------------------------------";

    int customerID;
    std::cout << "\n\nWhat customer would you like to delete (enter memberID): ";
    std::cin >> customerID;

    for (int i = 0; i < customers.size(); i++)
    {
        if (customers[i].customerId == customerID)
        {
            customers.erase(customers.begin() + i);
            std::cout << "\Customer information deleted successfully.\n\n";
            found = true;
            break;  // Stop searching after deletion
        }
    }

    if (!found)
    {
        std::cout << "MemberID not found.";
    }

    for (Customer list : customers)
    {
        PrintCustomerList(list);
    }

    std::cout << "\n\nPress any key to go back. ";
    std::cin >> choice;
}

void EditCustomerInformation(std::vector<Customer>& customers)
{
    bool found = false;
    std::string choice;

    for (Customer list : customers)
    {
        PrintCustomerList(list);
    }
    std::cout << "\n-----------------------------------------------------------";

    int customerID;
    std::cout << "\n\nWhat customers information would you like to edit (enter memberID): ";
    std::cin >> customerID;

    for (int i = 0; i < customers.size(); i++)
    {
        if (customers[i].customerId == customerID)
        {
            found = true;
            std::cout << "Editing customer with ID: " << customerID << "\n";
            std::cout << "Current Customer Name: " << customers[i].customerName << "\n";
            std::cout << "Enter new name: ";

            std::string newCustomerName;
            std::cin >> newCustomerName;

            if (!newCustomerName.empty())    // if not empty then edit name
            {
                customers[i].customerName = newCustomerName;
            }

            std::cout << "\nCurrent Customer Email: " << customers[i].customerEmail << "\n";
            std::cout << "Enter new email: ";

            std::string newCustomerEmail;
            std::cin >> newCustomerEmail;

            if (!newCustomerEmail.empty())
            {
                customers[i].customerEmail = newCustomerEmail;
            }
            
            std::cout << "\nCurrent Customer Phone: " << customers[i].customerPhone << "\n";
            std::cout << "Enter new phone number: ";

            int newCustomerPhone;
            std::cin >> newCustomerPhone;

            if (newCustomerPhone != -1)
            {
                customers[i].customerPhone = newCustomerPhone;
            }

            std::cout << "\nCustomer information updated successfully!\n\n";
            break;
        }
    }

    if (!found)
    {
        std::cout << "MemberID not found.";
    }

    for (Customer list : customers)
    {
        PrintCustomerList(list);
    }

    std::cout << "\n\nPress any key to go back. ";
    std::cin >> choice;
}
// --------------------------------------------------------------------------------
int main()
{
    std::vector<Customer> customers =
    {
        Customer(1111, "David", "David@gmail.com", 23690874),
        Customer(1112, "Bobby", "Bobby@gmail.com", 22307895),
        Customer(1113, "Santi", "Santi@gmail.com", 98756493),
        Customer(1114, "Alfred", "Alfred@gmail.com", 89576493),
        Customer(1115, "Juan", "Juan@gmail.com", 94201674),
    };

    std::vector<Product> products =
    {
        Product(101, "Bread", 1.25),
        Product(102, "Sugar", 2.10),
        Product(103, "Beans", 1.00),
        Product(104, "Juice", 2.25),
        Product(105, "Flour", 1.75),
    };

    for (Product list : products)
    {
        PrintProductList(list);
    }

    bool isMember = false;
    int amountOfProduct = 0;
    int customerMemberID;
    int index = 0;
    double customerMoney;
    double customerChange;
    double subTotal = 0.0;
    double discoutedPrice;
    double totalAfterDiscount;
    std::string memberCheck;
    std::string CustomerName;
    std::string productName;
    std::string storeEnterInput;
    Basket storeBasket;

    PrintStoreArt();

    std::cout << "Welcome to Fresh Market!\nWhat is your name?\n";
    std::cin >> CustomerName;

    storeBasket.customerName = CustomerName;

    if (CustomerName.compare("Supersecret") == 0)  // secret word to access the admin page
    {
        int adminOption;

        while (1)
        {
            PrintAdminArt();

            std::cout << "Welcome back Admin. What are we going to do today?\n";
            std::cout << "1. Add new product\n2. Remove a product\n3. Edit a product\n4. Add new member\n5. Delete a member\n6. Edit a members information\n7. View products list\n8. View customers list\n9. Exit admin page\n\n";

            std::cin >> adminOption;

            if (adminOption == 1)
            {
                PrintAdminArt();
                for (Product list : products)
                {
                    PrintProductList(list);
                }
                AddNewProduct(products);
            }
            else if (adminOption == 2)
            {
                PrintAdminArt();

                DeleteStoreProduct(products);
            }
            else if (adminOption == 3)
            {
                PrintAdminArt();

                EditStoreProducts(products);
            }
            else if (adminOption == 4)
            {
                PrintAdminArt();
                for (Customer list : customers)
                {
                    PrintCustomerList(list);
                }
                AddNewCustomer(customers);
            }
            else if (adminOption == 5)
            {
                PrintAdminArt();
                for (Customer list : customers)
                {
                    PrintCustomerList(list);
                }
                DeleteCustomer(customers);
            }
            else if (adminOption == 6)
            {
                PrintAdminArt();

                EditCustomerInformation(customers);
            }
            else if (adminOption == 7)
            {
                PrintProductListInAdmin(products);
            }
            else if (adminOption == 8)
            {
                PrintCustomerListInAdmin(customers);
            }
            else if (adminOption == 9)
            {
                break;
            }

        }
    }

    PrintStoreArt();

    std::cout << CustomerName << " are you a Fresh Market member?\n";
    std::cout << "(yes/no): ";
    std::cin >> memberCheck;

    if (memberCheck.compare("yes") == 0)
    {
        std::cout << "\nWhat is your MemberID number? ";
        std::cin >> customerMemberID;
        int i = 0;

        for (Customer list : customers)
        {
            i++;
            if (list.customerId == customerMemberID)
            {
                isMember = true;
                index = i;
                break;
            }

        }

        if (isMember)
        {
            PrintStoreArt();
            std::cout << "Welcome back! " << customers[index].customerName << "\n";
            std::cout << "Phone Number: " << customers[index].customerPhone << "\n";
            std::cout << "Email: " << customers[index].customerEmail << "\n\nEnjoy your benefits!\n\n";
            storeBasket.customerName = customers[index].customerName;
        }
        else
        {
            PrintStoreArt();
            std::cout << "Error, invalid input. No member found.\n\n";
        }
    }
    else if (memberCheck.compare("no") == 0)
    {
        PrintStoreArt();
        std::cout << "Unfortunately you will not get any discount since you are not a member.\n\n";
    }
    else
    {
        PrintStoreArt();
        std::cout << "Error, invalid input. No discount applied\n\n";
    }

    while (1)
    {
        std::cout << "Type in (enter) to access the store\n\n";
        PrintDoorArt();
        std::cin >> storeEnterInput;
        if (storeEnterInput.compare("enter") == 0)
        {
            break;
        }
    }

    while (1)
    {
        PrintStoreArt();

        std::cout << "Make sure to type (done) when finished your purchase.\n";
        std::cout << "-----------------------------------------------------------\n\n";

        for (Product list : products)
        {
            PrintProductList(list);
        }

        std::cout << "\n\nShopping Cart Items: " << amountOfProduct;

        std::cout << "\n\nSubtotal: " << subTotal;

        std::cout << "\n-----------------------------------------------------------\n\n";

        std::cout << "What would you like to buy (product name)? ";
        std::cin >> productName;

        if (productName.compare("done") == 0)
        {
            break;
        }

        for (Product list : products)
        {
            if (productName.compare(list.productName) == 0)
            {
                int quantity;
                double temp = 0;
                std::cout << "Good choice! " << list.productName << " is a great product.\nHow many would you like? ";
                std::cin >> quantity;


                amountOfProduct += quantity;
                subTotal += quantity * list.productPrice;
                temp += quantity * list.productPrice;

                storeBasket.productNames.push_back(list.productName);
                storeBasket.productPrice.push_back(temp);
                storeBasket.productAmount.push_back(quantity);

                break;
            }
        }
    }

    while (1)
    {
        PrintStoreArt();
        std::cout << "Those were good choices " << storeBasket.customerName << "! Lets proceed with your checkout.\n\n";

        std::cout << "Receipt:\n";
        std::cout << "------------------------------------------------------------------\n\n";
        std::cout << "Amount     " << "Product Name     " << "     Price\n";
        std::cout << "------------------------------------------------------------------\n";
        for (int i = 0; i < storeBasket.productNames.size(); ++i)
        {
            std::cout << "   " << storeBasket.productAmount[i] << "        " << storeBasket.productNames[i] << "                 $" << storeBasket.productPrice[i] << "\n";
        }

        std::cout << "\n------------------------------------------------------------------\n\n";

        std::cout << "Total Items in Cart: " << amountOfProduct << "\n";
        std::cout << "Total Amount: $" << subTotal << "\n\n";
        std::cout << "--------------------------------------------------------------------\n";
        if (isMember)
        {
            std::cout << "\n\nSince you are a member of Fresh Market, you get a 10% discount on your subtotal.\n\n";
            discoutedPrice = subTotal / 10;
            totalAfterDiscount = subTotal - discoutedPrice;

            std::cout << "Discount Applied: -$" << discoutedPrice;
            std::cout << "\nTotal to be paid: $" << totalAfterDiscount;

            std::cout << "\n\nEnter the amount you are paying with (cash only): ";
            std::cin >> customerMoney;

            if (customerMoney >= totalAfterDiscount)
            {
                customerChange = customerMoney - totalAfterDiscount;

                std::cout << "Here is your change: $" << customerChange << "\n\n";
                std::cout << "Thank you very much " << storeBasket.customerName << " for choosing Fresh Market. Have a great rest of your day!\n\n";
                break;
            }
            else
            {
                continue;
            }
        }
        else
        {
            std::cout << "\nUnfortunately you are not a member of Fresh Market. No discounts were applied.";

            std::cout << "\n\nEnter the amount you are paying with (cash only): ";
            std::cin >> customerMoney;

            if (customerMoney >= subTotal)
            {
                customerChange = customerMoney - subTotal;

                std::cout << "Here is your change: " << customerChange << "\n\n";
                std::cout << "Thank you very much " << storeBasket.customerName << " for choosing Fresh Market. Have a great rest of your day!\n\n";
                break;
            }
            else
            {
                continue;
            }
        }
    }

    return 0;
}