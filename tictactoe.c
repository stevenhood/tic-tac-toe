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

// The board is global
//        y  x
int board[3][3];

int main(int argc, char *argv[]) {
  int turns = 0;
  int currentPlayer;
  int currentX;
  int currentY;
  char *shape[] = { "", "Noughts", "Crosses" };

  printf("\n   Tic Tac Toe\n   ===========\n\n");
  clearBoard();
  printBoard();

  while(turns < 9) {

    currentPlayer = (turns % 2) + 1;
    printf("\n Player %d (%s), enter x,y coordinates for your move: ", currentPlayer, shape[currentPlayer]);
    scanf("%d,%d", &currentX, &currentY);

    if (!makeMove(currentPlayer, currentX-1, currentY-1)) {
      printf(" Invalid move.\n");
    } else {
      printf("\n");
      printBoard();
      if (testGoal()) {
	printf("\n Player %d has won!\n\n", currentPlayer);
	return 0;
      }
      turns++;
    }
  }

  printf("\n Stalemate!\n\n");
  return 0;
}

int makeMove(int player, int x, int y) {
  // Check if a move has already been made in that position
  // or if the coordinates are out of bounds
  if (board[y][x] > 0 || x < 0 || x > 2 || y < 0 || y > 2) {
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

    printf("   ");
    for(x = 0; x < 3; x++) {
      if (board[y][x] == 0) {
	printf("   ");
      } else if (board[y][x] == 1) {
	printf(" O ");
      } else if (board[y][x] == 2) {
	printf(" X ");
      }

      if (x < 2) {
	printf("|");
      }
    }
    printf("\n");

    if (y < 2) {
      printf("   ---|---|---\n"); // Separator
    } else {
      break;
    }

  }
  return;
}

int testGoal() {
  // Run all tests sequentially
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
  // Test for equality between every horizontally adjacent position (excluding zero)
  int x;
  for (x = 0; x < 3; x++) {
    if (board[0][x] != 0 && board[0][x] == board[1][x] && board[1][x] == board[2][x]) {
      return TRUE;
    }
  }
  return FALSE;
}

int testVertical() {
  // Tests equality of vertical positions
  int y;
  for (y = 0; y < 3; y++) {
    if (board[y][0] != 0 && board[y][0] == board[y][1] && board[y][1] == board[y][2]) {
      return TRUE;
    }
  }
  return FALSE;
}

int testDiagonal() {
  // Tests equality of the two diagonal positions
  if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board [2][2]) {
    return TRUE;
  } else if (board[2][0] != 0 && board[2][0] == board[1][1] && board[1][1] == board [0][2]) {
    return TRUE;
  }
  return FALSE;
}

