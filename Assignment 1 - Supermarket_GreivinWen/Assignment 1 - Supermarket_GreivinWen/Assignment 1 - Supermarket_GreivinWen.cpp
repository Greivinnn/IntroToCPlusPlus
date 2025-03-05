#include <iostream>
#include <string>
#include <time.h>
#include <vector>

// hey bobby we talked about using the & on codes and I think in the case of adding, deleting and editing structs I have to use the & so it can actually make a change on the vectors. 


// Codes Structs
struct Customer
{
    std::vector<std::string> customerName{ "David", "Bobby", "Santi", "Emma" };
    std::vector<int> phoneNumber{ 123456789, 987654321, 111111111, 222222222 };
    std::vector<std::string> customerEmail{ "David@gmail.com", "Bobby@gmail.com", "Santi@gmail.com", "Emma@gmail.com" };
    std::vector<int> customerID{ 1111, 1234, 9876, 4321 };
};
struct Product
{
    std::vector<int> productsID{ 111,112,113,114,115 };
    std::vector<std::string> productList{ "Apple", "Rice", "Chocolate", "Keyboard", "Jacket" };
    std::vector<double> productPrices{ 1.39, 5.99, 2.99, 80.99, 85.00 };
};
struct Basket
{
    std::vector<std::string> productNames;
    std::vector<double> productPrice;
    std::vector<int> productAmount;
    std::string customerName;
};
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

// Print Customer and Product functions // PrintCustomerListInAdmin has the input of a string for the user to be able to see the messages of their actions in admin
void PrintCustomerList(Customer customers)
{
    std::cout << "Fresh Market Customer Database\n\n";
    for (int i = 0; i < customers.customerID.size(); ++i)
    {
        std::cout << "MemberID: " << customers.customerID[i] << " || Name: " << customers.customerName[i] << " || Email: " << customers.customerEmail[i] << " || Phone Number: " << customers.phoneNumber[i] << "\n\n";
    }
}

void PrintCustomerListInAdmin(Customer customers)
{
    std::string choice;
    PrintAdminArt();
    std::cout << "Fresh Market Customer Database\n\n";
    for (int i = 0; i < customers.customerID.size(); ++i)
    {
        std::cout << "MemberID: " << customers.customerID[i] << " || Name: " << customers.customerName[i] << " || Email: " << customers.customerEmail[i] << " || Phone Number: " << customers.phoneNumber[i] << "\n\n";
    }
    std::cout << "\n\nPress any number key to go back. ";
    std::cin >> choice; // this is so the user can see the message after doing anything in the admin page, since system("cls") clears too fast for us to know if the implementation was made or not
}

void PrintProductList(Product products)
{
    std::cout << "Fresh Markets Product List and Prices:\n\n";
    for (int i = 0; i < products.productList.size(); ++i)
    {
        std::cout << products.productsID[i] << " | " << products.productList[i] << " - $" << products.productPrices[i] << "\n";
    }
}

void PrintProductListInAdmin(Product products)
{
    std::string choice;
    PrintAdminArt();
    std::cout << "Fresh Markets Product List and Prices:\n\n";
    for (int i = 0; i < products.productList.size(); ++i)
    {
        std::cout << products.productsID[i] << " | " << products.productList[i] << " - $" << products.productPrices[i] << "\n";
    }
    std::cout << "\n\nPress any number key to go back. ";
    std::cin >> choice;
}
// --------------------------------------------------------------------------------

// Customer Functions: ADD, DELETE, EDIT
void AddNewCustomer(Customer& secretKey)
{
    PrintAdminArt();
    PrintCustomerList(secretKey);

    int customerID;
    std::string customerName;
    int customerNumber;
    std::string customerEmail;

    std::cout << "\n\nAdding a new member...\n\n";
    std::cout << "Enter members ID: ";
    std::cin >> customerID;

    std::cout << "\nEnter members name: ";
    std::cin >> customerName;

    std::cout << "\nEnter members phone number: ";
    std::cin >> customerNumber;

    std::cout << "\nEnter members email: ";
    std::cin >> customerEmail;

    secretKey.customerID.push_back(customerID);
    secretKey.customerName.push_back(customerName);
    secretKey.phoneNumber.push_back(customerNumber);
    secretKey.customerEmail.push_back(customerEmail);

    std::cout << "\n\nNew member added successfully!\n";

    PrintCustomerListInAdmin(secretKey);
}

