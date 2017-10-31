#include<iostream>
using namespace std;

int main()
{
	int x, y;
	int *pal; //it's exclusive purpose is to store addresses of other variables. Use * when you create the pal
	
	//assign x to a value
	x = 100;
	pal = &x; //pal now has the address of x DE-REFERENCING A POINTER

	//what's inside a variable: how a programmer sees things
	cout << "Value of x: " << x << endl;
	cout << "Address of x: " << &x << endl;

	*pal = 300; //this is pal acting in lieu of x; i.e., as if it were x. If pal wants to act as a variable again use *. REFERENCING A POINTER
	cout << "Value of x after pal's vist: " << x << endl;
	*pal = *pal + 20; //x = x + 20
	cout << "Value now after math: " << x << endl;

	pal = &y; //from here on, pal has the address of y
	*pal = 500;
	cout << "So, what's inside y?:" << y << endl;


	return 1;
}