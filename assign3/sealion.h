#ifndef SEALION_H
#define SEALION_H

#include <iostream>
#include "animal.h"
using namespace std;



/****************
 * Program: sealion.h 
 * Author: Hannah maung 
 * Date: 2/17/2020
 * Description: creates the Sealion class
**************/

class Sealion : public Animal {

	public:
		Sealion();
		Sealion(int age2);
		Sealion &operator = (const Sealion& num);
	private:




};
#endif
