#include<stdio.h>

long long int factorail(long long int n){
  if (n == 0){
    return 1;
  }

  return n*factorail(n-1);
}

long long int fibonacci(long long int n){
  if (n == 1 || n == 2 ){
    return 1;
  }

  return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
  printf("\nName: Ankur\n");
  printf("URN: 2302473\n\n");

  long long int choice, n;
  printf("1. Factorial\n");
  printf("2. Fibonacci\n\n");
  printf("Choose an option: ");
  scanf("%lld", &choice);

  while(getchar() != '\n');

  printf("Enter any positive number: ");
  scanf("%lld", &n);
  while(getchar() != '\n');


  if (n < 0 ) {
    printf("Negative number is not allowed.\n");
    return 0;
  }

  switch (choice)
  {
  case 1:
    printf("Factorial of %lld = %lld\n", n, factorail(n));
    break;
  case 2:
    if (n == 0) {
      printf("0th Fibonacci series term = 0\n");
      break;
    }
    printf("%lldth Fibonacci series term = %lld\n", n, fibonacci(n));
    break;
  
  default:
    printf("Invalid Input!\n");
    break;
  }

  return 0;

}