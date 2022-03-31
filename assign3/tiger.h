#ifndef TIGER_H
#define TIGER_H

#include <iostream>
#include "animal.h"

using namespace std;




/***************
 * Program: tiger.h
 * Description: creates the Tiger class 
 * Author: Hannah Maung 
 * Date: 2/17/2020
**************/

class Tiger : public Animal{

	public:
		Tiger();
		Tiger(int);
		Tiger &operator=(const Tiger& num);
	private:




};
#endif
