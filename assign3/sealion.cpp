#include <iostream>
#include "sealion.h"
#include "animal.h"
using namespace std;

/*********************
 * Program: sealion.cpp
 * Author: Hannah Maung 
 * Date: 2/17/2020
 * Desciption: Creates constructors for Sealion class
 * Input: none
 * Output: none
********************/


//Sealion default constructor
Sealion::Sealion() {

	age = 0;

}

//Sealion alternate construtor
Sealion::Sealion(int age2) {


	age = age2;

}

//Operator Overload
Sealion & Sealion::operator=(const Sealion& num) {

	this-> age = num.age;
	return *this;


}
