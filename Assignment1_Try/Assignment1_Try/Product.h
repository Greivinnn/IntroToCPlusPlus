#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace Product
{
	struct Product
	{
		Product(int productID, std::string productName, double productPrice);
		void PrintProductList();
		
		int productID;
		std::string productName;
		double productPrice;
	};
}