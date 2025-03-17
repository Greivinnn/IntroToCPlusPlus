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

void Warehouse::RunLogic()
{
	ASCIIArt();
	Product products;

	Product product1("Apple", 10, 1.00, "Fruit");
	Product product2("Banana", 20, 0.50, "Fruit");
	Product product3("Orange", 15, 0.75, "Fruit");
	Product product4("Carrot", 5, 0.25, "Vegetable");
	Product product5("Broccoli", 7, 0.75, "Vegetable");
	Product product6("Cucumber", 8, 0.50, "Vegetable");

	M_productsMap.insert(std::pair<int, Product>(1, product1));
	M_productsMap.insert(std::pair<int, Product>(2, product2));

	std::cout << "Welcome to the Warehouse Inventory System!" << "\n\n";

	Orders order;

	order.AddNewOrder(M_productsMap, M_ordersQueue);

}
