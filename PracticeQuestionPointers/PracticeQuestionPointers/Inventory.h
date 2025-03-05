#pragma once
#include <iostream>

namespace Practice
{
	class Inventory
	{
	public:
		Inventory()
		{
		}
		void SetItemNumber(int num)
		{
			_itemNumbers = num;
		}
		int GetItemNumber() const
		{
			return _itemNumbers;
		}

	private:
		int _itemNumbers;
		int _biggestNumber;
	};
}
