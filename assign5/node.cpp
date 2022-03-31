#include <iostream>
#include "node.h"
#include "linked_list.h"

using namespace std;

/**********************
 * Program: node.cpp
 * Name: Hannah Maung 
 * Date: 3/15
 * Description: holds all the function for the Node class
 * Input: nothing
 * Output: all of the node functions
*********************/


/**********************
 * Name: Node
 * Type: Node
 * Description: Node constructor
 * Input: nothing
 * Output: sets the variables in the Node class
*********************/
Node::Node() {

	next = NULL;
	val = 0;

}

/**********************
 * Name: ~Node
 * Type: Node
 * Description: Node destructor
 * Input: nothing
 * Output: nothing
*********************/
Node::~Node() {

	delete next;

}

/**********************
 * Name: merge_ascending 
 * Type: Node *
 * Description: connects the nodes of the linked list in an ascending order 
 * Input: Node * head, Node * head2
 * Output: nodes are sorted 
*********************/
Node * merge_ascending(Node * head, Node * head2) {

	if (head == NULL) {
		return head2;
	}

	if (head2 == NULL) {
		return head;
	}

	Node * first = new Node;
	Node * sec  = new Node;
	Node * third  = new Node;
	
	first = head;

	while (head2 != NULL) {

		sec = head2;
		head2 = head2->next;
		sec ->next = NULL;

		if ((head->val) > (sec->val)) {
			sec->next = head;
			head = sec;
			first = head;
		}

		flag:
		if(first->next == NULL) {
			first->next = sec;
			first = first->next;
		}
		else if (first->next->val <= sec->val) {
			first = first->next;
			goto flag;
		}
		else {
			third = first->next;
			first->next = sec;
			sec->next = third;
			
		}
	}	
	return head;
}


/**********************
 * Name: merge_descending
 * Type: Node *
 * Description: connects the nodes of the linked list in a descending order
 * Input: Node * head, Node * head2
 * Output: nodes are sorted
*********************/
Node * merge_descending(Node * head, Node * head2) {

        if (head == NULL) {
                return head2;
        }

        if (head2 == NULL) {
                return head;
        }

        Node * first = new Node;
        Node * sec  = new Node;
        Node * third  = new Node;

        first = head;

        while (head2 != NULL) {

                sec = head2;
                head2 = head2->next;
                sec ->next = NULL;

                if ((head->val) < (sec->val)) {
                        sec->next = head;
                        head = sec;
                        first = head;
                }

                flag:
                if(first->next == NULL) {
                        first->next = sec;
                        first = first->next;
                }
                else if (first->next->val <= sec->val) {
                        first = first->next;
			goto flag;
                }
                else {
                        third = first->next;
                        first->next = sec;
                        sec->next = third;

                }
        }

        return head;
}

/**********************
 * Name: control
 * Type: void
 * Description: calls functions from linked_list class, sorts list in ascending or descending order 
 * Input: nothing
 * Output: function calls
*********************/
void control() {

	Linked_List l;
	
	string ans;
	ans = l.another();
	if (ans == "a") {
		l.sort_ascending();

	}	
	else{
		l.sort_descending();
	}
	l.is_prime();
	l.clear();

}

/**********************
 * Name: menu
 * Type: void
 * Description: asks user if they want to repeat 
 * Input: nothing
 * Output: repeats or exists
*********************/
void menu() {

	int run = 1;

	while(run) {
		control();
		cout << "Would you like to do this again? (y or n): ";
		char x;
		cin >> x;

	if (x == 'n') {
		cout << "EXITING..." << endl;
		run = 0;
	}

	}


}




