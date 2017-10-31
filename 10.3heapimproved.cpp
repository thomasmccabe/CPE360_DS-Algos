#include<iostream>
using namespace std;

//create an idea of an "item"
class Item{
publlic:
	int price;
	int rating;
	Item *next;

	Item() {
		price = 0;
		rating = 0;
		next = NULL;
	}
};

//now, create an idea of a shopping cart
//1. shopping cart is a collection of "Items"
//2. shopping cart lets you do thing: add items, delete items, display items
class ShoppinpCart{
public:
	Item *head; //the only attribute is a pointer to your first item in cart

	ShoppingCart() {
		head = NULL; //a new shopping cart has nothing in it. Default look and feel
	}
	//step1: create a function that adds new items to cart
	void addNewItem(int price, int rating){
		Item *temp; //like your left hand, grabs a new "item" so it can knit it in
		temp = new Item; //a new chunk in the heap
		//prep this newly created item, and update it's price and rating
		temp->price = price;
		temp->rating = rating;

		//First, check to see if the structure is empty
		if(head == NULL){
			//yes, the cart is empty
			head = temp;
		}
		else{
			temp->next = head;
			head = temp;
		}
	}
	void deleteItem(int position);
	void displayItems();

};

int main()
{
	ShoppingCart myCart;

	//how to add an item?
	myCart.addNewItem(10, 5);
	myCart.deleteItem(3);
	myCart.displayItems();


	return 1;
}