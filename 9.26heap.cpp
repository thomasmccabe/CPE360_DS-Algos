#include<iostream>
using namespace std;

class CartItem
{
public:
	int price;
	int rating;
	CartItem *nextItem;

	//constructor
	//default look and feel to every object
	CartItem(){
		price = 0;
		rating = 0;
		nextItem = NULL;
	}
};


int main()
{
	CartItem *customerCart = NULL;

	//customer has an empty cart to begin with
	//customers happens to add an item to cart
	customerCart = new CartItem; //a new cartItem gets created, and keys are provided. And we store these keys in customerCart(pointer)
	customerCart->price = 100;
	customerCart->rating = 4;

	//lets add another item to the cart, such that the first iem points to the second item
	//<pointer> = new <structure>
	customerCart->nextItem = new CartItem;
	customerCart->nextItem->price = 10;
	customerCart->nextItem->rating = 5;

	//lets add a third item, such that second item points to the third
	customerCart->nextItem->nextItem = new CartItem;
	customerCart->nextItem->nextItem->price = 23;
	customerCart->nextItem->nextItem->rating = 3;

	//lets add a forth item at the end of the third
	customerCart->nextItem->nextItem->nextItem = new CartItem;
	customerCart->nextItem->nextItem->nextItem->price = 99;
	customerCart->nextItem->nextItem->nextItem->rating = 5;

	cout << "First item price: " << customerCart->price << endl;
	cout << "Third item rating: " << customerCart->nextItem->nextItem->rating << endl;
	cout << "Second item price: " << customerCart->nextItem->price << endl;
	cout << "Foruth item price: " << customerCart->nextItem->nextItem->nextItem->price << endl;
}

