#include <iostream>
#include "zoo.h"
#include <fstream>
#include "bear.h"
#include "sealion.h"
#include "tiger.h"
#include "animal.h"

/************
 * Program: driver.cpp
 * Author: Hannah Maung 
 * Input: nothing
 * Output: all the zoo tycoon information 
 * Date: 2/17/2020
************/
int main() {

	int run = 1;
	string n;
	cout << "Enter your zoo tycoon name: ";
	getline(cin,n);
	
	Zoo z(n);
	
	z.play_game();	


}
