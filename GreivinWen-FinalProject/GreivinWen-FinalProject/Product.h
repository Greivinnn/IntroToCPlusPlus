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
		void AddProduct(std::map<int, Product>& inventory);
		void DisplayProduct(std::map<int, Product>& inventory) const;
		void FindProduct(std::map<int, Product> inventory);
		void UpgradeProductQuantityMinus(int quantity);
		Product GetProduct();
		void PrintProducts(std::vector<Product> products) const;
		void SaveInventoryToFile(const std::map<int, Product>& inventory);
		static double CalculateStockValue(const std::map<int, Product> inventory);
		void ASCIIArt();
		void DisplayTopProducts(const std::map<int, Product> inventory, int count);
		std::string GetProductName() const;
		int GetProductQuantity() const;
		double GetPrice() const;
		std::string GetCatergory() const;
		void SetOrderedQuantity(int quantity);
		int GetOrderedQuantity() const;
	private:
		std::string M_name;
		int M_quantity;
		double M_price;
		std::string M_category;
		int M_orderedQuantity;
	};
}