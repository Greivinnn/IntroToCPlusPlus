#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include "Customer.h"
#include "Product.h"
#include "Art.h"

using namespace ProductInfo;
using namespace CustomerInfo;
using namespace ArtInfo;

Art StoreArt;

void AddNewProduct(Product secretKey)
{
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

    

    
    secretKey.productList.push_back(productName);
    secretKey.productPrices.push_back(productPrice);

    std::cout << "\n\nProduct added successfully!\n";

    PrintProductListInAdmin(secretKey);

}

int main()
{
    std::vector<Customer> customers =
    {
        Customer("David", 22306541, "David@gmail.com", 112233),
        Customer("Bobby", 22567851, "Bobby@gmail.com", 998877),
        Customer("Juan", 54678921, "Juan@gmail.com", 123456),
        Customer("Santi", 88775332, "Santi@gmail.com", 654321),
    };

    std::vector<Product> products =
    {
        Product(1111, "Apple", 1.67),
        Product(1112, "Pear", 2.25),
        Product(1113, "Potatoe", 1.20),
        Product(1114, "Tomato", 3.00),
        Product(1115, "Banana", 1.00),
    };

    Product adminProduct(0, "", 0.0);
    std::string CustomerName;

    StoreArt.PrintStoreArt();

    for (Product print : products)
    {
        print.PrintProductList();
    }

    for (Customer print : customers)
    {
        print.PrintCustomerList();
    }

    std::cout << "Welcome to Fresh Market!\nWhat is your name?\n";
    std::cin >> CustomerName;

    if (CustomerName.compare("Supersecret") == 0)  // secret word to access the admin page
    {
        int adminOption;

        while (1)
        {
            StoreArt.PrintAdminArt();

            std::cout << "Welcome back Admin. What are we going to do today?\n";
            std::cout << "1. Add new product\n2. Remove a product\n3. Edit a product\n4. Add new member\n5. Delete a member\n6. Edit a members information\n7. View products list\n8. View customers list\n9. Exit admin page\n\n";

            std::cin >> adminOption;

            if (adminOption == 1)
            {
                StoreArt.PrintAdminArt();
                for (Product print : products)
                {
                    print.PrintProductList();
                }
                Add
            }
    
        }
    }
}
/*
            else if (adminOption == 2)
            {
                StoreArt.PrintAdminArt();
                for (Product print : products)
                {
                    print.PrintProductList();
                }
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
            */
