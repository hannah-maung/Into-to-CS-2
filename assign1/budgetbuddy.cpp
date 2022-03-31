#include <iostream> 
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include "budgetbuddy.h"
using namespace std; 

/**************
 *Program : budgetbuddy.cpp
 *Author: Hannah Maung 
 *Date: 01/19/2019
 *Description: Includes all the function used for this program 1
***************/


/***************
 * Name: create_user_db 
 * Type: user*
 * Description: Creating a dynamically allocated array to create an array for all the users 
 * Input: num_users
 * Output: users_db 
****************/
user* create_user_db(int num_users){

	user* users_db = new struct user[num_users];

	return users_db; 

}

/***************
 * Name: get_users_data
 * Type: void 
 * Description: Creating a function that gets users data as the first argument of the command line 
 * Input: num_users, users_data, argv[]
 * Output: parses x cstring to an integral number 
****************/

void get_users_data(int & num_users, ifstream & users_data, char * argv[]){

	string x;
	users_data.open(argv[1], ifstream::in); 
	users_data >> x; 
	num_users = atoi(x.c_str()); 
	
}


/**************
 * Name: fill_user_db 
 * Type: void 
 * Description: Fills the user_db array with all the information in the .txt file 
 * Input: user_db, num_users, data
 * Output: x, the inputs of each variable in the struct 
*****************/
void fill_user_db(user* user_db, int num_users, ifstream & data) {

	string x; 
	
	for(int i = 0; i < num_users; i++) {

		getline(data, x, ' '); 
		user_db[i].name = x; 

		getline(data,x, ' '); 
		user_db[i].id = atoi(x.c_str()); 
	
		getline(data, x);
		user_db[i].password = x; 
	}
}

/**************
 * Name: create_budgets
 * Type: budget*
 * Description: Creates a dynamically allocated array called create_budgets for all the budgets in the file
 * Input: num_budget
 * Output: budget_db 
******************/
budget* create_budgets(int num_budget){

	budget* budget_db = new struct budget[num_budget]; 
	return budget_db;
}

/**************
 * Name: get_budget_data
 * Type: void
 * Description: Creating a function that gets the budget data as the second argument of the command line 
 * Input: num_budget, budget_data, argv[]
 * Output: parses the x cstring an an integral number to represent the number of budgets 
******************/
void get_budget_data(int &num_budget, ifstream & budget_data, char * argv[]) {
	
	string x;
	budget_data.open(argv[2], ifstream::in); 
	budget_data >> x;
	num_budget = atoi(x.c_str()); 	

}

/**************
 * Name: fill_budget_db 
 * Type: void
 * Description: Fills the budget_db array with all the information in the .txt file of the second command line argument
 * Input: budget_db, num_budget, data
 * Output: x, the inputs of each variable in the struct 
******************/
void fill_budget_db(budget* budget_db, int num_budget, ifstream & data) {

	string x; 

	for (int i = 0; i < num_budget; i++) {

                getline(data, x, ' ');
                budget_db[i].id = atoi(x.c_str());

                getline(data, x, ' ');
                budget_db[i].balance = atof(x.c_str()); 

                getline(data, x);
                budget_db[i].num_transactions = atoi(x.c_str());

		budget_db[i].t = create_transactions(budget_db[i].num_transactions); 
		
		get_transaction_data(budget_db[i].t, budget_db[i].num_transactions, data); 
		
	}

}
	
/**************
 * Name: create_transactions
 * Type: transaction*
 * Description: Creates a dynamically allocated array called create_transactions 
 * Input: num_transaction
 * Output: transaction_db
******************/
transaction* create_transactions(int num_transaction) {

	transaction* transaction_db = new struct transaction[num_transaction];
	return transaction_db; 
	
}

/***********
 * Name: get_transaction_data
 * Type: void 
 * Description: Fills the transaction_db array with all the transactions in the .txt file of the second command line argument 
 * Input: transaction_db, num_transaction, data
 * Output: x, the inputs of each variable in the struct 
************/
void get_transaction_data(transaction* transaction_db, int num_transaction, ifstream & data) {

	string x; 
	for (int i = 0; i < num_transaction; i++){ 

		getline(data, x, ' ');
		transaction_db[i].date= x; 

		getline(data,x,' '); 
		transaction_db[i].amount = atof(x.c_str()); 

		getline(data,x, ' '); 
		transaction_db[i].description = x; 

		getline(data,x); 
		transaction_db[i].category = x; 
	}

}

