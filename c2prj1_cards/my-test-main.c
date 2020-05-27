#include "cards.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  card_t card;
  for (int i=0;i<52;i++){
    card = card_from_num(i);
    printf("Card %d: ", i);
    print_card(card);
    printf("\n");
  }
}
