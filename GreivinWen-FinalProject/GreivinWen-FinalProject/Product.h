#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>

namespace FinalProject
{
	class Product 
	{
	public:
		Product();
		Product(std::string name, int quantity, double price, std::string category);
		void AddProduct(std::map<int, Product> inventory);
		void DisplayProduct(std::map<int, Product>& inventory) const;
		void FindProduct(std::map<int, Product> inventory);
		int GetProductQuantity();
		void UpgradeProductQuantityMinus(int quantity);
		Product GetProduct();
		std::string GetProductName();
		void PrintProducts(std::vector<Product> products) const;
	private:
		std::string M_name;
		int M_quantity;
		double M_price;
		std::string M_category;
	};
}