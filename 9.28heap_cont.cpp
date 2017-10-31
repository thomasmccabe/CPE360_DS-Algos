#include <iostream>
using namespace std;

class Cart{
public:
	int price;
	int rating;
	Cart *next;

	Cart(){
		price = 0;
		rating = 0;
		next = NULL;
	}
};

int main()
{
	Cart *head, *temp, * del;

	//adding first element to cart. set price = 10, ratings = 4
	head = new Cart; //adding first element to cart. set price = 10, ratings = 4
	head->price = 10; //head-> is like using a key to open a mailbox. has to be ->price/rating/next
	head->rating = 5;

	//create second element, first connected to second
	head->next = new Cart;
	head->next->price = 99;
	head->next->rating = 2;

	//create third, second connected to third
	head->next->next = new Cart;
	head->next->next->price = 54;
	head->next->next->rating = 3;

	//let's try to add a new item all the way to the front
	//step1: Use a temp pointer, and get that item in the heap
	temp = new Cart;
	temp->price = 100;
	temp->rating = 5;
	temp->next = head;
	head = temp;

	//verify
	cout << "First element: " << head->price << endl;
	cout << "Second element: " << head->next->price << endl;
	cout << "Third: " << head->next->next->price << endl;
	cout << "Fourth " << head->next->next->next->price << endl;

	//let's add a new item between the second and third
	temp = new Cart;
	temp->price = 1;
	temp->rating = 0;
	temp->next = head->next->next;
	head->next->next = temp;

	//let's go print the price of the third item
	cout << "Price: " << head->next->next->price << endl;

	//lets add a new thing between the fourth and fifth chunk
	temp = new Cart;
	temp->price = 5;
	temp->rating = 5;
	temp->next = head->next->next->next->next;
	head->next->next->next->next = temp;

	//let's traverse the structure
	temp = head; //start your other pointer at the very begining 
	while(temp !=NULL) {	//for(int i = 0; i < 6; i++) 
		cout << temp->price << endl;
		temp = temp->next;
	}

	//let's delete the last chunk
	// need two pointers
	//step1: take "del" to the chunk to be deleted
	//step2: take "temp" to the chunk before the chunk to be deleted
	del = head->next->next->next->next->next; 
	temp = head->next->next->next->next;
	temp->next = NULL; //cut the next one off
	delete del; //actually deletes the cut chunk

	//let's delete the first chunk
	del = head;
	head = head->next
	delete del;

	//let's delete the third chunk
	del = head->next->next;
	temp = head->next;
	temp->next = temp->next->next; //need this to link to the fourth chunk before deleting the third (same as head->next->next->next)
	delete del;

	return 1;
}

//Notes on Common Mistakes
//alwasys draw for these types of problems as a train or a bead of strings
//compiler does not effectively check for correctness for these types of problems
//silent errors
//last chunk must be null