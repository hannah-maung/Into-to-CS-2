#include <iostream>
#include <cstdlib>
#include "linked_list.h"
#include "node.h"

/******************
 * Program: linked_list.cpp
 * Author: Hannah Maung
 * Date: 3/15
 * Description: holds all of the Linked_List functions
***************/

using namespace std;

/**********************
 * Name: Linked_List
 * Type: Linked_List
 * Description: class constructor
 * Input: nothing
 * Output: sets variables 
*********************/
Linked_List::Linked_List() {


	front = NULL;
	back = NULL;
	length = 0;

}

/**********************
 * Name: ~Linked_List
 * Type: Linked_List
 * Description: destructor
 * Input: nothing
 * Output: deletes temp numbers
*********************/
Linked_List::~Linked_List() {

	for (int i = 0; i < length; i++) {
		Node * temp;
		temp = front;
		front = front->next;
		delete temp;			

	}
	this->length = 0;
}


/**********************
 * Name: check_num
 * Type: int
 * Description: checks if the string is a number or not
 * Input: string num
 * Output: returns 1 or 0
*********************/
int Linked_List::check_num(string num) {
        int count = 0;

        for (int i = 0; i < num.length(); i++) {

                if (!((char(num.at(i)) >= '0') && (char(num.at(i)) <= '9'))) {
                        count = 1;
                }
        }

        if (count == 1) {
                return 1;
        }
        else {
                return 0;
        }
}


/**********************
 * Name: print
 * Type: void
 * Description: prints out linked list
 * Input: nothing
 * Output: printed out list
*********************/
void Linked_List::print() {

	Node *temp = new Node;
	temp = front;
	
	cout << "Linked List: ";
	if (temp!= NULL) {

		cout << temp->val << " ";
		temp = temp->next;
	}

}

/**********************
 * Name: clear
 * Type: void
 * Description: clears memory
 * Input: nothing
 * Output: empty memory
*********************/
void Linked_List::clear() {

	for(int i = 0; i < length; i++) {
		Node *temp;
		temp = front;
		front = front->next;
		delete temp;

	}

	this->length = 0;
}

/**********************
 * Name: push_front
 * Type: unsigned int
 * Description: pushes the value passed and makes it the node of the head
 * Input: int f
 * Output: length
*********************/
unsigned int Linked_List::push_front(int f) {

	this->length++;

	Node * temp = new Node;
	temp->val = f;
	temp->next = front;	
	front = temp;
	
	return this->length;
}

/**********************
 * Name: push_back
 * Type: unsigned int 
 * Description: pushes the value to the back of the linked list 
 * Input: int b 
 * Output: length
*********************/
unsigned int Linked_List::push_back(int b) {
	
	this->length++;

	Node * temp = new Node;

	if (front == NULL){
		front = temp;
		back = temp;
		temp = NULL;
	}
	else {
		back->next = temp;
		back = temp;
	}

	return this->length;
}



/**********************
 * Name: put_in
 * Type: unsigned int
 * Description: inserts a value at different point of the linked list
 * Input: int val, int place
 * Output: length
*********************/
unsigned int Linked_List::put_in(int val, int place) {
	
	Node * first = new Node;
	Node * second = new Node;
	Node * third = new Node;

	first->val = val;
	third = front;
	int in = 0;
	if (front != NULL) {
		int in2 = in + 1;
		while(third->next != NULL) {
			second = third;
			third = third->next;
			in++;
		}
		if(in == 0) {
			push_front(val);
		}
		else if (place > in2) {
			
		}
		else {

			third->next = first;
			first->next = third;
		}

	}
	else {

		front = first;
		first->next = NULL;
	}
	this->length++;
	return length;
		
}

/**********************
 * Name: sort_ascending
 * Type: void
 * Description: calls the sort function which sorts the list in an ascending order
 * Input: nothing
 * Output: linked list in ascending order
*********************/
void Linked_List::sort_ascending() {
	sort(&front,1);
}

/**********************
 * Name: sort_descending
 * Type: void
 * Description: calls the sort function which sorts the list in a descending order
 * Input: nothing
 * Output: linked list in a descending order
*********************/
void Linked_List::sort_descending() {

	sort(&front,2);
}

/**********************
 * Name: sort
 * Type: void
 * Description: sorts the linked list to merge ascendingly or descendingly
 * Input: Node **h, int choice
 * Output: linked list is sorted by recursive merge sort in an ascending or descending way
*********************/
void Linked_List::sort(Node ** h, int choice ) {

	Node *first = new Node;
	Node *second = new Node;
	Node *temp = new Node;
	first = *h;
	temp = *h;

	if (first == NULL || first->next == NULL) {
		
	}
	else{ 
		while(first->next != NULL) {
			first = first->next;
			if(first->next != NULL) {
				temp = temp->next;
				first = first->next;
			}

		}
		second = temp->next;
		temp->next = NULL;
		first = *h;
	}
	sort(&first, choice);
	sort(&second, choice);

	if (choice == 1) {
		*h = merge_ascending(first, second);
	}
	else {
		*h = merge_descending(first, second);
	}

}

/**********************
 * Name: return_prime
 * Type: bool
 * Description: returns true or false if the number is prime or not 
 * Input: node &v
 * Output: returns true or false 
*********************/
bool Linked_List::return_prime(Node & v) {

	for (int i = 2; i < v.val; i++ ) {
		if(v.val < 0) {
			return false;
		}
		else if (v.val % i == 0) {
			return false;
		}
		else if (v.val == 0 || v.val == 1) {
			return false; 
		}
		else {
			return true; 
		}
	}
}

/**********************
 * Name: is_prime
 * Type: void
 * Description: checks if the numbers in the linked list are prime or not
 * Input: nothing
 * Output: prints out the number of prime numbers  
*********************/
void Linked_List::is_prime() {

	int count;
	count = 0;
	Node * temp = new Node;

	temp = front;
	for (int i = 0; i < length; i++) {
		if (return_prime(*temp)) {
			count++;
		}

		temp = temp->next;
	}
	cout << "This list has " << count << " prime numbers" << endl;
}


/**********************
 * Name: another
 * Type: string
 * Description: asks the user for the numbers in the linked list 
 * Input: nothing
 * Output: nothing
*********************/
string Linked_List::another() {

	int x = 0;
        cout << "Enter a number; ";
        string input;
        getline(cin, input);
        int a;
        a = atoi(input.c_str());
        push_front(a);
        
	int run = 1;
	while(run){
		while(!(x)) {
                	if (check_num(input)) {
                        	cout << "Invalid, enter a number: ";
                        	getline(cin, input);
                     		int p;
                        	p = atoi(input.c_str());
               		       	push_front(p);
                	}
              		else {
                        	x = 1;
                	}
        	}
		cout << "Do you want to add another number (y or n): ";
                char input;
                cin >> input;
                if (input == 'y') {
                        cout << "Enter a number: ";
                        int x;
                        cin >> x;
                        push_front(x);
                }
                else{
                        run = 0;
			
		}
	}
	cout << "Do you want it sorted ascending or descending order (a or d)?: ";
	cout << endl;
	string ans;
	getline(cin,ans);
	return ans;

}


