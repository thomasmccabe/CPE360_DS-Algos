#include <iostream>
#include <stdlib.h>
using namespace std;

class Item{
public:
	int value;
	Item *next;

	Item(){
		value = 0;
		next = NULL;
	}
};

class queue{
public:
	Item *head;
	//int len; (for LL assignment)
	//keep track of how many things you have in the list

	queue(){
		head = NULL;
	}

	//adding things to a Q
	void enqueue(int x){
		Item *temp = new Item;
		temp->value = x;

		if(head == NULL){
			head = temp;
		}
		else{
			temp->next = head;
			head = temp;
		}
	}

	//removing things from a Q
	void dequeue(){
		Item*slow, *fast;
		if(head == NULL){
			cout << "Q is empty, nothing to do." << endl;
		}
		else{
			slow = fast = head;
			//fast should point to the last item; and slow to the second-last
			while(fast->next != NULL){
				slow = fast;
				fast = fast->next;
			}
			//at this point, fast is onto the item to be deleted
			//and slow is to the parent of that item
			cout << "About to delete: " << fast->value << endl;
			delete fast;
			slow->next = NULL;
		}
	}

	//display contents
	void display(){
		cout << "--------------------------------" << endl;
		if(head == NULL){
			cout << "The queue is empty. There is nothing to display." << endl;
		}
		else{
			Item*traverse;
			traverse = head;
			cout << "============" << endl;
			while(traverse != NULL){
				cout << traverse->value << endl;
				traverse = traverse->next;
			}
			cout << "============" << endl;
		}
	}

};

int main(){
	queue myQueue;
	int choice;

	while(1){
		cout << "Press 1 to enqueue!" << endl;
		cout << "Press 2 to dequeue!" << endl;
		cout << "Press 3 to print queue!" << endl;
		cin >> choice;
		switch(choice){
			case 1 : cout << "Enqueue what?" << endl;
				int x;
				cin >> x;
				myQueue.enqueue(x);
				break;

			case 2 : myQueue.dequeue();
				break;

			case 3 : myQueue.display();
				break;

			default : exit(1);
		}
	}

	return 1;
}