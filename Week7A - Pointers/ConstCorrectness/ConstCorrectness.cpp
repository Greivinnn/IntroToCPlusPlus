#include <iostream>
#include "ConstCorrectness.h"

int main()
{
	/*
	const int something = 10; // locks it at 10, cannot change with a "something = 5"
	// something = 5 

	// 1. locked values, cannot use SetValue()
	// Pointer can change where is pointing at, 
	// however you cannot update the value inside what is being pointed
	ConstantCorrectness obj(42);
	ConstantCorrectness obj2(43);
	const ConstantCorrectness* p1 = &obj;

	p1->GetValue(); // This is allow as long as we have a const in our function in the header file
	p1 = &obj2;	// allowed
	// p1->SetValue(); not allowed

	// 2. locked pointer, cannot set p2 = &objx, however, can use SetValue()
	// A constant pointer to a non-constant ConstantCorrectness
	ConstantCorrectness* const p2 = &obj2;
	p2->SetValue(10);// allowed
	// p2 = &obj2; // not allowed

	// 3. locked pointer and locked obj, cannot set p2 = objx or use SetValue()
	const ConstantCorrectness* const p3 = &obj;
	// p3 = &obj2;	// not allowed
	// p3->SetValue(); // not allowed
	p3->GetValue(); // allowed
	*/

	ConstantCorrectness obj(42);
	int a = obj.GetValue();                                       

	return 0;
}