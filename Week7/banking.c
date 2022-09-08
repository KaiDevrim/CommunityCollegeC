/*
 * Create constant variable for maximum
 * number of accounts to be created and set it to 3;
 * Then create a bank account structure
 * with the following parameters,
 * an int called number, a double for balance,
 * and a double for interest_rate. And call the
 * structure bank_account.
 * 
 * Then make a function called update_account that
 * takes in a bank_account pointer then it
 * updates the account balance to the account balance
 * plus account balance times account interest rate.
 * 
 * Then in the main function create an array of bank
 * accounts set to the maximum int defined. Then fill
 * it with the values given. Then call the
 * update_account function and pass in the account
 * variable.
 * 
 * Then print out the header and the values of
 * the bank account information.
 * K D McCormick, 2022-07-11
*/

#include <stdio.h>
const int MAX_ACCOUNTS = 3;
typedef struct bank_account {
	int number;
	double balance;
	double interest_rate;
} bank_account;

void update_account(bank_account *account) {
	account->balance = account->balance + (account->balance) * (account->interest_rate);
}

int main(void) {
	bank_account account[MAX_ACCOUNTS] = {
		{10907, 2000.00, 0.015},
		{47112, 5372.25, 0.024},
		{87435, 1800.00, 0.03}
	};
	
	update_account(account);
	
	printf("Acct #\tBalance\n");
	printf("------\t-------\n");
	
	for (int i = 0; i < MAX_ACCOUNTS; i++) {
		printf("%i\t", account[i].number);
		printf("$%.2f\n", account[i].balance);
	}
	return 0;
}
