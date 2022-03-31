#include <iostream>
#include <cstdlib>
#include "zoo.h"
#include "bear.h"
#include "tiger.h"
#include "sealion.h"
#include <string>
using namespace std;

/*****************
 * Program: zoo.cpp
 * Author: Hannah Maung 
 * Date: 2/17/2020
 * Description: includes the functions that are a Zoo type
 * Input: nothing
 * Output: everything in the zoo functions
*****************/



/****************
 * Name: Zoo
 * Type: Zoo
 * Input: string name2
 * Output: creates array of bears, tigers, sealions 
 * Description: initializes the variables and creates arrays for each animal
****************/
Zoo::Zoo(string name2) {

	name = name2;
	num_sealions = 0;
	num_bears = 0;
	num_tigers = 0;
	balance = 100000;
	revenue = 0;
	cost = 0;
	weeks = 0;
	basecost = 80;	
 	bears = new Bear[num_bears];
	tigers = new Tiger[num_tigers];
	sealions = new Sealion[num_sealions];		


}

/****************
 * Name: ~Zoo
 * Type: Zoo
 * Input: nothing
 * Output: destructor
 * Description: deletes bears, tigers, sealions arrays
****************/
Zoo::~Zoo(){

	delete []  bears;
	delete []  tigers;
	delete [] sealions;

}

/****************
 * Name: Zoo
 * Type: Zoo
 * Input: const Zoo &num
 * Output: nothing
 * Description: non-default constructor 
****************/
Zoo::Zoo( const Zoo &num) {

	num_bears = num.num_bears;
	num_tigers = num.num_tigers;
	num_sealions = num.num_sealions;
	balance = num.balance;
	name = num.name;
}

/****************
 * Name: check_num
 * Type: int
 * Input: string name2
 * Output: returns 1,0
 * Description: checks if string is an integer or not 
****************/
int Zoo::check_num(string num) {
        int count = 0;

        for (int i = 0; i < num.length(); i++) {

                if (!((char(num.at(i)) >= '0') && (char(num.at(i)) <= '9'))) {
                        count = 1;
                }
        }

        if (count == 1) {
                return 1;
        }
        else {
                return 0;
        }
}
	


/****************
 * Name: print_instructions
 * Type: void
 * Input: nothing
 * Output: print statements 
 * Description: prints out the instructions of zoo tycoon 
****************/

void Zoo::print_instructions() {

	cout << "---------------------------WELCOME TO ZOO TYCOON-----------------------------" << endl << endl;


	cout << "---INSTRUCTIONS---" << endl;
	cout << "You are the owner of a zoo with no animals, but you have 100k in the bank." << endl;
        cout << "You will buy animals and a special event will occur every month by random" << endl << endl << endl;
	
}



/****************
 * Name: print_information
 * Type: void
 * Input: nothing
 * Output: print statements  
 * Description: prints out the weekly reports of the persons account, checks how many baby and adult babies they have in their zoo
****************/
void Zoo::print_information() {

	
	cout << "--- MONTHLY REPORT ---" << endl;
	cout << "Week: " << weeks << endl;
	cout << "The balance in your account: " << balance << endl;
	
	int count_a = 0 , count_b = 0; 
	for (int i = 0 ; i < num_bears; i++ ) {
		if (bears[i].get_age() < 26) {
			count_b++;
		}
		else{
			count_a++;
		}

	}	
	cout << "You have " << count_b << " baby bears" << endl;
	cout << "You have " << count_a << " adult bears" << endl;
	
	count_a = 0; count_b = 0;
	for (int i = 0; i < num_tigers; i++ ) {
		if (tigers[i].get_age() < 26) {
			count_b++;
		}
		else{
			count_a++;
		}

	}
	cout << "You have " << count_b << " baby tigers" << endl;
	cout << "You have " << count_a << " adult tigers" << endl;


	count_a = 0; count_b = 0;
	 for (int i = 0; i < num_sealions; i++ ) {
                if (sealions[i].get_age() < 26) {
                        count_b++;
                }
                else{
                        count_a++;
                }

        }

	cout << "You have " << count_b << " baby sealions" << endl;
	cout << "You have " << count_a << " adult sealions" << endl << endl;
}



/****************
 * Name: choose_animal
 * Type: void
 * Input: nothing
 * Output: print statement
 * Description: has the user choose what animal they want/what option out of the three
****************/

