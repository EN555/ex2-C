#include<stdio.h>
#include "myBank.h"

int main(){
char charOperation = 'A';
double sumDepose = 0;




 while(scanf(" %c", &charOperation) != EOF){		//all the transaction option
	int accountNumber;
	double sumWithDraw;
	double interest;
	double sum;
	double ans;


	printf("\nPlease choose a transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposit\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");

	


	if (charOperation == 'O')		//open account and depose money
	{
		printf("Please enter amount for deposit: ");

		if (scanf("%lf", &sumDepose) == 1 && sumDepose >= 0)		//check if is valid input	
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
			printf("Failed to read the amount\n");

		}
	}



	else if (charOperation == 'B') {			//return the sum of the money in the account

		printf("Please enter account number: ");

		if (scanf("%d", &accountNumber) == 1 && accountNumber <= 951 && accountNumber >= 901) {		//check if it's valid account number
			ans = BalanceInquiry(accountNumber);

			if (isExist(accountNumber) != 0) {
				printf("The balance of account number %d is: %.2lf\n", accountNumber, ans);
			}
			else {
				printf("This account is closed\n");
			}
		}
		else {
			printf("Failed to read the account number\n");
		}
	}
			 

		//depose money in exist account

	else if (charOperation == 'D') {

		printf("Please enter account number: ");
		if (scanf("%d", &accountNumber) == 1 && accountNumber <= 951 && accountNumber >= 901) {	//check if it's valid account number
			
			if (isExist(accountNumber != 0)) {
				printf("Please enter amount for deposit");
				
				if (scanf("%lf", &sumDepose) == 1) {

					if (sumDepose >= 0) {
						sum = sumDeposit(accountNumber, sumDeposit);
						printf("The new balance is: %d %.2lf\n", accountNumber, sum);
					}
					else {
						printf("Cannot deposit a negative amount\n");
						break;
					}
				}
				else {
					printf("Failed to read the amount\n");
				}
			}
			else {
				printf("This account is closed\n");
			}
		}
		else {
			printf("Failed to read the account number\n");
		}
	}


	//withdraw money

	else if (charOperation == 'W') {

		printf("Please enter account number: ");

		 if(scanf("%d" , &accountNumber)==1 && accountNumber<=951 && accountNumber>=901){			

			 if (isExist(accountNumber) != 0) {

				 printf("Please enter the amount to withdraw : ");

					 if (scanf("%lf", &sumWithDraw) == 1 && sumWithDraw > 0)
					 {
						 if (Withdrawal(accountNumber, sumWithDraw) != -1)
						 {
							 printf("The new balance is: %.2lf", sumWithDraw);
						 }
						 else {
							 printf("Cannot withdraw more than the balance");
						 }
					 }
					 else {
						 printf("Failed to read the amount");
						 break;
					 }
			 }
			 else{
				 printf("This account is closed");
			 }

		 }
		 else{
			 printf("Failed to read the account number");
		 }
	}


	// case 'C':
		// if(scanf("Please enter account number%d" , &accountNumber)==1 && accountNumber<=951 && accountNumber>=901){
			// int state = isExist(accountNumber);		
			// if(state==1){
					// CloseAccount(accountNumber);																										
					// printf("Closed account number %d" ,accountNumber);
			// }
			// else if(state==0){
					// printf("This account is already closed");
			// }	

		// }
		// else{
				// printf("Failed to read the account number");
		// }
		// break;


	// case 'I':
		// if(scanf("Please enter interest rate:%lf" , &interest)==1){		
			// Interest(interest);
		// }
		// else{
		// printf("Failed to read the interest rate");	
		// }
		// break;

	// case 'P':
		// Print();
		// break;


	// case 'E':	
		// Exit();
		// break;
	else {
		printf("Invalid transaction type\n");			//if insert invalid character
	}
	
	 
}
return 0;
}	



