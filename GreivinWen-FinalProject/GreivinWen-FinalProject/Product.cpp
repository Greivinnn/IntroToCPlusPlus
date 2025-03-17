#include "Product.h"
#include <iostream>
#include <string>

using namespace FinalProject;

Product::Product()
{
}

Product::Product(std::string name, int quantity, double price, std::string category)
	:M_name(name), M_quantity(quantity), M_price(price), M_category(category)
{
}

Product Product::GetProduct()
{
	return Product(M_name, M_quantity, M_price, M_category);
}

void Product::DisplayProduct(std::map<int, Product>& inventory) const
{
	for (const std::pair<int, Product> pair : inventory)
	{
		std::cout << "Product ID: " << pair.first << "\n";
		std::cout << "Product Name: " << pair.second.M_name << "\n";
		std::cout << "Product Quantity: " << pair.second.M_quantity << "\n";
		std::cout << "Product Price: " << pair.second.M_price << "\n";
		std::cout << "Product Category: " << pair.second.M_category << "\n\n";
	}
}

void Product::AddProduct(std::map<int, Product> inventory)
{
	try
	{
		std::string productName;
		int productQuantity;
		double productPrice;
		std::string productCategory;
		int productID;

		std::cout << "Add New Product" << "\n\n";

		std::cout << "Enter Product ID: ";
		std::cin >> productID;

		if (inventory.find(productID) != inventory.end())
		{
			std::cout << "Product ID already exists. Enter additional quantity to add: ";
			std::cin >> productQuantity;
			if (productQuantity < 0)
			{
				throw std::invalid_argument("Quantity cannot be negative!");
			}
			inventory[productID].M_quantity += productQuantity;
			std::cout << "Product quantity updated successfully!" << "\n\n";
		}
		else
		{
			std::cout << "Enter Product Name: ";
			std::cin >> productName;
			std::cout << "Enter Product Quantity: ";
			std::cin >> productQuantity;
			if (productQuantity < 0)
			{
				throw std::invalid_argument("Quantity cannot be negative!");
			}
			std::cout << "Enter Product Price: ";
			std::cin >> productPrice;
			if (productPrice < 0)
			{
				throw std::invalid_argument("Price cannot be negative!");
			}
			std::cout << "Enter Product Category: ";
			std::cin >> productCategory;

			Product product(productName, productQuantity, productPrice, productCategory);
			inventory.insert(std::pair<int, Product>(inventory.size() + 1, product));
			M_quantity += productQuantity;

			std::cout << "Product Added Successfully!" << "\n\n";
		}
	}
	catch (std::invalid_argument e)
	{
		std::cerr << e.what() << "\n";
	}
}

void Product::FindProduct(std::map<int, Product> inventory)
{
	int productID;
	std::cout << "Enter Product ID to find: ";
	std::cin >> productID;

	if (inventory.find(productID) != inventory.end())
	{
		std::cout << "Product Found!" << "\n";
		std::cout << "Product Name: " << inventory[productID].M_name << "\n";
		std::cout << "Product Quantity: " << inventory[productID].M_quantity << "\n";
		std::cout << "Product Price: " << inventory[productID].M_price << "\n";
		std::cout << "Product Category: " << inventory[productID].M_category << "\n\n";
	}
	else
	{
		std::cout << "Product Not Found!" << "\n\n";
	}
}

int Product::GetProductQuantity()
{
	return M_quantity;
}

void Product::UpgradeProductQuantityMinus(int quantity)
{
	M_quantity -= quantity;
}

void Product::PrintProducts(std::vector<Product> products) const
{
	for (std::vector<Product>::const_iterator it = products.begin(); it != products.end(); ++it)
	{
		std::cout << "Product Name: " << it->M_name<< "\n";
		std::cout << "Quantity: " << it->M_quantity << "\n";
		std::cout << "Price: " << it->M_price << "\n";
		std::cout << "Category: " << it->M_category << "\n";
	}
}

