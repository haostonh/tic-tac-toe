// Checks for the 8 possible winning conditions
int BoardChecker(char board[3][3]) {
  const int num_win_conditions = 8;
  const int num_tile_coords = 3;
  const int num_x_y_coords = 2;
  int winning_rows[num_win_conditions][num_tile_coords][num_x_y_coords] = 
  {
    {{0,0},{0,1},{0,2}},{{1,0},{1,1},{1,2}},{{2,0},{2,1},{2,2}},{{0,0},{1,0},{2,0}},
    {{0,1},{1,1},{2,1}},{{0,2},{1,2},{2,2}},{{0,0},{1,1},{2,2}},{{2,0},{1,1},{0,2}}
  };
  bool three_in_a_row = false;
  char current_symbol;

  for (int index = 0; index <= num_win_conditions - 1; index++) {
    if (board[winning_rows[index][0][0]][winning_rows[index][0][1]] == board[winning_rows[index][1][0]][winning_rows[index][1][1]] &&
    board[winning_rows[index][1][0]][winning_rows[index][1][1]] == board[winning_rows[index][2][0]][winning_rows[index][2][1]]) {
      current_symbol = board[winning_rows[index][0][0]][winning_rows[index][0][1]];
      three_in_a_row = true;
    }

    if (three_in_a_row) {
      if (current_symbol == 'X') {
        return 1;
      } else if (current_symbol == 'O') {
        return 2;
      }
    }
  }
  return 0;
}