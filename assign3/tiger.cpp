#include <iostream>
#include "animal.h"
#include "tiger.h"

using namespace std;

/********
 * Program: tiger.cpp
 * Author: Hannah Maung 
 * Date: 2/17/2020
 * Description: creates the tiger constructors 
 * Input: none
 * output: none
*********/


//Default constructor
Tiger::Tiger() {

	age = 0;

}

//Alternate constructor
Tiger:: Tiger(int age2) {

	age = age2;

}

//operator constructor 
Tiger & Tiger::operator=(const Tiger& num) {

	this-> age = num.age;
	return *this;

}
