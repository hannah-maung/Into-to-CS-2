#include <iostream>
#include "animal.h"

using namespace std;




/*************
 * Program: animal.cpp
 * Author: hannah maung 
 * date: 2/17/2020
 * description: creates the animal class and keeps track of age in terms of weeks passed 
 * input: none
 * output: weeks passed, age
*************/


//animal constuctor 
Animal::Animal() {

}


//returns the age of the animals
int Animal::get_age() {

	return age;
}

// counts the numbers of weeks that have passed, increases age 
void Animal::count_weeks() {

	this-> age++;

	

}
