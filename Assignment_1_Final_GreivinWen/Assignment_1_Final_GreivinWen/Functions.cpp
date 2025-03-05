#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include "Product.h"
#include "Customer.h"
#include "Art.h"

using namespace ProductInfo;
using namespace CustomerInfo;
using namespace ArtInfo;

Customer::Customer(std::string customerName, int phoneNumber, std::string customerEmail, int customerID)
    : M_customerName(customerName), M_phoneNumber(phoneNumber), M_customerEmail(customerEmail), M_customerID(customerID)
{

}

Product::Product(int productID, std::string productName, double productPrice)
    : M_productID(productID), M_productName(productName), M_productPrice(productPrice)
{

}

void Art::PrintDoorArt()
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

void Art::PrintAdminArt()
{
    system("cls");
    std::cout << "   __    ____  __  __  ____  _  _    ____   __    ___  ____ \n";
    std::cout << "  /__|  (  _ |(  |/  )(_  _)( |( )  (  _ | /__|  / __)( ___)\n";
    std::cout << " /(__)|  )(_) ))    (  _)(_  )  (    )___//(__)|( (_-. )__) \n";
    std::cout << "(__)(__)(____/(_/|/|_)(____)(_)|_)  (__) (__)(__)|___/(____)\n\n";
}

void Art::PrintStoreArt()
{
    system("cls");
    std::cout << " ____  ____  ____  ___  _   _    __  __    __    ____   _  _  ____  ____ \n";
    std::cout << "( ___)(  _ |( ___)/ __)( )_( )  (  |/  )  |__|  (  _ | ( )/ ) |___)(_  _)\n";
    std::cout << " )__)  )   / )__) |__ | ) _ (    )    (  |(__)|  )   /  )  (  |)__)  )(  \n";
    std::cout << "(__)  (_)|_)(____)(___ ( (_) )  (_/|/|_)(__)|(_)(_)||_)(_)|_) |||_) (__) \n\n";
}

void Customer::PrintCustomerListInAdmin()
{
    std::string choice;

    std::cout << "MemberID: " << M_customerID << " || Name: " << M_customerName << " || Email: " << M_customerEmail << " || Phone Number: " << M_phoneNumber << "\n";

    std::cout << "\n\nPress any key to go back. ";
    std::cin >> choice;
}

void Customer::PrintCustomerList()
{
    std::cout << "MemberID: " << M_customerID << " || Name: " << M_customerName << " || Email: " << M_customerEmail << " || Phone Number: " << M_phoneNumber << "\n";
}

void Product::PrintProductListInAdmin()
{
    std::string choice;

    std::cout << M_productID << " | " << M_productName << " - $" << M_productPrice << "\n";

    std::cout << "\n\nPress any key to go back. ";
    std::cin >> choice;
}

void Product::PrintProductList()
{
    std::cout << M_productID << " | " << M_productName << " - $" << M_productPrice << "\n";
}

void Product::AddNewProduct()
{
    std::cout << "\n-----------------------------------------------------------\n\n";

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

    Product newProduct(productID, productName, productPrice);
    productList.push_back(newProduct);

    std::cout << "\n\nProduct added successfully!\n";
}

/*void Product::DeleteStoreProduct()
{
    int productID;

    std::cout << "\n-----------------------------------------------------------\n\n";
    std::cout << "What product would you like to delete? (enter productID) ";
    std::cin >> productID;

    int index = -1; // since the array start at 0 we need the index to check after -1, so if its -1 the productID does not exist

    for (int i = productList.begin(); i != productList.end(); ++i)
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
}*/
