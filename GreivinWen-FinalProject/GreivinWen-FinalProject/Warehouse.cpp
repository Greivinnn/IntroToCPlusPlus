#include "Warehouse.h"
#include "Product.h"
#include <iostream>
#include <string>
#include <vector>
#include "Orders.h"

using namespace FinalProject;

Warehouse::Warehouse()
{
}

void Warehouse::ASCIIArt()
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

std::map<int, Product> Warehouse::GetProductsMap()
{
	return M_productsMap;
}

std::queue<Orders> Warehouse::GetOrderQueue()
{
	return M_ordersQueue;
}

void Warehouse::RunLogic()
{
	while (1)
	{
		ASCIIArt();
		int choice;

		M_warehouseUsers.insert(std::pair<std::string, std::string>("admin", "123456"));	// admin
		M_warehouseUsers.insert(std::pair < std::string, std::string>("manager", "987654"));	// manager

		Product product1("Apple", 50, 1.5, "Fruit");
		Product product2("Pear", 60, 1.5, "Fruit");
		Product product3("Banana", 40, 1.5, "Fruit");
		Product product;
		Orders order;

		M_productsMap.insert(std::pair<int, Product>(1, product1));
		M_productsMap.insert(std::pair<int, Product>(2, product2));
		M_productsMap.insert(std::pair<int, Product>(3, product3));

		std::string username, password;
		std::cout << "Welcome, please enter your username: ";
		std::cin >> username;
		std::cout << "Please enter your password: ";
		std::cin >> password;

		std::map<std::string, std::string>::iterator it = M_warehouseUsers.find(username);
		if (it != M_warehouseUsers.end() && it->second == password)
		{
			while (1)
			{
				if (username == "admin")
				{
					ASCIIArt();
					std::cout << "Welcome back, Admin, let's proceed:\n\n";
					std::cout << "1. Add new products or existing products\n";
					std::cout << "2. View total stock value\n";
					std::cout << "3. Search product\n";
					std::cout << "4. View top stocked products\n";
					std::cout << "5. View all products in warehouse\n";
					std::cout << "6. Exit\n\n";// add display all products

					std::cout << "Choice: ";
					std::cin >> choice;

					if (choice == 1)
					{
						product.AddProduct(M_productsMap);
					}
					else if (choice == 2)
					{
						ASCIIArt();
						std::cout << "The warehouse current stock value: $" << product.CalculateStockValue(M_productsMap) << "\n\n";
						system("pause");
					}
					else if (choice == 3)
					{
						product.FindProduct(M_productsMap);
					}
					else if (choice == 4)
					{
						product.DisplayTopProducts(M_productsMap, 3);
					}
					else if (choice == 5)
					{
						ASCIIArt();
						product.DisplayProduct(M_productsMap);
						system("pause");
					}
					else
					{
						break;
					}
				}
				else if (username == "manager")
				{
					ASCIIArt();
					std::cout << "Welcome back, Manager, let's proceed:\n\n";
					std::cout << "1. Add an order\n";
					std::cout << "2. View current order\n";
					std::cout << "3. View total stock value\n";
					std::cout << "4. View top stocked products\n";
					std::cout << "5. Search product\n";
					std::cout << "6. Display all orders\n";
					std::cout << "7. Exit\n\n";

					std::cout << "Choice: ";
					std::cin >> choice;

					if (choice == 1)
					{
						order.AddNewOrder(M_productsMap, M_ordersQueue);
						system("pause");
					}
					else if (choice == 2)
					{
						order.PrintCurrentOrder(M_ordersQueue);
						system("pause");
					}
					else if (choice == 3)
					{
						ASCIIArt();
						std::cout << "The warehouse total stock value is: $" << product.CalculateStockValue(M_productsMap) << "\n\n";
						system("pause");
					}
					else if (choice == 4)
					{
						product.DisplayTopProducts(M_productsMap, 3);
					}
					else if (choice == 5)
					{
						product.FindProduct(M_productsMap);
					}
					else if (choice == 6)
					{
						order.PrintOrderQueue(M_ordersQueue);
						system("pause");
					}
					else
					{
						break;
					}
				}
			}
		}
		else
		{
			std::cout << "Staff ID not found in the system.\n\n";
		}
		system("pause");
	}
}
