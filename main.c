#include<stdio.h>
#include "myBank.h"

int main(){
char charOperation = 'A';
double sumDepose = 0;




 while(scanf(" %c", &charOperation) != EOF){		//all the transaction option
	int accountNumber;
	double sumWithDraw;
	int interest;
	double sum;
	double ans;


	printf("\nPlease choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");

	


	if (charOperation == 'O')		//open account and depose money
	{
		printf("Please enter amount for deposit: ");

		if (scanf("%lf", &sumDepose) == 1)		//check if is valid input	
		{
			if (sumDepose >= 0)
			{
				int ans = isOpenAcount(sumDepose);
				if (ans != -1)					//can open account
				{
					printf("New account number is: %d\n", ans);
				}
				else {							//no empty index in the array
					printf("This account is closed\n");
				}
			}
			else {
				printf("Invalid Amount\n");
			}
		}

		else {
			printf("Failed to read the amount\n");

		}
	}


	else if (charOperation == 'B') {			//return the sum of the money in the account

		printf("Please enter account number: ");

		if (scanf("%d", &accountNumber) == 1) {

			if (accountNumber <951 && accountNumber >= 901) {		//check if it's valid account number
				ans = BalanceInquiry(accountNumber);

				if (isExist(accountNumber) != 0) {
					printf("The balance of account number %d is: %.2lf\n", accountNumber, ans);
				}
				else {
					printf("This account is closed\n");		
				}
			}
			else {
				printf("Invalid account number\n");
			}
		}
		else {
			printf("Failed to read the account number\n");			//didn't succeed to read the input
		}

	}
		//depose money in exist account

	else if (charOperation == 'D') {

		printf("Please enter account number: ");

		if (scanf("%d", &accountNumber) == 1) {

			if (accountNumber < 951 && accountNumber >= 901) {	//check if it's valid account number

				if (isExist(accountNumber) != 0) {
					printf("Please enter the amount to deposit: ");

					if (scanf("%lf", &sumDepose) == 1) {

						if (sumDepose >= 0) {
							sum = sumDeposit(accountNumber, sumDeposit);
							printf("The new balance is: %.2lf\n", sum);
						}
						else {
							printf("Cannot deposit a negative amount\n");		//can't enter negative number
						}
					}
					else {
						printf("Failed to read the amount\n");
					}
				}
				else {
					printf("This account is closed\n");				//can't fount th eeaccount
				}
			}
			else {
				printf("Invalid account number\n");			
			}

		}
		else{
			printf("Failed to read the account number\n");
		}
	}


	//withdraw money

		else if (charOperation == 'W') {

			printf("Please enter account number: ");

			if (scanf("%d", &accountNumber) == 1) {

				if (accountNumber < 951 && accountNumber >= 901) {			//check if the it's valid account

					if (isExist(accountNumber) != 0) {

						printf("Please enter the amount to withdraw : ");

						if (scanf("%lf", &sumWithDraw) == 1)
						{
							sumWithDraw = Withdrawal(accountNumber, sumWithDraw);

							if (sumWithDraw != -1)
							{
								printf("The new balance is: %.2lf\n", sumWithDraw);
							}
							else {
								printf("Cannot withdraw more than the balance\n");				//try to withdraw more than have him money
							}
						}
						else {
							printf("Failed to read the amount\n");
						}
					}
					else {
						printf("This account is closed\n");			//the account not exist
					}
				}
				else {
					printf("Invalid account number\n");
				}
			}
			else {
				printf("Failed to read the account number\n");
			}
		}

	else if (charOperation == 'C') {					//close account operation
		printf("Please enter account number: ");

		if (scanf("%d", &accountNumber) == 1) {

			if (accountNumber < 951 && accountNumber >= 901) {			//check if the it's valid account

				if (isExist(accountNumber)) {
					CloseAccount(accountNumber);
					printf("Closed account number %d\n", accountNumber);
				}
				else
				{
					printf("This account is already closed\n");		//the account not exist
				}
			}
			else {
				printf("Invalid account number\n");
			}
		}
		 else{
				 printf("Failed to read the account number\n");		//didn't succed to read the input
		 }
	}

	else if (charOperation == 'I') 				//insert interest
	{
		printf("Please enter interest rate: ");
		if (scanf("%d", &interest) == 1) {
			
			if (interest > 0) {			//only if interest bigger than zero
				Interest(interest);
			}
			else {
				printf("Invalid interest rate\n");
			}
		}
		else {
			printf("Failed to read the interest rate\n");		//didn't succeed to get the input
		}
	}

	else if (charOperation == 'P') 				//print all the acounts
	{
		Print();
	}


	else if (charOperation == 'E')		//exit from the loop while
	{
		Exit();
		break;
	}

	else {
		printf("Invalid transaction type\n");			//if insert invalid character
	}
	
	 
}
return 0;
}	