void DeleteCustomer(Customer& secretKey, int customerID)
{
    PrintAdminArt();
    int index = -1;

    for (int i = 0; i < secretKey.customerID.size(); ++i)
    {
        if (secretKey.customerID[i] == customerID)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        secretKey.customerID.erase(secretKey.customerID.begin() + index);
        secretKey.customerName.erase(secretKey.customerName.begin() + index);
        secretKey.customerEmail.erase(secretKey.customerEmail.begin() + index);
        secretKey.phoneNumber.erase(secretKey.phoneNumber.begin() + index);

        std::cout << "\nCustomer Deleted Successfully\n\n";
    }
    else
    {
        std::cout << "\nMemberID Not Found.\n\n";
    }

    PrintCustomerListInAdmin(secretKey);
}

void EditCustomerInformation(Customer& secretKey, int customerID)
{
    int index = -1;

    for (int i = 0; i < secretKey.customerID.size(); ++i)
    {
        if (secretKey.customerID[i] == customerID)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        std::cout << "Editing " << secretKey.customerName[index] << "'s information...\n\n";
        std::cout << "Current memberID: " << secretKey.customerID[index] << "\n";
        std::cout << "Enter a new memberID: ";

        int newCustomerID;
        std::cin >> newCustomerID;

        if (newCustomerID != -1)
        {
            secretKey.customerID[index] = newCustomerID;
        }

        std::string newName;
        std::cout << "\nCurrent customer name: " << secretKey.customerName[index] << "\n";
        std::cout << "Enter new customer name: ";
        std::cin >> newName;

        if (!newName.empty())
        {
            secretKey.customerName[index] = newName;
        }

        int newNumber;
        std::cout << "\nCustomer current phone number: " << secretKey.phoneNumber[index] << "\n";
        std::cout << "Enter new phone number: ";
        std::cin >> newNumber;

        if (newNumber != -1)
        {
            secretKey.phoneNumber[index] = newNumber;
        }

        std::string newMail;
        std::cout << "\nCustomer current email address: " << secretKey.customerEmail[index] << "\n";
        std::cout << "Enter customers new email address: ";
        std::cin >> newMail;

        if (!newMail.empty())
        {
            secretKey.customerEmail[index] = newMail;
        }
        std::cout << "\n\nEverything was deleted succesfully\n\n";
    }
    else
    {
        std::cout << "\nMemberID not found in database.\n\n";
    }

    PrintCustomerListInAdmin(secretKey);
}
// --------------------------------------------------------------------------------

//  Product Functions: ADD, DELETE, EDIT
void AddNewProduct(Product& secretKey)
{
    PrintAdminArt();
    PrintProductList(secretKey);
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

    secretKey.productsID.push_back(productID);
    secretKey.productList.push_back(productName);
    secretKey.productPrices.push_back(productPrice);

    std::cout << "\n\nProduct added successfully!\n";

    PrintProductListInAdmin(secretKey);

}

void DeleteStoreProduct(Product& secretKey, int ID)
{
    int index = -1; // since the array start at 0 we need the index to check after -1, so if its -1 the productID does not exist

    for (int i = 0; i < secretKey.productsID.size(); ++i)
    {
        if (secretKey.productsID[i] == ID)
        {
            index = i;      // find the index to be deleted
            break;
        }
    }

    if (index != -1)    // product found and erase function applied
    {
        secretKey.productsID.erase(secretKey.productsID.begin() + index);
        secretKey.productList.erase(secretKey.productList.begin() + index);
        secretKey.productPrices.erase(secretKey.productPrices.begin() + index);

        std::cout << "\nProduct Deleted Successfully!\n\n";
    }
    else
    {
        std::cout << "\nProduct ID not found\n\n";
    }

    PrintProductListInAdmin(secretKey);
}

void EditStoreProducts(Product& secretKey, int ID)
{
    int index = -1;
    for (int i = 0; i < secretKey.productsID.size(); ++i)
    {
        if (secretKey.productsID[i] == ID)
        {
            index = i;      // find the index to be deleted
            break;
        }
    }

    if (index != -1)
    {
        std::cout << "Editing product with ID " << ID << "\n";
        std::cout << "Current Product Name: " << secretKey.productList[index] << "\n";
        std::cout << "Enter new name: ";

        std::string newProductName;
        std::cin >> newProductName;

        if (!newProductName.empty())    // if nothing is inputted then the name stays the same as before
        {
            secretKey.productList[index] = newProductName;
        }

        double newProductPrice;

        std::cout << "\nCurrent Product Price: $" << secretKey.productPrices[index] << "\n";
        std::cout << "Enter new price: ";
        std::cin >> newProductPrice;

        if (newProductPrice != -1)
        {
            secretKey.productPrices[index] = newProductPrice;
        }
        std::cout << "\nProduct updated successfully!\n\n";
    }
    else
    {
        std::cout << "\nProduct not found.\n\n";
    }

    PrintProductListInAdmin(secretKey);
}
// --------------------------------------------------------------------------------

