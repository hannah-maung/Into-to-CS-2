#include <iostream>
#ifndef NODE_H
#define NODE_H

using namespace std;
/***************
 * Program: node.h
 * Author: Hannah Maung 
 * Date: 3/15
 * Description: creates the class called Node
 * Input: n/a
 * Output: creates Node variables
**************/

class Node {
	public:
		int val;    // the value that this node stores
		Node *next; // a pointer to the next node in the list

		Node();
		~Node();
		//void control();
		//void menu();
};

	Node * merge_ascending(Node * head, Node * head2);
	Node * merge_descending(Node * head, Node * head2);
	
	void menu();
#endif
