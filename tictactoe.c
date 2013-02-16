#include <stdio.h>

#define TRUE 1
#define FALSE 0

int makeMove(int player, int x, int y);
void clearBoard();
void printBoard();

int testGoal();
int testHorizontal();
int testVertical();
int testDiagonal();

//        y  x
int board[3][3];

int main(int argc, char *argv[]) {
  printf("\nTic Tac Toe\n===========\n\n");
  clearBoard();
  printBoard();
  int turns = 0;

  int currentPlayer;
  int currentX;
  int currentY;

  while(1) {
    currentPlayer = (turns % 2) + 1;
    printf("\nPlayer %d, enter x,y coordinates for your move: ", currentPlayer);
    scanf("%d,%d", &currentX, &currentY);
    makeMove(currentPlayer, currentX, currentY);
    printBoard();
    if (testGoal()) {
      printf("Player %d has won!\n\n", currentPlayer);
      return;
    }
    turns++;
  }
}

int makeMove(int player, int x, int y) {
  // Check if a move has already been made in that position
  if (board[y][x] > 0) {
    return FALSE;
  } else {
    board[y][x] = player;
    return TRUE;
  }
}

void clearBoard() {
  int y, x;
  for (y = 0; y < 3; y++) {
    for (x = 0; x < 3; x++) {
      board[y][x] = 0;
    }
  }
  return;
}

void printBoard() {
  int y, x;
  for (y = 0; y < 3; y++) {
    printf(" %d | %d | %d \n", board[y][0], board[y][1], board[y][2]);

    if (y < 2) {
      printf("---|---|---\n"); // Separator
    } else {
      break;
    }
  }
  return;
}

int testGoal() {
  if (testHorizontal()) {
    return TRUE;
  } else if (testVertical()) {
    return TRUE;
  } else if (testDiagonal()) {
    return TRUE;
  } else {
    return FALSE;
  }
}

int testHorizontal() {
  int x;
  for (x = 0; x < 3; x++) {
    if (board[0][x] != 0 && board[0][x] == board[1][x] && board[1][x] == board[2][x]) {
      return TRUE;
    }
  }
  return FALSE;
}

int testVertical() {
  int y;
  for (y = 0; y < 3; y++) {
    if (board[y][0] != 0 && board[y][0] == board[y][1] && board[y][1] == board[y][2]) {
      return TRUE;
    }
  }
  return FALSE;
}

int testDiagonal() {
  if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board [2][2]) {
    return TRUE;
  } else if (board[2][0] != 0 && board[2][0] == board[1][1] && board[1][1] == board [0][2]) {
    return TRUE;
  }
  return FALSE;
}

