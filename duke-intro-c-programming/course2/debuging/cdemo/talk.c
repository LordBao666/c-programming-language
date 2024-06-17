#include <stdio.h>
#include "talk.h"


void talk(Person * p ){
  printf("%d,%s\n",p->age,p->name);
  printf("I'm talking!!!\n");
}
