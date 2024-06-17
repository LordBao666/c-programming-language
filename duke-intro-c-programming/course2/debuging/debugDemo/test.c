#include <stdio.h>
#include <stdlib.h>

void func1(int * p);
void func2(int * p);
void func3(int * p);

int main(){
  int a=1;
  int arr[]={1,2,3,4};
  printf("main is calling \n");
  func1(&a);

  //set a conditional break point here
  for(int i=0;i<20;i++){
    printf("%d ",i);
  }
  printf("\n");
  printf("a = %d\n",a);
  printf("main is over\n");
  
  return EXIT_SUCCESS;
}


void func1(int * p){
  *p=*p+1;
  printf("func1 is calling\n");
  func2(p);
}

void func2(int * p){
  *p = *p+1;
  printf("func2 is calling\n");
  func3(p);
}

void func3(int * p){
  *p = *p+1;
  printf("func3 is calling\n");
 
}

