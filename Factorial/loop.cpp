#include <iostream>

int factorial(int n) {    
  if(n<0)    
    return(-1); /*Wrong value*/      
  if(n==0)    
    return(1);  /*Terminating condition*/    
  else    
  {    
  return(n*factorial(n-1));        
  }    
}  

int main() {
  // Grab Input
  printf("Enter a number: ");
  int num;
  scanf("%d", &num);

  
  // For loop
  for (int i = num; i != 0; i--) {
     printf("The factorial of %d is %d\n", i, factorial(i));
     }
  }
