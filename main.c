#include<stdio.h>
#include "myBank.h"

int main(){
char charOperation;

while(scanf("\nPlease choose a transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposit\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n% c" , &charOperation) != EOF){		//all the transaction option
	
	switch(charOperation)
	{	
	case 'O':			//open account and depose money
		double sumDeposit;
		if(scanf("Please enter amount for deposit%.2lf" , &sumDeposit)==1 && sumDeposit >=0)		//check if is valid input	
		{		
			int ans = isOpenAcoount(sumDeposit);	
			if(ans != -1)					//can open account
			{
			printf("New account number is: %d" , ans); 	
			}
			else{							//no empty index in the array
			printf("This account is closed");	
			}		
		}
		else{
		printf("Failed to read the amount");
			
		}
			break;
	case 'B':			//return the sum of the money in the account
		int accountNumber;
		
		if(scanf("Please enter account number%d" , &accountNumber)==1 && accountNumber<=951 && accountNumber>=901 && isExist(accountNumber)){		//check if it's valid account number
			Double ans = BalanceInquiry(accountNumber);
			printf("The balance of account number: ans %d is: %.2lf" ,accountNumber , ans);
		}
		else{			
			printf("Failed to read the account number");	
		}
			break;
	case 'D':			//depose money in exist account
		 int accountNumber;
		 double sumDeposit;
		if(scanf("Please enter account number%d" , &accountNumber) == 1 && accountNumber<=951 && accountNumber>=901){	//check if it's valid account number
			if(!isExist(accountNumber)){
				if(scanf("Please enter amount for deposit%.2lf" ,&sumDeposit)==1){	
			
					if(sumDeposit >= 0){
							Double sum = Deposit(accountNumber ,sumDeposit);
							printf("The new balance is: %d %.2lf" ,accountNumber , sum);
						}
				
						else{
						printf("Cannot deposit a negative amount");
							break;
						}
				}
				else{
					printf("Failed to read the amount");
				}
			}
			else{
					prinft("This account is closed");
			}
		}
		else{
			printf("Failed to read the account number");			
		}
			break;
	case 'W':
		int accountNumber;
		double sumWithDraw;
		if(scanf("Please enter account number%d" , &accountNumber)==1 && accountNumber<=951 && accountNumber>=901){			
			
			if(!isExist(accountNumber)){
				if(scanf("Please enter the amount to withdraw:%.2lf" ,&sumWithDraw)==1 && sumWithDraw > 0 )
				{
					if(Withdrawal(accountNumber , sumWithDraw) != -1){			
						prinft("The new balance is: %.2lf" , sumWithDraw);
					}
					else{
						prinft("Cannot withdraw more than the balance");			
					}
				}
				else{
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
		break;	
	case 'C':
		int accountNumber;
		if(scanf("Please enter account number%d" , &accountNumber)==1 && accountNumber<=951 && accountNumber>=901){
			int state = isExist(accountNumber);		
			if(state==1){
					CloseAccount(accountNumber);																										
					prinft("Closed account number %d" ,accountNumber);
			}
			else if(state==0){
					printf("This account is already closed");
			}	

		}
		else{
				printf("Failed to read the account number");
		}
		break;
	case 'I':
		double interest;
		if(scanf("Please enter interest rate:%.2lf" , &interest)==1){
			
			
			Interest(interest):
		}
		else{
		prinft("Failed to read the interest rate");	
		}
		break;
	case 'P':
		Print();
		break;
	case 'E':	
		Exit();
		break;
	default: 
		printf("Invalid transaction type");			//if insert invalid character
	
	}
}
return 0;
}	



