#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int balance = 10000;
int pin = 1234;
int transactionHistory[100] = {0};
int i = 0;
bool authUser(){
    int inputPin;

    printf("Enter your pin: ");
    scanf("%d", &inputPin);

    for (int i = 0; i < 2; i++){
      if (inputPin == pin){
        return true;
      }

      printf("You have entered wrong PIN, %d chances left.\n\n", (2-i));
      printf("Enter your pin: ");
      scanf("%d", &inputPin);
      if (i == 1 && inputPin != pin){
        return false;
      }
    }
    return true;

};

void withdraw(int amt){
  balance -= amt;
  transactionHistory[i++] = amt*(-1);
};

void deposit(int amt){
  balance += amt;
  transactionHistory[i++] = amt;
};

void getTransactionHistory(){
  printf("Transaction History: ");
  for (int j = 0; j <= i-1; j++){
    printf("%d  ", transactionHistory[j]);
  }
  printf("\n");
};

int main(){
  if (!authUser()) {
  printf("You have utilised maximum attempts. Your access is denied.\n");
  return 0;
  }

  while(true){
  printf("\n*****--Welcome to ATM--*****\n");

  printf("1. Balance Enquiry\n");
  printf("2. Cash Withdrawal\n");
  printf("3. Cash Deposit\n");
  printf("4. Funds Transfer\n");
  printf("5. Change Pin\n");
  printf("6. View transaction History\n");
  printf("7. Exit\n\n");
  

  int choice;
  int amt;
  printf("Choose an option: ");
  scanf("%d", &choice);

  switch (choice){
  case 1:
    printf("Your current Balance = %d\n", balance);
    break;
  case 2:
    
    printf("Enter the amount to withdraw: ");
    scanf("%d", &amt);
    if(amt <= balance){
      if(!authUser()){
        printf("YOU HAVE ENTERED WRONG PIN. Your session has been termiated.");
        exit(1);
      }
      withdraw(amt);
      printf("You have successfully withdrew Rs. %d\n", amt);
      printf("Your Updated Balance is Rs. %d\n", balance);
      break;
    }
    printf("Withdrawl amount exceeds your available balance. Withdrawal not possible.\n");
    break;
  

  case 3:
    printf("Enter the amount you want to deposit: ");
    scanf("%d", &amt);
    deposit(amt);
    printf("You have successfully Deposited Rs. %d.\n", amt);
    printf("Your Updated Balance is Rs. %d\n", balance);
    break;
  
  case 5:
    printf("Enter your new Pin: ");
    int newPin;
    scanf("%d", &newPin);
    pin = newPin;
    printf("You have successfully changed your pin.\n");
    break;
  case 6:
    getTransactionHistory();
    break;
  case 7:
    printf("Thank you for banking with us :)\n");
    return 0;
  default:
    printf("You have chosen and invalid option.");
    break;
  }

  }
  return 0;
}