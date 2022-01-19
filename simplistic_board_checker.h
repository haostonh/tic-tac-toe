// Only checks for the 8 winning conditions
int BoardChecker(char board[3][3]) {
  bool three_in_a_row = 0;
  char current_symbol;

  for (int row = 0; row <= 2; row++) {
    for (int col = 0; col <= 2; col++) {
      
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