#ifndef BEAR_H
#define BEAR_H
#include <iostream>
#include "animal.h"

using namespace std;



/***********************
 * Program: bear.h
 * Author: Hannah Maung 
 * Date: 2/17/2020
 * Description: creates the Bear class
*********************/

class Bear: public Animal {
	private:
	
	public:
		Bear();
		Bear(int);
		Bear&operator=(const Bear& age);
};
#endif
