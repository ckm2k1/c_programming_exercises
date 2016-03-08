#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define NUM_SUITS 4
#define NUM_RANKS 13


int main(int argc, char const *argv[]) {
  int numCards, rank, suit;
  const char *suits[] = {"Clubs", "Spades", "Hearts", "Diamonds"};
  const char *ranks[] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};

  char inHand[NUM_SUITS][NUM_RANKS] = {{false}};

  srand((unsigned) time(NULL));

  printf("Enter the number of cards in hand: ");
  scanf("%d", &numCards);

  printf("Your hand: ");
  while (numCards > 0) {
    suit = rand() % NUM_SUITS;
    rank = rand() % NUM_RANKS;
    if (!inHand[suit][rank]) {
      inHand[suit][rank] = true;
      numCards--;
      printf("\n%s of %s", ranks[rank], suits[suit]);
    }
  }
  printf("\n");

  return 0;
}