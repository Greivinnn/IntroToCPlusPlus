#pragma once

class ConstantCorrectness
{
public:
	ConstantCorrectness(int v)
	{
		_value = v;
	}
	int GetValue() const // this const gurantees that whatever we do inside the function it will not change the type of the class
	{
		return _value;
	}
	void SetValue(int v) 
	{
		_value = v;
	}
private:
	int _value;
};