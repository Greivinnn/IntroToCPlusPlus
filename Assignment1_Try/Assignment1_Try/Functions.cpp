#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include "Product.h"

using namespace Product;

void PrintProductList()
{
    std::cout << Product::prodcutID << " | " << M_productName << " - $" << M_productPrice << "\n";
}

Product::Product(int productID, std::string productName, double productPrice)
    : M_productID(productID), M_productName(productName), M_productPrice(productPrice)
{

}