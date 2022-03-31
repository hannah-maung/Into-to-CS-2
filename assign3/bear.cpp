#include <iostream>
#include "bear.h"
#include "animal.h"

using namespace std;

/*****************
 * Program: bear.h
 * Author: Hannah Maung
 * Date: 2/17/2020
 * Description: Creates the bear class and constructors 
 * Input: none 
 * Output: none
*****************/


//Default constructor 
Bear::Bear() {

	age = 0;

}


//alternate constructor
Bear::Bear(int age2) {

	age = age2;

}

//operator overload
Bear& Bear::operator=(const Bear& num) {

	this-> age=num.age;
	return *this;

}
