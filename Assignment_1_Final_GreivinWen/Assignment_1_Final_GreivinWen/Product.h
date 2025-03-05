#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace ProductInfo
{
    class Product
    {
    public:
        Product(int productID, std::string productName, double productPrice);
        void PrintProductListInAdmin();
        void PrintProductList();
        void AddNewProduct();
        //void DeleteStoreProduct();
        std::vector<Product> productList;
    private:
        int M_productID;
        std::string M_productName;
        double M_productPrice;
    };
}

