// 1. how would you define the add function to take two integer parameters and return their sum
// 2. define a global variable opearation count that counts how many operations have been performed
// 3. modify each arithmatic function to increment this global variable each time it is called.

// Asssignment/////////////////////

//implement the complete calculator program as described ensuring to demonstarate the use of local and global variables


#include <stdio.h>
#include <stdlib.h>

// Task -- 1
// int add(int a,int b){
//     return a+b;
// }

// Task -- 2
int oprCount = 0;

// Task -- 3
int add(int a,int b){
    oprCount++;
    return a+b;
}
int sub(int a, int b){
    oprCount++;
    return a-b;
}

int mul(int a, int b){
    oprCount++;
    return a*b;
}

float divi(float a, float b){
    oprCount++;
    return a/b;
}

// Assignment


int main(){
    printf("\nName: Ankur\n");
    printf("URN: 2302473\n");
    int x, y, choice;
    while (1){
        printf("\n*****--CALC--*****\n");  
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Division\n");
        printf("5. Exit\n\n");
        printf("Choose an operation: ");
        scanf("%d", &choice);
        while (getchar() != '\n');
        
        if (choice >= 1 && choice <= 4)
        {
            printf("Enter the two numbers: ");
            scanf("%d %d", &x, &y);
        }
        

        switch(choice) {
            case 1:
                printf("Sum of %d and %d = %d\n", x, y, add(x, y));
                break;
            case 2:
                printf("Subtraction of %d and %d = %d\n", x, y, sub(x, y));
                break;
            case 3:
                printf("Multiplication of %d and %d = %d\n", x, y, mul(x, y));
                break;
            case 4:
                if(y == 0) {
                    printf("Division by ZERO is undefined!\n");
                    break;
                }
                printf("Division of %d and %d = %.2f\n", x, y, divi(x, y));
                break;
            case 5:
                printf("%d calculations performed.\n", oprCount);
                exit(0);
                break;
            default :
                printf("Invalid Input!\n");
        }
    }

    return 0;
}