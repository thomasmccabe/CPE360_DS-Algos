#include<iostream>
using namespace std;

//classes are templates for objects to follow
//new kind of variable
//it can have attributes and functions
//CONEPTUAL
class threeStoryCondo {
public:
	//attributes
	int x;
	int y;
	int z;
};

int main()
{
	//===========================================================================
	//								A P P   S P A C E
	//===========================================================================
	//name-of-class name-of-object
	threeStoryCondo hobokenCondo;
	hobokenCondo.x = 10;
	hobokenCondo.y = 20;
	hobokenCondo.z = 30;
	//Name.Attribute = value

	int x;

	//===========================================================================
	//									H E A P 
	//===========================================================================
	//first step to create something in the heap;
	//STEP1: You are going to need a pointer
	threeStoryCondo *ptr;
	//STEP2: use this pointer to now go and create something in the heap
	//Pointer = new name-of-structure 
	ptr = new threeStoryCondo;
	ptr->x = 10;
	ptr->y = 20;
	ptr->z = 30;
	//pointer->attribute = value
	cout << "x is: " << ptr->x << ", y is: " << ptr->y << ", z is: " << ptr->z << endl;


	return 1;
}