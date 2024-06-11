#include<stdio.h>

int sumUptoN(int n) {
  if (n == 1){
    return 1;
  }


  return n + sumUptoN(n-1);
}

int countDig(int n, int count) {
  if (n > 0){
    n /= 10;
    count++;
    countDig(n, count);
  }
  else if (n == 0) return count;

}
int main(){
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  printf("Sum upto %d = %d\n", n, sumUptoN(n));
  printf("No. of digits in %d = %d\n", n, countDig(n, 0));

  return 0;
}