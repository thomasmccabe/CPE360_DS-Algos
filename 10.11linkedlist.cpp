#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
	int data;
	node *next;
};

class list{
public:
	node *head,*tail;

	list(){
			head = NULL;
			tail = NULL; 
		}

	//insert node at start
	void insert_start(int value){
		node *temp = new node;
		temp->data = value;
		temp->next = head;
		head = temp;
	}

	//insert at a certain position
	void insert_position(int pos, int value){
		node *present = new node; //pass the address of the new node in the next field of the previous one
		node *current = new node; //pass the address of the current node in the next field of the new node
		node *temp = new node;
		current = head;
		for(int i = 1; i < pos; i++){
			present = current;
			current = current->next;
		}
		temp->data = value;
		present->next = temp;
		temp->next = current;
	}

	//delete at a position
	void delete_position(int pos){
		node *current = new node;
		node *previous = new node;
		current = head;
		for(int i=1; i < pos; i++){
			previous = current;
			current = current->next;
		}
		previous->next=current->next;
	}


	//display the linked list
	void display(){
		cout << "=================================" << endl;
		if(head == NULL){
			cout << "The list is empty. There is nothing to display." << endl;
		}
		else{
		node *temp = new node;
		temp = head;
		while(temp != NULL){
			cout << temp->data <<"\t";
			temp = temp->next;
		}
	}
		cout << "\n===============================" <<endl;
	}
};

int main(){

	list mylist;
	int choice;

	cout << "Linked List Menu" << endl;
	cout << "What would you like to do?" << endl;

	while(1){
		cout << "Press 1 to insert a node at the start." << endl;
		cout << "Press 2 to insert a node at a position." << endl;
        cout << "Press 3 to delete a node at a position." << endl;
        cout << "Press 4 to display list." << endl;
        cout << "Press anything else to exit." << endl;
        cin >> choice;

        switch(choice){
        	case 1 : cout << "Insert what value?" << endl;
        		int value;
        		cin >> value;
        		mylist.insert_start(value);
        		break;

        	case 2 : cout << "1st type where to insert. Then, type the value?" << endl;
    			int pos;
    			cin >> pos;
    			cin >> value;
        		mylist.insert_position(pos,value);
        		break;

        	case 3 : cout << "Delete which position?" << endl; 
    			cin >> pos;
        		mylist.delete_position(pos);
        		break;

        	case 4 : mylist.display();
        		break;

        	default : exit(1);

        }
    }
}
