// Performs checks for three in a row on each tile
int BoardChecker(char board[3][3]) {
  bool three_in_a_row = 0;
  char current_symbol;

  for (int row = 0; row <= 2; row++) {
    for (int col = 0; col <= 2; col++) {
      current_symbol = board[row][col];
      
      // 1. Error Check to ensure not out of bounds
      // 2. Check for rows of 3 of same letter

      // Check upper left corner tile
      if ((row + 1 < 3) && (row + 2 < 3) && (col + 1 < 3) && (col + 2 < 3)) {
        if (((current_symbol == board[row][col + 1]) && (current_symbol == board[row][col + 2])) ||
        ((current_symbol == board[row + 1][col]) && (current_symbol == board[row + 2][col])) ||
        ((current_symbol == board[row + 1][col + 1]) && (current_symbol == board[row + 2][col + 2]))) {
          three_in_a_row = 1;
          break;
        }
      }

      // Check upper center tile
      if ((row + 1 < 3) && (row + 2 < 3) && (col - 1 >= 0) && (col + 1 < 3)) {
        if (((current_symbol == board[row][col - 1]) && (current_symbol == board[row][col + 1])) ||
        ((current_symbol == board[row + 1][col]) && (current_symbol == board[row + 2][col]))) {
          three_in_a_row = 1;
          break;
        }
      }

      // Check upper right corner tile
      if ((row + 1 < 3) && (row + 2 < 3) && (col - 1 >= 0) && (col - 2 >= 0)) {
        if (((current_symbol == board[row][col - 1]) && (current_symbol == board[row][col - 2])) ||
        ((current_symbol == board[row + 1][col]) && (current_symbol == board[row + 2][col])) ||
        ((current_symbol == board[row + 1][col - 1]) && (current_symbol == board[row + 2][col - 2]))) {
          three_in_a_row = 1;
          break;
        }
      }

      // Check middle left tile
      if ((row - 1 >= 0) && (row + 1 < 3) && (col + 1 < 3) && (col + 2 < 3)) {
        if (((current_symbol == board[row][col + 1]) && (current_symbol == board[row][col + 2])) ||
        ((current_symbol == board[row - 1][col]) && (current_symbol == board[row + 1][col]))) {
          three_in_a_row = 1;
          break;
        }
      }

      // Check middle center tile
      if ((row - 1 >= 0) && (row + 1 < 3) && (col - 1 >= 0 ) && (col + 1 < 3)) {
        if (((current_symbol == board[row][col - 1]) && (current_symbol == board[row][col + 1])) ||
        ((current_symbol == board[row - 1][col]) && (current_symbol == board[row + 1][col])) ||
        ((current_symbol == board[row - 1][col - 1]) && (current_symbol == board[row + 1][col + 1])) ||
        ((current_symbol == board[row + 1][col - 1]) && (current_symbol == board[row - 1][col + 1]))) {
          three_in_a_row = 1;
          break;
        }
      }

      // Check middle right tile
      if ((row - 1 >= 0) && (row + 1 < 3) && (col - 1 >= 0) && (col - 2 >= 0)) {
        if (((current_symbol == board[row][col - 1]) && (current_symbol == board[row][col - 2])) ||
        ((current_symbol == board[row - 1][col]) && (current_symbol == board[row + 1][col]))) {
          three_in_a_row = 1;
          break;
        }
      }

      // Check bottom left corner tile
      if ((row - 1 >= 0) && (row - 2 >= 0) && (col + 1 < 3) && (col + 2 < 3)) {
        if (((current_symbol == board[row][col + 1]) && (current_symbol == board[row][col + 2])) ||
        ((current_symbol == board[row - 1][col]) && (current_symbol == board[row - 2][col])) ||
        ((current_symbol == board[row - 1][col + 1]) && (current_symbol == board[row - 2][col + 2]))) {
          three_in_a_row = 1;
          break;
        }
      }

      // Check bottom center tile
      if ((row - 1 >= 0) && (row - 2 >= 0) && (col - 1 >= 0) && (col + 1 < 3)) {
        if (((current_symbol == board[row][col - 1]) && (current_symbol == board[row][col + 1])) ||
        ((current_symbol == board[row - 1][col]) && (current_symbol == board[row - 2][col]))) {
          three_in_a_row = 1;
          break;
        }
      }

      // Check bottom right tile
      if ((row - 1 >= 0) && (row - 2 >= 0) && (col - 1 >= 0) && (col - 2 >= 0)) {
        if (((current_symbol == board[row][col - 1]) && (current_symbol == board[row][col - 2])) ||
        ((current_symbol == board[row - 1][col]) && (current_symbol == board[row - 2][col])) ||
        ((current_symbol == board[row - 1][col - 1]) && (current_symbol == board[row - 2][col - 2]))) {
          three_in_a_row = 1;
          break;
        }
      }
    }

    if (three_in_a_row == true) {
      if (current_symbol == 'X') {
        return 1;
      } else if (current_symbol == 'O') {
        return 2;
      }
    }
  }
  return 0;
}