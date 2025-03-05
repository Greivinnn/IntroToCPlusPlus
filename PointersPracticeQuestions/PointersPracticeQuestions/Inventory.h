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
		void SetBiggestNumber(int num)
		{
			_biggestNumber = num;
		}
		int GetBiggestNumber(int num)
		{
			return _biggestNumber;
		}

	private:
		int _itemNumbers;
		int _biggestNumber;
	};
}