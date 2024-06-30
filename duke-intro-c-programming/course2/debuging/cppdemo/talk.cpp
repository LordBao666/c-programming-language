#include <iostream>
#include <string>
#include "talk.h"

using namespace std;
Person::Person():age(0),name(""){
}
Person::Person(int age,string name):age(age),name(name){
}

void Person::talk(){
  cout<<this->age<<","<<this->name<<endl;
  cout<<"I'm talking!!!"<<endl;
}