/****************
 * Name: create_alltransaction
 * Type: transaction 
 * Description: Creates an array of all the transactions 
 * Input: budget_db, num_budgets, all_transactions 
 * Output: alltransaction_db
*****************/
transaction* create_alltransaction( budget * budget_db, int num_budgets, int all_transactions) {

	transaction* alltransaction_db = new struct transaction[all_transactions];

	int count = 0;

	for(int i = 0; i < num_budgets; i++){
		for(int j = 0; j < budget_db[i].num_transactions; j++){
			alltransaction_db[count].date = budget_db[i].t[j].date;
			alltransaction_db[count].amount = budget_db[i].t[j].amount;
			alltransaction_db[count].category = budget_db[i].t[j].category;
			alltransaction_db[count].description = budget_db[i].t[j].description;
			count++;	
		}
	}	

	return alltransaction_db; 


}


/*******************
 * Name: transactions_budgets
 * Type: int
 * Description: adds the old array of transactions to the new array
 * Input: budget_db, num_budget
 * Output: all
*******************/
int transactions_budgets(budget * budget_db, int num_budget) {

	int all = 0; 
	for (int i = 0; i < num_budget; i++) {
		all = budget_db[i].num_transactions + all; 
	}

	return all;
}


/*************
 * Name: delete_info
 * Type: void 
 * Description: deletes the memory that was dynamically allocated 
 * Input: user_db, budget_db, num_budgets, num_users 
 * Output: deletes all the memory
**************/
void delete_info(user* user_db, budget* budget_db, int num_budgets, int num_users, transaction * transaction_db) {
	
	delete [] user_db;

	for (int i = 0; i < num_budgets; i++) {

		delete [] budget_db[i].t;
		
	}

	delete [] budget_db;
	delete [] transaction_db;
}

/****************
 * Name: commandline_check
 * Type: void
 * Description: Makes sure that there are the correct amount of arguments, if it is not a file, it prints out an error statement
 * Input: argc, argv[]
 * Output: checks file
*****************/
void commandline_check(int argc, char *argv[]){

	if (argc != 3){
		cout << "Exiting, invalid number of files" << endl; 
		exit(0); 
	}
	else{
		for (int i = 1; i < 3; i++) {
			ifstream file; 
			file.open(argv[i], ifstream:: in); 
			if(!(file.is_open())){
				cout << "Exiting, not a file" << endl; 
				exit(0); 	
			}
			file.close(); 	
		}
	}
}

