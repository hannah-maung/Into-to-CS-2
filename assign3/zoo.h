#ifndef ZOO_H
#define ZOO_HI
#include "tiger.h"
#include "sealion.h"
#include "bear.h"
#include <iostream>
#include <string>
using namespace std;

/************************
 * Program: zoo.h
 * Author: Hannah Maung 
 * Date: 2/17/2020
 * Description: creates the zoo class 
 * Input: none
 * Output: creates variables in the zoo class 
************************/

class Zoo{

	private:

		string name;
		int num_sealions;
		int num_bears;
		int num_tigers;
		float balance;
		float revenue;
		float cost;
		int weeks;
		int basecost;
		Bear * bears;
		Tiger * tigers;	
		Sealion * sealions;

	public:
	
		Zoo(string name);
		Zoo(const Zoo&);
		~Zoo();
		void print_instructions();
		int check_num(string);
		void print_information();
		void play_game();
		void choose_animal();
		void purchase_bear();
		void purchase_tiger();
		void purchase_sealion();
		void bear_revenue();
		void tiger_revenue();
		void sealion_revenue();
		void bear_foodcost();
		void tiger_foodcost();
		void sealion_foodcost();
		void adding_bear(int,int);
		void adding_tiger(int,int);
		void adding_sealion(int,int);
		void baby_bear();
		void baby_tiger();
		void baby_sealion();
		void sick_bear();
		void sick_tiger();
		void sick_sealion();
		void count_weeks(int &run);
		void sick_random(); 
		void birth_random();
		void sealion_bonus();
		void event_random();
};
#endif



