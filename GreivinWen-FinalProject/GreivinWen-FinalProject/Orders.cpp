#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include "Orders.h"
#include "Product.h"

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

		product.PrintProducts(M_products);
	}
}

//void Orders::AddNewOrder(std::map<int, Product>& inventory, std::queue<Orders>& orders)
//{
//	try
//	{
//		Orders newOrder;
//
//		std::cout << "Enter the order ID: ";
//		std::cin >> newOrder.M_orderID;
//		std::cout << "Enter the customer name: ";
//		std::cin >> newOrder.M_customerName;
//
//		std::string addMore;
//		do
//		{
//			Product product;
//			int productID;
//			product.DisplayProduct(inventory);
//			
//			std::cout << "What product would you like to add to the order? Enter the product ID: ";
//			std::cin >> productID;
//
//			if (inventory.find(productID) == inventory.end())
//			{
//				throw std::invalid_argument("Product ID does not exist!");
//			}
//			else
//			{
//				product = inventory[productID];
//			}
//
//			int productQuantity;
//			std::cout << "Enter the quantity of the product: ";
//			std::cin >> productQuantity;
//
//			inventory[productID].UpgradeProductQuantityMinus(productQuantity);
//			newOrder.M_products.push_back(product);
//			std::cout << "Do you want to add more products? (yes/no): ";
//			std::cin >> addMore;
//		} while (addMore == "yes");
//		orders.push(newOrder);
//	}
//	catch (std::invalid_argument e)
//	{
//		std::cerr << e.what() << "\n";
//	}
//	
//}

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

		product.PrintProducts(order.M_products);
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