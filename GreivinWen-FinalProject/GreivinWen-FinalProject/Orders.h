#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Product.h"

namespace FinalProject
{
	class Orders
	{
	public:
		void AddNewOrder(std::map<int, Product>& inventory, std::queue<Orders>& orders);
		void ProcessOrders(std::queue<Orders>& orders);
		void PrintOrderQueue(std::queue<Orders> orders) const;
	private:
		int M_orderID;
		std::string M_customerName;
		std::vector<Product> M_products;
	};
}