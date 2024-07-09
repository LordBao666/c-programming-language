#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(2 <=c.value && c.value <= VALUE_ACE);
  assert(SPADES <= c.suit && c.suit <= CLUBS);
}




const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
    case STRAIGHT_FLUSH:return "STRAIGHT_FLUSH";
    case FOUR_OF_A_KIND:return "FOUR_OF_A_KIND";
    case FULL_HOUSE:return "FULL_HOUSE";
    case FLUSH:return "FLUSH";
    case STRAIGHT:return "STRAIGHT";
    case THREE_OF_A_KIND:return "THREE_OF_A_KIND";
    case TWO_PAIR:return "TWO_PAIR";
    case PAIR:return "PAIR";
    case NOTHING:return "NOTHING";
    default: return "";
  }    
}

char value_letter(card_t c) {
  if(2<= c.value && c.value <= 9){
    return '0'+c.value;
  }else{ //10, J,Q,K,A
    switch(c.value){
    case 10:return '0';
    case 11:return 'J';  
    case 12:return 'Q';  
    case 13:return 'K';
    case 14:return 'A';
    default:return ' ';
    }
  }  
 
}


char suit_letter(card_t c) {
  switch(c.suit){
  case SPADES:return 's';
  case HEARTS:return 'h';
  case DIAMONDS:return 'd';
  case CLUBS:return 'c';
  default: return ' ';  
  }  
}

void print_card(card_t c) {
  printf("%c%c",value_letter(c),suit_letter(c));
}

unsigned  letter_to_value(char value_let){
  if(value_let=='0'){
    return 10;
  }
  if('2'<=value_let && value_let <='9'){
    return value_let - '0';
  }
  if(value_let=='J'){
    return VALUE_JACK;
  }  
  if(value_let=='Q'){
    return VALUE_QUEEN;
  }  
  if(value_let=='K'){
    return VALUE_KING;
  }  
  if(value_let=='A'){
    return VALUE_ACE;
  }  
  return 100;
}

suit_t letter_to_suit(char suit_let){
  if(suit_let=='s'){
    return SPADES;
  }
  if(suit_let=='h'){
    return HEARTS;
  }  
  if(suit_let=='d'){
    return DIAMONDS;
  }
  if(suit_let=='c'){
    return CLUBS;
  }
  return 100;
}


 
card_t card_from_letters(char value_let, char suit_let) {
  unsigned value = letter_to_value(value_let);
  suit_t suit = letter_to_suit(suit_let);
  card_t temp;
  temp.value = value;
  temp.suit = suit;
  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  suit_t suit;
  unsigned d = c / 13;
  if(d==0){
    suit = SPADES;
  }else if(d==1){
    suit=HEARTS;
  }else if(d==2){
    suit=DIAMONDS;
  }else{
    suit=CLUBS;
  }
  unsigned value = c % 13 + 2; 
  
  card_t temp;
  temp.suit = suit;
  temp.value = value;
  return temp;
}
