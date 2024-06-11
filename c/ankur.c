#include <stdio.h>

// W/o args w/o return type

void sum1(){
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d%d",&a, &b );

    printf("Sum of Two numbers is: %d\n\n", a+b);
}

// w/o ars w/ return type

int sum2(){
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    return a+b;
}

// w/ args w/o return type

void sum3(int a,int b){
    printf("sum of two numbers = %d", a+b);
}

// w/ args w/ return type

int sum(int c, int d) {
    int r = c+d;
    return r;
}

int main(){
    printf("Printing sum with W/o args w/o return type function\n");
    sum1();

    printf("Printing sum with W/o args w/ return type function\n");
    printf("Sum of two number is = %d\n",sum2());

    printf("Printing sum with W/ args w/o return type function\n");
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    
    
    return 0;
}

// string fns

// how would you define the add function to take two integer parameters and return their sum
// define a global variable opearation count that counts how many operations have been performed
// modify each arithmatic function to increment this global variable each time it is called.

// Asssignment/////////////////////

//implement the complete calculator program as described ensuring to demonstarate the use of local and global variables
