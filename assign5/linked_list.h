#include <iostream>
#include "node.h"
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

using namespace std;



/********************
 * Program: Linked_List.h
 * Author: Hannah Maung
 * Date: 3/15
 * Description: creates the Linked_List class
 * Input: n/a
 * Output: all the Linked_List variables
******************/
class Linked_List{


        private:
                unsigned int length;
                Node *front;
		Node *back;
        public:
		Linked_List();
		~Linked_List();
		int check_num(string);	
                int get_length();
                void print();
                void clear();
		unsigned int push_front(int);
                unsigned int push_back(int);
                unsigned int insert(int val, unsigned int index);
                void sort_ascending();
                void sort_descending();
		unsigned int put_in(int, int);
		void sort(Node** h, int);
		bool return_prime(Node &v);
		void is_prime();
		//void print_prime();
		//void ask_user();
		//void another_num();
		string another();

};

#endif
