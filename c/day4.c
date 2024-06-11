#include <stdio.h>


void printArr(int *arr, int n){
  for (int i = 0; i < n; i++){
    printf("%d ", *(arr++));
  }
}

int rows , cols ;
void print2D(int arr[][cols], int m, int n){
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}



int main(){
  int arr[5] = {1, 2, 3, 4, 5};
  printArr(arr, 5);


  printf("\nEnter the number of rows and columns: ");
  scanf("%d %d", &rows, &cols);

  int arr2D[rows][cols];

  printf("Enter the values for 2d array\n");
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){
      scanf("%d", &arr2D[i][j]);
    }
  } 
  printf("\n");

  printf("2D array of the enterd values: \n");
  print2D(arr2D, rows, cols);

  printf("\n");

  // printArr(&arr2D[0][0], rows*cols);


  // char grades[30];
  // int gradesIn5Sub[30][5];

  // for (int i = 0; i < 30; i++){
  //   scanf("%c", &grades[i]);
  // }






  return 0;
}

