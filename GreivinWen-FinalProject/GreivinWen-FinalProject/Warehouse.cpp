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

void Warehouse::RunLogic()
{
	ASCIIArt();

	std::string admin = "123456";
	std::string manager = "987654";

	M_warehouseUsers.insert(std::pair<std::string, std::string>("123456", "Bobby"));	// admin
	M_warehouseUsers.insert(std::pair < std::string, std::string>("987654", "JP"));	// manager

	std::cout << "Welcome, please enter a staff ID\n\n";
	std::string password;
	std::cin >> password;

	if (M_warehouseUsers.find(password) != M_warehouseUsers.end())
	{
		if (password == admin)
		{
			ASCIIArt();
			std::cout << "Welcome back, Admin, let's proceed:\n\n";
			std::cout << "1. Add new products or existing products\n";
			std::cout << "2. View total stock value\n";
		}
		else if (password == manager)
		{

		}
	}
	else
	{
		std::cout << "Staff ID not found in the system.\n\n";
	}

	
	system("pause");
}