/*****************
 * Name: check_num
 * Type: int 
 * Description: Checks input to make sure that it is an integer
 * Input: num
 *  Output: 1 if the input is an integer, 0 if the input is not an integer
******************/
int check_num(string num) {
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

/*****************
 * Name: log_in 
 * Type: void 
 * Description: Log in system for the program, asks the user for their username and password, if it is not correct then it prints an error statement 
 * Input: user_db, num_users
 * Output: Enters the budgetbuddy program or prints out an error statement
****************/    
int log_in(user * user_db, int num_users, transaction * transaction_db, int num_transactions) {


	string input; 
	cout << "Enter your ID: ";
	getline(cin, input); 
	 
	while (check_num(input)){
		cout << "Invalid ID, integers only!"; 
		getline(cin, input);
	}
	
	int id = atoi(input.c_str());

	string password; 
	cout << "Enter your password: ";
	getline(cin,password);

	if(check_password(id, password, user_db, num_users)){
		return 1; 
	}
	else{
		return 0;
	}

}

/*****************
 * Name: check_password 
 * Type: bool 
 * Description: checks the password of the user, if they got it correct or not 
 * Input: id2, password2, user_db, num_users
 * Output: return true or false
****************/
bool check_password(int id2, string password2, user* user_db, int num_users) {

	
	for (int i = 0; i < num_users; i++){

		if ((user_db[i].id == id2) && (strcmp(user_db[i].password.c_str(), password2.c_str()) == 0)) {	
			return true; 
		}
	}
	return false;
}

/*****************
 * Name: menu
 * Type: void
 * Description: actual set up of the program, asks the user how they want their sorted transaction information displayed, asks them to enter a 1-4
 * Input: input
 * Output: error statement or enters another function
******************/
int menu(transaction * transaction_db, int num_transactions) {
	
	string input;
	cout << "How do you want the sorted transaction information displayed? " << endl; 
	cout << "(1) Sort transactions by category" << endl; 
	cout << "(2) Sort transactions by date" << endl;
	cout << "(3) Sort transactions by dollar amount" << endl;
	cout << "(4) Quit the program" << endl; 
	cout << "Selection: ";
	getline(cin,input);

	while(check_num(input)) {
		cout << "Not an integer, enter a 1,2,3 or 4: ";
		getline(cin, input); 
	}
	
	int newinput = atoi(input.c_str()); 

	if (newinput < 0 && newinput > 4) {
		cout << "Not an option, enter a 1, 2, 3, or 4: ";	
		getline(cin, input); 
		newinput = atoi(input.c_str());
	}

	switch(newinput){
		case 1: category_sort(transaction_db, num_transactions); break; 
		case 2: date_sort(transaction_db, num_transactions); break;
		case 3: dollar_sort(transaction_db, num_transactions); break;
		case 4: return 0; break;
	}

	
	printinginformation(transaction_db, num_transactions); 
	return 1; 
	

}

/****************
 * Name: printinginformation 
 * Type: void
 * Description: Asks them if they would like the information printed to the screen or written to a file
 * Input: transaction_db, num_transactions 
 * Output: option 
***************/
void printinginformation(transaction * transaction_db, int num_transactions) {

	string option;
	cout << "Would you like your information printed to the screen (Press 1) OR written to a file (Press 2)?" << endl;
	cout << "Selection: ";
	getline(cin, option); 

	while(check_num(option)) {
		cout << "Not a number, enter 1 or 2: ";
		getline(cin, option); 
	} 

	int newoption = atoi(option.c_str()); 

	if (newoption < 0 && newoption > 4) {
		cout << "Not an option, enter a 1 or 2: ";	
		getline(cin,option); 
		newoption = atoi(option.c_str()); 
	}
	
	switch(newoption) {
		case 1: printtransactions(transaction_db, num_transactions);break;
		case 2: writetofile(transaction_db, num_transactions);break;
	}	
}


// asks the user for a file name
void getfilename(string &filename) {

	cout << "What do you want your filename to be?" << endl; 
	getline(cin,filename); 

}


/*****************
 * Name: writetofile
 * Type: void 
 * Description: if the user chooses to write a file, this creates a file and stores it in their directory
 * Input: transaction_db, num_transactions
 * Output: creates a file 
****************/
void writetofile(transaction * transaction_db, int num_transactions) {

	string filename; 
	getfilename(filename);
	ofstream file; 
	file.open(filename.c_str());

	for (int i = 0; i < num_transactions; i++) {
	file << " " << transaction_db[i].date << " " << transaction_db[i].amount << " " << transaction_db[i].description << " " << transaction_db[i].category << endl;
	}

	file.close(); 

}

/************
 * Name: dollar_sort
 * Type: void 
 * Description: sorts through all the data by dollar amount 
 * Input: transaction_db, num_transactions
 * Output: sorted amount
************/
void dollar_sort(transaction * transaction_db, int num_transactions) {


	for (int i = 0; i < num_transactions -1; i++) {	
		bool swapped = false; 

		for (int j = 0; j < num_transactions-i-1 ; j++) {
			if (transaction_db[j].amount > transaction_db[j+1].amount) {
				std::swap(transaction_db[j], transaction_db[j+1]);
					swapped = true;
			}
		}
		
		if (!swapped) {
			break; 
		}	
	}	
}

/***********
 * Name: date_sort
 * Type: void 
 * Description: sorts through the data by date
 * Input: transaction_db, num_transactions
 * Output: sorted dates 
************/
void date_sort(transaction * transaction_db, int num_transactions) {

	for (int i = 0; i < num_transactions-1 ; i++) {
		bool swapped = false; 
		
		for (int j = 0; j < num_transactions-i-1 ; j++) {
				if (strcmp(transaction_db[j].date.c_str(), transaction_db[j+1].date.c_str()) > 0){
				std::swap(transaction_db[j], transaction_db[j+1]);
				swapped = true;

			}
		}

	if (!swapped) {
		break; 
	}
	}
}

/*****************
 * Name:category_sort
 * Type: void
 * Description: sorts through the data by categories 
 * Input: transaction_db, num_transactions
 * Output: sorted categories
**************/
void category_sort(transaction * transaction_db, int num_transactions) {

	for (int i = 0; i < num_transactions -1; i++) {
		bool swapped = false; 
		for (int j = 0; j < num_transactions-i-1; j++) {
			if(strcmp(transaction_db[j].category.c_str(), transaction_db[j+1].category.c_str()) > 0) {
				std:: swap(transaction_db[j], transaction_db[j+1]);
				swapped = true; 

			}
		}	

	if (!swapped) {
		break;
	}
}

}

/**************
 * Name: printtransactions
 * Type: void
 * Description: prints out the sorted data to the screen 
 * Input: transaction_db, num_transactions 
 * Output: sorted data
**************/
void printtransactions(transaction * transaction_db, int num_transactions) {

	for (int i = 0; i < num_transactions; i++) {
		cout << " " << i+1 << " " << transaction_db[i].date << " " << transaction_db[i].amount << " " << transaction_db[i].description << " " << transaction_db[i].category << endl;
	}


}


