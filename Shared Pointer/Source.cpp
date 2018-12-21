#include<iostream>

#include"SharedPointer.h"

#include"SharedPointerA.h"

#include"Ptr.h"

using namespace std;

int main()
{



	SharedPointer<int[]> foo = new int[2];
	foo[0] = 10;
	foo[1] = 20;

	SharedPointer<int[]> bar = new int[2];
	bar = foo;
	cout << bar[1];
}