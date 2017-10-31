#include <iostream>
#include <stdlib.h>
using namespace std;
 
//idea of an "item"; we want a stack of such items
class Item{
public:
	int value;
	Item *next;

	Item(){
		value = 0;
		next = NULL;
	}
};

class stack{
public:
	Item*head;

	stack(){
		head = NULL; //start with an empty stack
	}

	//adds things to instel. Hint: Add to the head end
	void push(int x) {
		//First, let's go and get an 'item' from the heap
		Item *temp;
		temp = new Item;
		temp->value = x;

		//is it empty?
		if(head==NULL){
			head = temp;
		}
		else {
			temp->next = head;
			head = temp;
		}
	}

	//remove an element from iteslf. Hint: Remove the first element
	void pop(int){
		//is it empty?
		if(head == NULL) {
			cout << "Oops, this stakc is empty!" << endl;
		}
		else{
			//just remove the first item
			Item *temp;
			temp = head;
			head = head->next;
			cout << "About to delete: " << temp->value << endl;
			delete temp;
		}
	}

	//display contents
	void display(){
		if(head == NULL) {
			cout << "Stack is empty. Nothing to display." << endl;
		}
		else{
			Item*traverse;
			traverse = head;
			cout << "===========" << endl;
			while(traverse != NULL){
				cout << traverse->value << endl;
				traverse = traverse->next;
			}
			cout << "===========" << endl;
		}

	}
};


int main(){
	stack myStack;
	int choice;

	while(1){
		cout << "Press 1 to push!" << endl;
		cout << "Press 2 to pop!" << endl;
		cout << "Press 3 to display!" << endl;
		cout << "Anything else to quit." << endl;
		cin >> choice;
		switch(choice){
			case 1 : cout << "Push what?" << endl;
				int value;
				cin >> value;
				myStack.push(value);
				break;

			case 2 : myStack.pop(value);
				break;


			case 3 : myStack.display();
				break;

			default : exit(1);
		}
	}

	return 1;
}