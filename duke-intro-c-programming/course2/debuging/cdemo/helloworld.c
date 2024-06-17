#include <stdio.h>
#include <stdlib.h>
#include "talk.h"

int main(){
  Person p;
  p.age=13;
  p.name="jack";
  talk(&p);
  printf("Hello World\n");
  return 0;
}