int main()
{
    srand(time(NULL));

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
    std::string secretInput;
    Customer Customer1;
    Product products;
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
                AddNewProduct(products);
            }
            else if (adminOption == 2)
            {
                PrintAdminArt();
                PrintProductList(products);
                
                int productID;

                std::cout << "\n-----------------------------------------------------------\n\n";
                std::cout << "What product would you like to delete? (enter productID) ";
                std::cin >> productID;
                DeleteStoreProduct(products, productID);
            }
            else if (adminOption == 3)
            {
                PrintAdminArt();
                PrintProductList(products);

                int productID;

                std::cout << "\n-----------------------------------------------------------\n\n";
                std::cout << "What product would you like to edit? (enter productID) ";
                std::cin >> productID;
                EditStoreProducts(products, productID);
            }
            else if (adminOption == 4)
            {
                AddNewCustomer(Customer1);
            }
            else if (adminOption == 5)
            {
                PrintAdminArt();
                PrintCustomerList(Customer1);
                int customerID;
                std::cout << "\n\nWhat customer would you like to delete (enter memberID): ";
                std::cin >> customerID;

                DeleteCustomer(Customer1, customerID);
            }
            else if (adminOption == 6)
            {

                PrintAdminArt();
                PrintCustomerList(Customer1);
                int customerID;
                std::cout << "\n\nWhat customers information would you like to edit (enter memberID): ";
                std::cin >> customerID;

                EditCustomerInformation(Customer1, customerID);
            }
            else if (adminOption == 7)
            {
                PrintProductListInAdmin(products);
            }
            else if (adminOption == 8)
            {
                PrintCustomerListInAdmin(Customer1);
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

        for (int i = 0; i < Customer1.customerID.size(); ++i)
        {
            if (Customer1.customerID[i] == customerMemberID)
            {
                isMember = true;
                index = i;
                break;
            }
        }

        if (isMember)
        {
            PrintStoreArt();
            std::cout << "Welcome back! " << Customer1.customerName[index] << "\n";
            std::cout << "Phone Number: " << Customer1.phoneNumber[index] << "\n";
            std::cout << "Email: " << Customer1.customerEmail[index] << "\n\nEnjoy your benefits!\n\n";
            storeBasket.customerName = Customer1.customerName[index];
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
        std::cin >> secretInput;
        if (secretInput.compare("enter") == 0)
        {
            break;
        }
    }

    while (1)
    {
        PrintStoreArt();

        std::cout << "Make sure to type (done) when finished your purchase.\n";
        std::cout << "-----------------------------------------------------------\n\n";

        PrintProductList(products);

        std::cout << "\n\nShopping Cart Items: " << amountOfProduct;

        std::cout << "\n\nSubtotal: " << subTotal;

        std::cout << "\n-----------------------------------------------------------\n\n";

        std::cout << "What would you like to buy (product name)? ";
        std::cin >> productName;

        if (productName.compare("done") == 0)
        {
            break;
        }

        for (int i = 0; i < products.productList.size(); ++i)
        {
            if (productName.compare(products.productList[i]) == 0)
            {
                int quantity;
                double temp = 0;
                std::cout << "Good choice! " << products.productList[i] << " is a great product.\nHow many would you like? ";
                std::cin >> quantity;


                amountOfProduct += quantity;
                subTotal += quantity * products.productPrices[i];
                temp += quantity * products.productPrices[i];

                storeBasket.productNames.push_back(products.productList[i]);
                storeBasket.productPrice.push_back(temp);
                storeBasket.productAmount.push_back(quantity);

                break;
            }
        }
    }

    while (1)
    {
        PrintStoreArt();
        std::cout << "Those were good choices " <<  storeBasket.customerName << "! Lets proceed with your checkout.\n\n";

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
// when discounted price the price values are up to 3 decimals how do i change that?
// Put the structs in header files 
// and make the struct a vector and not its components. Its components should be single storing units not vectors