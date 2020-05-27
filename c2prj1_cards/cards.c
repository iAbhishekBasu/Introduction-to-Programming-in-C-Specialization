#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  unsigned val = c.value;
  suit_t suit = c.suit;
  assert(2 <= val && val <= VALUE_ACE && SPADES <= suit && suit <= CLUBS);
}


const char *ranking_to_string(hand_ranking_t r) {
  switch (r) {
  case STRAIGHT_FLUSH:
    return "STRAIGHT_FLUSH";
  case FOUR_OF_A_KIND:
    return "FOUR_OF_A_KIND";
  case FULL_HOUSE:
    return "FULL_HOUSE";
  case FLUSH:
    return "FLUSH";
  case STRAIGHT:
    return "STRAIGHT";
  case THREE_OF_A_KIND:
    return "THREE_OF_A_KIND";
  case TWO_PAIR:
    return "TWO_PAIR";
  case PAIR:
    return "PAIR";
  default:
    return "NOTHING";   // r == NOTHING
  }
}


char value_letter(card_t c) {
  int val = c.value;
  if (val <= 9) {
    return '0' + val;
  } else if (val == 10) {
    return '0';
  } else if (val == VALUE_JACK){
    return 'J';
  } else if (val == VALUE_QUEEN) {
    return 'Q';
  } else if (val == VALUE_KING) {
    return 'K';
  }
  return 'A';   // val == VALUE_ACE
}


char suit_letter(card_t c) {
  int suit = c.suit;
  if (suit == SPADES) {
    return 's';
  } else if (suit == HEARTS) {
    return 'h';
  } else if (suit == DIAMONDS) {
    return 'd';
  }
  return 'c';   // suit == CLUBS
}


void print_card(card_t c) {
  printf("%c%c", value_letter(c), suit_letter(c));
}


card_t card_from_letters(char value_let, char suit_let) {
  unsigned value;
  if ('1' <= value_let && value_let <= '9') {
    value= value_let - '0';
  } else if (value_let == '0') {
    value= 10;
  } else if (value_let == 'J') {
    value = VALUE_JACK;
  } else if (value_let == 'Q') {
    value = VALUE_QUEEN;
  } else if (value_let == 'K') {
    value = VALUE_KING;
  } else {   // value_let == 'A'
    value = VALUE_ACE;
  }

  suit_t suit;
  if (suit_let == 's') {
    suit = SPADES;
  } else if (suit_let == 'h') {
    suit = HEARTS;
  } else if (suit_let == 'd') {
    suit = DIAMONDS;
  } else {   // suit_let == 'c'
    suit = CLUBS;
  }

  card_t ans;
  ans.value = value;
  ans.suit = suit;
  return ans;
}


card_t card_from_num(unsigned c) {
  unsigned value = (c % 13) + 2;  // 0 <= c % 13 <= 12, 2 <= (c % 13) + 2 <= 14
  suit_t suit = c / 13;

  card_t ans;
  ans.value = value;
  ans.suit = suit;
  return ans;
}
