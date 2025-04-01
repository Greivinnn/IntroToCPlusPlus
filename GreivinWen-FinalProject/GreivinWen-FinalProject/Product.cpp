#include "Product.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace FinalProject;

Product::Product()
{
}

Product::Product(std::string name, int quantity, double price, std::string category)
	:M_name(name), M_quantity(quantity), M_price(price), M_category(category)
{
}

void Product::ASCIIArt()
{
	system("cls");
	std::cout << R"(
 ____    _    _     _     _____ ____   __        ___    ____  _____ _   _  ___  _   _ ____  _____ 
| __ )  / \  | |   | |   | ____|  _ \  \ \      / / \  |  _ \| ____| | | |/ _ \| | | / ___|| ____|
|  _ \ / _ \ | |   | |   |  _| | |_) |  \ \ /\ / / _ \ | |_) |  _| | |_| | | | | | | \___ \|  _|  
| |_) / ___ \| |___| |___| |___|  _ <    \ V  V / ___ \|  _ <| |___|  _  | |_| | |_| |___) | |___ 
|____/_/   \_\_____|_____|_____|_| \_\    \_/\_/_/   \_\_| \_\_____|_| |_|\___/ \___/|____/|_____|
				)" << "\n\n";
}

Product Product::GetProduct()
{
	return Product(M_name, M_quantity, M_price, M_category);
}

void Product::SetOrderedQuantity(int quantity)
{
	M_orderedQuantity = quantity;
}

int Product::GetOrderedQuantity() const
{
	return M_orderedQuantity;
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

void Product::SaveInventoryToFile(const std::map<int, Product>& inventory)	// this is not correct here however it makes my life way easier 
{
	std::ofstream warehouseData("warehouse_data.txt");
	if (warehouseData.is_open())
	{
		for (const auto& pair : inventory)
		{
			warehouseData << "Product ID: " << pair.first << "\n";
			warehouseData << "Product Name: " << pair.second.M_name << "\n";
			warehouseData << "Product Quantity: " << pair.second.M_quantity << "\n";
			warehouseData << "Product Price: " << pair.second.M_price << "\n";
			warehouseData << "Product Category: " << pair.second.M_category << "\n\n";
		}
		warehouseData.close();
	}
	else
	{
		std::cout << "Failed to open file boss.\n\n";
	}
}

void Product::AddProduct(std::map<int, Product>& inventory)
{
	ASCIIArt();
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

			SaveInventoryToFile(inventory);
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

			SaveInventoryToFile(inventory);
		}
	}
	catch (std::invalid_argument e)
	{
		std::cerr << e.what() << "\n";
	}
	system("pause");
}

void Product::FindProduct(std::map<int, Product> inventory)
{
	ASCIIArt();
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
	system("pause");
}

int Product::GetProductQuantity() const
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

double Product::CalculateStockValue(const std::map<int, Product> inventory)
{
	double totalValue = 0.0;

	for (const std::pair<int, Product> pair : inventory)
	{
		totalValue += pair.second.M_price * pair.second.M_quantity;
	}

	return totalValue;
}

void Product::DisplayTopProducts(const std::map<int, Product> inventory, int count)
{
	ASCIIArt();
	if (inventory.empty())
	{
		std::cout << "No products in inventory.\n";
		return;
	}

	int* topProductIDs = new int[count];
	int* topQuantities = new int[count];

	for (int i = 0; i < count; i++)
	{
		topProductIDs[i] = -1;
		topQuantities[i] = -1;
	}

	for (const auto& pair : inventory)
	{
		int productID = pair.first;
		int quantity = pair.second.M_quantity;

		for (int i = 0; i < count; i++)
		{
			if (quantity > topQuantities[i])
			{
				for (int j = count - 1; j > i; j--)
				{
					topProductIDs[j] = topProductIDs[j - 1];
					topQuantities[j] = topQuantities[j - 1];
				}

				topProductIDs[i] = productID;
				topQuantities[i] = quantity;
				break;
			}
		}
	}

	int displayCount = count;
	for (int i = count - 1; i >= 0; i--)
	{
		if (topProductIDs[i] == -1)
		{
			displayCount--;
		}
	}

	std::cout << "Top " << displayCount << " Most Stocked Products:\n\n";

	for (int i = 0; i < displayCount; i++)
	{
		int productID = topProductIDs[i];
		auto it = inventory.find(productID);

		if (it != inventory.end())
		{
			std::cout << (i + 1) << ". Product ID: " << productID << "\n";
			std::cout << "   Product Name: " << it->second.M_name << "\n";
			std::cout << "   Quantity: " << it->second.M_quantity << "\n";
			std::cout << "   Value: $" << (it->second.M_price * it->second.M_quantity) << "\n\n";
		}
	}

	delete[] topProductIDs;
	delete[] topQuantities;
	system("pause");
}

std::string Product::GetProductName() const
{
	return M_name;
}

double Product::GetPrice() const
{
	return M_price;
}

std::string Product::GetCatergory() const
{
	return M_category;
}