void Zoo::choose_animal() {

	cout << "----COST OF ANIMALS----"  << endl;
	cout << "Sea Lion for $700 (press 1), Tiger for $12k (press 2), Black Bear for 5k (press 3)" << endl;
	cout << "What animal would you like to buy: ";
	string input;
	getline(cin,input);
	int x = 0;
	int y = 0;

	while (!(x)) {
		if(check_num(input)) {
			cout << "Invalid, enter a 1,2,or 3: ";
			getline(cin,input);
			}
			else {
				y = atoi(input.c_str());
				if (y > 0 && y < 4) {
				x = 1;
				}
		
		else {
			cout << "Invalid, enter a 1,2,or 3: ";
			getline(cin,input);
		}

	}
}
	int z = 0;
	int a = 0;
	cout << "How many did you want to buy? (the max is 2): ";
	getline(cin,input);
	while(!(z)) {
		if (check_num(input)) {
			cout << "Invalid input, enter a 1 or 2: ";
			getline(cin,input);	
		}
		else {
			a = atoi(input.c_str());
			if (a > 0 && a < 3) {
				z = 1;
			} 
			else {
				cout << "Invalid, enter a 1 or 2: ";
				getline(cin,input);
			}
		}
			
	}

	for (int i = 0; i < a; i ++) {	
	
		if (y == 1) {
			purchase_sealion();

		}
		else if ( y == 2) {
			purchase_tiger();
		}

		else {
			purchase_bear();

		}	
		
	}
}



/****************
 * Name: count_weeks
 * Type: void
 * Input: int &run
 * Output: asks the user what they want to pick out of the three options 
 * Description: resets everything in the game for every month
****************/

void Zoo::count_weeks(int &run) {

	for(int j = 0; j < 4; j++){	
		for (int i = 0; i < num_bears; i++ ) {
			bears[i].count_weeks();
		}
		for (int i = 0; i < num_tigers;i++) {
			tigers[i].count_weeks();
		}
		for (int i = 0; i < num_sealions;i++) {
			sealions[i].count_weeks();
		}
	}
	weeks = weeks+4;

	bear_revenue();
	tiger_revenue();
	sealion_revenue();	
	bear_foodcost();
	tiger_foodcost();
	sealion_foodcost();	
	
	balance += revenue;
	balance -= cost;
	revenue = 0;
	cost = 0;

	if (balance < 0) {

		cout << "Game over, you have no money left in your account" << endl;
		run = 0;
	}

	cout << "----CHOICES----" << endl << endl;
	cout << "Buy animals (press 1), Don't buy animals (press 2), Quit the game (press 3)" << endl;
	string input;
	getline(cin, input);

	int num = 0;
	int ans = 0;

	while(!(num)) {
                if (check_num(input)) {
                        cout << "Invalid input, enter a 1,2,or 3: ";
                        getline(cin,input);
                }
                else {
                        ans = atoi(input.c_str());
                        if (ans > 0 && ans < 4) {
                                num = 1;
                        }
                        else {
                                cout << "Invalid, enter a 1,2 or 3: ";
                                getline(cin,input);
                        }
                }

        }


	print_information();
	if (ans == 1) {
		choose_animal();	
		event_random();			
	}
	else if (ans == 3) { 
		run = 0;
	}
}


/****************
 * Name: purchase_bear
 * Type: void
 * Input: nothing
 * Output: new balance 
 * Description: calculates balance, calls function  
****************/
void Zoo::purchase_bear() {
	balance = balance - 5000;
	adding_bear(208,1);
}

/****************
 * Name: purchase_tiger
 * Type: void
 * Input: nothing
 * Output: new balance 
 * Description: calculates balance, calls function  
****************/
void Zoo::purchase_tiger() {

	balance = balance - 12000;
	adding_tiger(208,1);
}



/****************
 * Name: purchase_sealion
 * Type: void
 * Input: nothing
 * Output: new balance 
 * Description: calculates balance, calls function  
****************/
void Zoo::purchase_sealion() {

	balance = balance - 700;
	adding_sealion(208,1);
}


/****************
 * Name: bear_revenue
 * Type: void
 * Input: nothing
 * Output: revenue
 * Description: calculates the revenue for bears  
****************/

void Zoo::bear_revenue() {

	for (int i = 0; i < num_bears; i++ ) {
		
		if(bears[i].get_age() < 25) {
			revenue += 1000;
		}

		else { 

			revenue +=500;
		}

	
	}
}

/****************
 * Name: tiger_revenue
 * Type: void
 * Input: nothing
 * Output: revenue
 * Description: calculates the revenue for tigers 
****************/
void Zoo::tiger_revenue() {

	for (int i = 0; i < num_tigers;i++) {
		if(tigers[i].get_age() < 25) {
			revenue += 2400;
		}	
		else {
			revenue += 1200;
		}
	}

}


/****************
 * Name: sealion_revenue
 * Type: void
 * Input: nothing
 * Output: revenue
 * Description: calculates the revenue for sealions
****************/
void Zoo::sealion_revenue() {

	for (int i = 0; i < num_sealions; i++ )
		if (sealions[i].get_age() < 25) {
			revenue += 280;
		}
		else {

		revenue += 140;

	}
}



