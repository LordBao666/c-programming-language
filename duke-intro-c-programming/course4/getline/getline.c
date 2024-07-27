#include<stdlib.h>
#include<stdio.h>

int main(int argc,char ** argv){
  if(argc!=2){return EXIT_FAILURE;};
  FILE * file = fopen(argv[1],"r");
  if(file==NULL){return EXIT_FAILURE;};

  char * buf = NULL;
  size_t sz =0;
  ssize_t len =0;
  while((len=getline(&buf,&sz,file))>=0){
    printf("%s",buf);
  }
  free(buf);
  return EXIT_SUCCESS;
  
}  
