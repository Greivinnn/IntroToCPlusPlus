#pragma once

class Base
{
public:
	Base()
	{
		baseVariable = new int;
	}

	virtual ~Base();

private:
	int* baseVariable;
};