/****************
 * Name: bear_foodcost
 * Type: void
 * Input: nothing
 * Output: base cost 
 * Description: randomly calculates the food cost based on the previous month, between 80-120%
****************/
void Zoo::bear_foodcost() {

	srand (time(NULL));	
		
	int random_cost = rand() % 80 + 120;
	basecost = basecost*(random_cost / 100);
	for (int i = 0; i < num_bears; i++ ) {
		cost = cost - (basecost * 3);	
	
	}

}

/****************
 * Name: tiger_foodcost
 * Type: void
 * Input: nothing
 * Output: base cost 
 * Description: randomly calculates the food cost based on the previous month, between 80-120%
****************/
void Zoo:: tiger_foodcost() {

	srand (time(NULL));
	int random_cost = basecost*(random_cost/100);

	basecost = basecost*(random_cost / 100);
        for (int i = 0; i < num_tigers; i++ ) {
                cost = cost - (basecost * 5);

	}
}


/****************
 * Name: sealion_foodcost
 * Type: void
 * Input: nothing
 * Output: base cost 
 * Description: randomly calculates the food cost based on the previous month, between 80-120%
****************/
void Zoo:: sealion_foodcost() {

        for (int i = 0; i < num_sealions; i++ ) {
                cost = cost - basecost;

        }

}

/****************
 * Name: adding_bear
 * Type: void
 * Input: int age, int num
 * Output: num_bears++
 * Description: adds a bear to the new array bears2 
****************/
void Zoo::adding_bear(int age, int num) {

	Bear * bears2 = new Bear[num_bears+1];
	for (int i = 0; i < num_bears; i++ ) {

		bears2[i] = bears[i];
	
	}
	
	for (int j = 0; j < num; j++) {
		Bear b(age);
		bears2[num_bears+j] = b;
		
	}


	delete [] bears;	
	
	bears = bears2;
	num_bears++;
}



/****************
 * Name: adding_tiger
 * Type: void
 * Input: int age, int num
 * Output: num_tigers++
 * Description: adds a tiger to the new array tigers2 
****************/
void Zoo::adding_tiger(int age, int num) {

	Tiger *tigers2 = new Tiger[num_tigers+1];
	for (int i = 0; i < num_tigers; i++) {

		tigers2[i] = tigers[i];
	}

	for (int j = 0; j < num; j++) {
		Tiger t(age);
		tigers2[num_tigers+j] = t;

	}
	delete [] tigers;
	
	tigers = tigers2;
	num_tigers++;
}



/****************
 * Name: adding_sealion
 * Type: void
 * Input: int age, int num
 * Output: num_sealions++
 * Description: adds a sealion to the new array sealions2 
****************/
void Zoo::adding_sealion(int age, int num) {

	Sealion *sealions2 = new Sealion[num_sealions+1];

	for (int i = 0; i < num_sealions; i++ ) {

		sealions2[i] = sealions[i];
	}
	
	for(int j = 0 ; j < num; j++){
		Sealion s(age);
		sealions2[num_sealions+j] = s;
	} 
	delete [] sealions;

	sealions = sealions2;
	num_sealions++;
}




/****************
 * Name: baby_bear
 * Type: void
 * Input: nothing
 * Output: adding_bear information 
 * Description: since bears have 2 babies, this adds 2 bears, 0 years old 
****************/
void Zoo::baby_bear() {

	adding_bear(0, 2);
}




/****************
 * Name: baby_tiger
 * Type: void
 * Input: nothing
 * Output: adding_tiger information 
 * Description: since tigers have 3 babies, this adds 3 tigers,  0 years old 
****************/
void Zoo::baby_tiger() {

	adding_tiger(0,3);
}


/****************
 * Name: baby_sealion
 * Type: void
 * Input: nothing
 * Output: adding_sealion information 
 * Description: since sea lions have 1 baby at a time, this adds 1 sea lion, 0 years old 
****************/
void Zoo::baby_sealion() {

	adding_sealion(0,1);
}




/****************
 * Name: sick_bear
 * Type: void
 * Input: nothing
 * Output: print statements
 * Description: checks the balance of the account to see if the bear can be saved if it gets sick 
****************/
void Zoo::sick_bear() {

	cout << "Your bear is sick!" << endl;

	if (balance > 2500) {
		cout << "CONGRATS, you have enough money in your account to care for the sick bear" << endl;
		balance = balance - 2500;
	}
	else {
		cout << "You do not have enough money in your account, the sick bear died and will be removed from the zoo" << endl;

	}

}

