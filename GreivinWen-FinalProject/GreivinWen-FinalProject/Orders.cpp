#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include "Orders.h"
#include "Product.h"
#include "Warehouse.h"

using namespace FinalProject;

void Orders::PrintOrderQueue(std::queue<Orders> orders) const
{
	while (!orders.empty())
	{
		Product product;
		Orders order = orders.front();
		orders.pop();

		std::cout << "Order ID: " << order.M_orderID << "\n";
		std::cout << "Customer Name: " << order.M_customerName << "\n";
		std::cout << "Products in " << order.M_customerName << "'s order:\n";

		for (const Product& product : order.M_products)
		{
			std::cout << "Product Name: " << product.GetProductName() << "\n";
			std::cout << "Quantity: " << product.GetProductQuantity() << "\n";
			std::cout << "Price: " << product.GetPrice() << "\n";
			std::cout << "Category: " << product.GetCatergory() << "\n";
		}
	}
}

void Orders::AddNewOrder(std::map<int, Product>& inventory, std::queue<Orders>& orders)
{
	try
	{
		Orders newOrder;

		std::cout << "Enter the order ID: ";
		std::cin >> newOrder.M_orderID;
		std::cout << "Enter the customer name: ";
		std::cin >> newOrder.M_customerName;

		std::string addMore;
		do
		{
			Product product;
			int productID;
			product.DisplayProduct(inventory);
			
			std::cout << "What product would you like to add to the order? Enter the product ID: ";
			std::cin >> productID;

			if (inventory.find(productID) == inventory.end())
			{
				throw std::invalid_argument("Product ID does not exist!");
			}
			else
			{
				product = inventory[productID];
			}

			int productQuantity;
			std::cout << "Enter the quantity of the product: ";
			std::cin >> productQuantity;
			inventory[productID].UpgradeProductQuantityMinus(productQuantity);
			product.SetOrderedQuantity(productQuantity);
			newOrder.M_products.push_back(product);
			std::cout << "Do you want to add more products? (yes/no): ";
			std::cin >> addMore;
		} while (addMore == "yes");
		orders.push(newOrder);
	}
	catch (std::invalid_argument e)
	{
		std::cerr << e.what() << "\n";
	}
	
}

void Orders::ProcessOrders(std::queue<Orders>& orders)
{
	if (orders.empty())
	{
		std::cout << "No orders to process boss.\n\n";
		return;
	}

	Product product;
	Orders order = orders.front();
	orders.pop();

	std::ofstream orderHistory("order_history.txt");

	if (orderHistory.is_open())	// check if it opened correctly
	{
		orderHistory << "Order ID: " << order.M_orderID << "\n";
		orderHistory << "Customer Name: " << order.M_customerName << "\n";
		orderHistory << "Products in " << order.M_customerName << "'s order:\n";

		for (const Product& product : order.M_products)
		{
			orderHistory << "Product Name: " << product.GetProductName() << "\n";
			orderHistory << "Quantity: " << product.GetOrderedQuantity() << "\n";
			orderHistory << "Price: " << product.GetPrice() << "\n";
			orderHistory << "Category: " << product.GetCatergory() << "\n";
		}
		std::cout << "Ordered completed sucessfully!\n\n";
	}
	else
	{
		std::cout << "Failed to open the file.\n\n";
	}
	orderHistory.close();
}

void Orders::RejectOrders(std::queue<Orders>& orders)
{
	Orders order = orders.front();
	orders.pop();

	std::cout << "Order has been rejected sucessfully.\n\n";
}

void Orders::PrintCurrentOrder(std::queue<Orders>& orders)
{
	Product product;
	Warehouse warehouse;
	product.ASCIIArt();
	if (orders.empty())
	{
		std::cout << "No current orders in the queue.\n";
		return;
	}

	int choice;
	Orders order = orders.front();
	std::cout << "Order ID: " << order.M_orderID << "\n";
	std::cout << "Customer Name: " << order.M_customerName << "\n";
	std::cout << "Products in " << order.M_customerName << "'s order:\n";

	for (const Product& product : order.M_products)
	{
		std::cout << "Product Name: " << product.GetProductName() << "\n";
		std::cout << "Quantity: " << product.GetProductQuantity() << "\n";
		std::cout << "Price: " << product.GetPrice() << "\n";
		std::cout << "Category: " << product.GetCatergory() << "\n";
	}

	std::cout << "\n\n";

	std::cout << "What would you like to do to this order?\n";
	std::cout << "1. Process order  ||  2. Reject order\n\n";
	std::cout << "Choice: ";
	std::cin >> choice;

	if (choice == 1)
	{
		ProcessOrders(orders);
	}
	else if (choice == 2)
	{
		RejectOrders(orders);
	}
	else
	{
		std::cout << "Invalid input, going back...\n\n";
	}

	system("pause");
}
