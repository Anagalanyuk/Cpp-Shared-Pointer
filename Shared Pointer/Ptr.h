#pragma once

#include<iostream>

//template<typename T>
class Ptr
{
public:
	Ptr();
	Ptr(const int item);
	int GetPtr();
	void Print();
	~Ptr();
private:
	int num;
};

//template<typename T>
Ptr::Ptr()
{
}

//template<typename T>
Ptr::Ptr(const int item):
	num(item)
{
	std::cout << "constructor\n";
}

//template<typename T>
int Ptr::GetPtr()
{
	return num;
}

//template<typename T>
void Ptr::Print()
{
	std::cout << num;
}

//template<typename T>
Ptr::~Ptr()
{
	std::cout << "destructor\n";
}
