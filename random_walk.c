#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define len(a) (sizeof(a) / sizeof(a[0]))

#define WIDTH 30
#define HEIGHT 30

void printBoard(char board[WIDTH][HEIGHT], bool fill) {
  for (int i = 0; i < WIDTH; ++i) {
    for (int j = 0; j < HEIGHT; ++j) {
      if (fill) board[i][j] = '.';
      else printf("%3c", board[i][j]);
    }
    if (!fill) printf("\n");
  }
}

int main() {
  srand((unsigned) time(NULL));

  char board[WIDTH][HEIGHT] = {{0}};
  printBoard(board, true);
  // printBoard(board, false);

  int movesLeft = 4;
  int directionsTried[4] = {0};
  int x = 0, y = 0;
  char currentLetter = 'A';
  int moves[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

  board[0][0] = currentLetter;
  int cycleCount = 10;
  while(movesLeft && cycleCount) {
    int move = rand() % 4;
    // printf("%d ", move);
    if (directionsTried[move]) continue;
    int tempX = x + moves[move][0], tempY = y + moves[move][1];
    // printf("x: %d, y: %d ", tempX, tempY);
    if (tempX > WIDTH - 1 ||
        tempY > HEIGHT - 1 ||
        tempX < 0 ||
        tempY < 0 ||
        board[tempX][tempY] != '.') {
      directionsTried[move] = 1;
      --movesLeft;
      continue;
    }

    board[tempX][tempY] = ++currentLetter;
    for (int i = 0; i < 4; ++i) directionsTried[i] = 0;
    x = tempX;
    y = tempY;
    movesLeft = 4;
    if (currentLetter == 'Z') {
      currentLetter = 'A' - 1;
      --cycleCount;
    }
  }

  printBoard(board, false);

  return 0;
}