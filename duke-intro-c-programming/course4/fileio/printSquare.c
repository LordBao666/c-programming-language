#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv){
  if(argc!=4){return EXIT_FAILURE;}
  int begin = atoi(argv[1]);
  int end= atoi(argv[2]);
  FILE * file =fopen(argv[3],"w");
  if(file==NULL){return EXIT_FAILURE;}

  for(;begin<=end;begin++){
    fprintf(file,"%d ",begin*begin);
  }
		
  if(fclose(file)!=0){return EXIT_FAILURE;}
  return EXIT_SUCCESS;
}
