

Double arr [51][2]= {{0},{0}};		//50 rows the number of the accounts ant two columns first for the number of the account and the seconf for the sum of th emonet in the account

Double isOpenAcoount(Double sumDeposit){		//open an account and insert money

int numberOfAcoount = 0; 		
	for(int i= 1 ; i <= 50 ; i++){
		if(arr[i][0] == 0)
		{		
		numbeOfAccount = 900 + i;		
		arr[i][0] = 900+i;
		arr[i][1] = sumDeposit;		//insert the sum of the money to the ne account	
		}
	}
	if(numberOfAcoount ==0){		//mean that no place for another account
		return -1;
	}
	else return numbeOfAccount;
}	

int isExist(int accountNumber){
	
if(arr[(accountNumber -901)][0]==0)
	return 0;								//the account is colsed
	
return 1;							//this account isn't empty 
}


int BalanceInquiry(int accountNumber){
	
if((accountNumber - 900) < 50 && (accountNumber - 900) > 0)
	{
		return arr[accountNumber - 900][1];
	}
else return -1;

}



int sumDeposit(int accountNumber , Double sumToAdd){
	
		arr[accountNumber - 901][1] += sumToAdd;
		return arr[accountNumber - 901][1];
	
}


int Withdrawal(int accountNumber , double sumToWithdrawal){
	
		if(arr[accountNumber - 901][1] > sumToWithdrawal)
		{			
			arr[accountNumber - 901][1]	-= sumToWithdrawal;
				return arr[accountNumber - 900][1];
		}
	
else return -1;
	
}


int CloseAccount(int accountNumber){
	
		arr[accountNumber - 901][0]= -1;
		arr[accountNumber - 901][1]= 0;;
	return 0;
}


int Interest(int accountNumber, Double interest){
	
	for(int i =0 ; i < 50 ; i++)
	{	
		if(arr[i][0] != 0 )
		{
			arr[i][1] += interest*arr[i][0];
		}
	
	}
return 0;	
}


int Print(){
	for(int i =0 ; i < 50 ; i++)
	{	
		if(arr[i][0] != 0 )
		{
			printf("The balance of account number%d is: %lf" , arr[i][0],arr[i][1]);
		}
	}
return 0;	
}



public int Exit(){
	for(int i =0 ; i < 50 ; i++)
	{	
		arr[i][0]=-1;					//remove the account number
		arr[i][1]=0;					//remove the sum of the money in the accounts
	}
return 0;	
}













