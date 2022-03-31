#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>

using namespace std; 



/*******************
 * Program: animal.h
 * author: hannah maung 
 * date: 2/17/2020
 * input: none
 * output: animal class
***************/

class Animal{

	protected:
		int age; 
		string name;
	public:
		Animal();
		int get_age();
		string get_name();
		void count_weeks();
};
#endif
