#include <iostream> 
#include <fstream> 
#include "budgetbuddy.h"
#include <string> 
using namespace std; 
/***********************
 * Program: driver.cpp
 * Author: Hannah Maung 
 * Date: 01/19/2020
 * Description: includes the int main and function calls 
************************/


/*******************
 * Name: main
 * Type: int 
 * Description: calls functions, controls the program
 * Input: argc, argv
 * Output: sorted information by category 
*******************/
int main(int argc, char* argv[]) {

	string num; 
	commandline_check(argc, argv);
	check_num(num);

	int num_users, num_budget, num_transactions;
	string password2; 

	ifstream users_data;
	get_users_data(num_users, users_data, argv);
	user * user_db = create_user_db(num_users);
	fill_user_db(user_db, num_users, users_data); 

	users_data.close(); 

	ifstream budget_data; 
	get_budget_data(num_budget, budget_data, argv); 
	budget * budget_db = create_budgets(num_budget); 
	fill_budget_db(budget_db, num_budget, budget_data);

	num_transactions = transactions_budgets(budget_db, num_budget);

	transaction * transaction_db = create_alltransaction(budget_db, num_budget,num_transactions);

	int run = 1, count = 0, pass = 0; 
	
	cout << "------------------------" << endl << "Welcome to Budget Buddy, Log in to proceed" << endl << "------------------------" << endl << endl;

	while(!pass) {
		if(log_in(user_db,num_users, transaction_db, num_transactions)) {
			
			cout << endl << "Welcome in! " << endl << endl;
			pass = 1; 
		}
		else if(count == 2) {
			delete_info(user_db,budget_db,num_budget,num_users, transaction_db);
			return 0; 
		}
		count++;
	}

	while(run){
		run = menu(transaction_db, num_transactions);
		
	}
	delete_info(user_db,budget_db,num_budget,num_users,transaction_db);

}
