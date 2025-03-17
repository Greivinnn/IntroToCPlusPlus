#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "Product.h"
#include "Orders.h"

namespace FinalProject
{
	class Warehouse
	{
	public:
		Warehouse();
		void RunLogic();
		void ASCIIArt();
		std::map<int, Product> GetProductsMap();
	private:
		std::map<int, Product> M_productsMap;
		std::queue<Orders> M_ordersQueue;
	};
}