/****************
 * Name: sick_tiger
 * Type: void
 * Input: nothing
 * Output: print statements
 * Description: checks the balance of the account to see if the tiger can be saved if it gets sick 
****************/
void Zoo::sick_tiger() {

	cout << "Your tiger is sick!" << endl;

	if (balance > 6000) {
		cout << "CONGRATS, you have enough money in your account to care for the sick tiger" << endl;
		balance = balance - 6000;

	}

	else {

		cout << "You do not have enough money in your account, the sick tiger died and will be removed from the zoo" << endl;
	}

}



/****************
 * Name: sick_sealion
 * Type: void
 * Input: nothing
 * Output: print statements
 * Description: checks the balance of the account to see if the sea lion can be saved if it gets sick 
****************/
void Zoo::sick_sealion() {

	cout << "Your sealion is sick! " << endl;
	
	if (balance > 350) {
		cout << "CONGRATS, you have enough money in your account to care for the sick sealion" << endl;
		balance = balance - 350;
	}
	else {

		cout << "You do not have enough money in your account, the sick sea lion died and will be removed from the zoo" << endl;
	}

}



/****************
 * Name: sick_random
 * Type: void
 * Input: nothing
 * Output: print statements
 * Description: randomly picks which animal gets sick by the rand() function, calls that specific animal function 
****************/
void Zoo::sick_random() {

	srand(time(NULL));
	int which_animal;
	
	for (int i = 0; i < 3; i++) {
	which_animal = rand()% 3 + 1;
		if (which_animal == 1) {
			sick_bear();
			break;

		}
		else if (which_animal == 2) {

			sick_tiger();
			break;
	
		}
		else {
			sick_sealion();
			break;
		}
	}

}


/****************
 * Name: birth_random
 * Type: void
 * Input: nothing
 * Output: print statements
 * Description: randomly picks which animal gives birth by the rand() function, calls that specific animal function 
****************/
void Zoo::birth_random() {


	srand(time(NULL));
	int which_animal, i, count = 0;

       		which_animal = rand()% 3 + 1;
                if (which_animal == 1) {
 			for(i = 0; i < num_bears; i++){
				if (bears[i].get_age() > 208) {
					count++;
                		}
			}
			if(count >=2 ){ 
				baby_bear(); 
			}
			else {
				cout << "You have no adult bears that are able to give birth" << endl;
			}
		}
                else if (which_animal == 2) {
			for (i = 0; i < num_tigers;i++) {
				if (tigers[i].get_age() > 208) {
					count++;
                		}
			}
			if (count >=2) {
				baby_tiger();
				
			}	
			else {
				cout << "You have no adult tigers that are able to give birth" << endl;
			}
		}
		else {
			for (i = 0; i < num_sealions; i++) {
				if (sealions[i].get_age() > 208) {
                        		count++;
				}
			}
			if (count >=2) {
				baby_sealion();
                	}
			
			else {
				cout << "You have no adult sea lions that are able to give birth" << endl;
			}
        	}

}


/****************
 * Name: sealion_bonus
 * Type: void
 * Input: nothing
 * Output: nothing
 * Description: a special event, when a boom occurs then a random revenue bonus for sealions occurs 
****************/
void Zoo::sealion_bonus() {

	srand(time(NULL));
	int r = rand() % 150 + 400;
	int x = num_sealions*r;
	revenue = x; 	
	cout << "A boom in zoo attendance occured. Each sea lion you have generated a random amount of extra bonus revenue! " << endl;
	cout << "Your random revenue amount is: " << x << endl;


}


/****************
 * Name: event_random
 * Type: void
 * Input: nothing
 * Output: special event 
 * Description: picks out of 4, which special event occurs randomly with the rand() function, calls that specific function so that the event occurs 
****************/
void Zoo::event_random() {

	srand(time(NULL));
	int which_event;

	
	for (int i = 0; i < 4; i++) {
	which_event = rand() % 4 + 1;
		if (which_event == 1) {
			cout << endl << "----SPECIAL EVENT: SICK ANIMAL----" << endl;		
			sick_random();
			break;
		}
		else if (which_event == 2) {
			cout << endl << "----SPECIAL EVENT: ANIMAL GIVES BIRTH" << endl;
			birth_random();
			break;
		}
		else if (which_event == 3) {
			cout << endl << "----SPECIAL EVENT: A BOOM IN ATTENDANCE----" << endl;
			sealion_bonus();			
			break;
		}
		else { 
			cout << "----SPECIAL EVENT: NONE----" << endl;	
			cout << "No special event occurs during this month" << endl;
			break;
		}
	}	

}


/****************
 * Name: play_game
 * Type: void
 * Input: nothing
 * Output: nothing 
 * Description: runs the game by calling the functions 
****************/
void Zoo::play_game() {

        print_instructions();
        print_information();
	choose_animal();
	
	int run = 1;
	while(run){
		count_weeks(run);
	}


}



