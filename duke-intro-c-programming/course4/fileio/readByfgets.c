#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LINE_SIZE 25
int main(int argc ,char ** argv){
  if(argc!=2){return EXIT_FAILURE;}

  FILE * file = fopen(argv[1],"r");
  if(file == NULL){return EXIT_FAILURE;}

  char arr[LINE_SIZE];
  while((fgets(arr,LINE_SIZE,file)!=NULL)){
      if(strchr(arr,'\n')==NULL){
	printf("The line is too long");
	return EXIT_FAILURE;
      }
      printf("%s",arr);
  }
  
    return EXIT_SUCCESS;
}
