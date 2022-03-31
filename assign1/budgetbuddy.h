#include <iostream> 
#include <string> 
#include <cstdlib> 
#include <fstream> 
#include <cstring>
using namespace std; 
/***********************
 * Program: budgetbuddy.h
 * Author: Hannah Maung 
 * Date: 01/19/2020
 * Description: includes all the structs used for this program and the headers
***********************/


struct user {

   string name;
   int id;
   string password;

};


struct budget {

   int id;
   float balance;
   int num_transactions;
   struct transaction *t;

};


struct transaction {

   float amount;
   string date;
   string category;
   string description;

};

int check_num(string num);
budget* create_budgets(int);
void get_budget_data(budget*, int, ifstream &);
transaction* create_alltransaction(budget *, int,int);
transaction* create_transactions(int);
void get_transaction_data(transaction*, int, ifstream &);
void commandline_check(int argc, char *argv[]);
user* create_user_db(int num_users);
void get_users_data(int & num_users, ifstream & users_data, char * argv[]);  
void fill_user_db(user* user_db, int num_users, ifstream & data);  
budget* create_budgets(int num_budget); 
void get_budget_data( int &num_budget, ifstream & budget_data, char *argv[]);
void fill_budget_db(budget* budget_db, int num_budget, ifstream & data); 
void delete_info(user* user_db, budget* budget_db, int num_budgets, int num_users, transaction * transaction_db);
int log_in(user * user_db, int num_users, transaction * transaction_db, int num_transactions);
void date_sort(transaction * transaction_db, int num_transactions);
void category_sort(transaction * transaction_db, int num_transactions); 
void getfilename(string &filename);
void writetofile(transaction * transaction_db, int num_transactions);
void printinginformation(transaction * transaction_db, int num_transactions);
void getfilename(string &filename);
bool check_password(int id2, string password2, user* user_db, int num_users);
int menu(transaction * transaction_db, int num_transactions);
void dollar_sort(transaction * transaction_db, int num_transactions);
int transactions_budgets(budget * budget_db, int num_budget); 
void printtransactions(transaction * transaction_db, int num_transactions);
