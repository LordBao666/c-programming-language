
#ifndef TALK_H
#define TALK_H
#include<string>
using namespace std;


class Person{
 private:
  int age;
  string  name;

 public:
  Person();
  Person(int age,string name);
 public:
  void talk();  
} ;




#endif
