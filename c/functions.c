#include <stdio.h>

void withArgNoRet(int a) {
  printf("\nThis is a function with-arg-no-return\n");
  printf("%d X 5 = %d", a, a * 5);
}

int noArgWithRet() {
  printf("\nThis is a function no-arg-with-return (sum is returned)\n");
  int num1 = 5, num2 = 2, sum;
  sum = num1 + num2;
  return sum;
}

int withArgWithRet(int a, int b) {
  printf("\nThis is a function with-arg-with-return ");
  int sum = a+b;
  return sum;
}

void noArgNoRet(){
  printf("\nThis is a function no-arg-no-return\n");
  int a= 10;
  int b = 20;
  printf("The sumof two numbers is %d", a+b);
  
}

int main() {
  printf("1. With Argument no Return\n");
  printf("2. No Argument with Return\n");
  printf("3. with Argument with Return\n");
  printf("4. no Argument no Return\n\n");
  printf("Enter your choice: ");
  int a,b, arg, choice;
  scanf("%d", &choice);

  switch (choice) {
  case 1:
    printf("\nEnter the argument: ");
    scanf("%d", &arg);
    withArgNoRet(arg);
    break;
  case 2:
    printf("%d", noArgWithRet());
    break;
  case 3:
    printf("Enter two nums: ");
    scanf("%d %d", &a, &b);
    printf("%d\n", withArgWithRet(a, b));
    break;
  case 4:
    noArgNoRet();
    break;
  default: printf("Please Enter a Valid Number!");

  }
  return 0;
}