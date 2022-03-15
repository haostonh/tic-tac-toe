#ifndef COMPUTER_MOVE_CHOOSERS_ARBITRARY_MOVE_CHOOSER_H_
#define COMPUTER_MOVE_CHOOSERS_ARBITRARY_MOVE_CHOOSER_H_

#include<random>

void ComputerBoardChooser(char board[3][3], char computer_letter) {
  bool invalid_coordinate = true;
  int x_coordinate = 0;
  int y_coordinate = 0;

  do {
    x_coordinate, y_coordinate = rand() % 3;

    if (board[x_coordinate][y_coordinate] == ' ') {
      invalid_coordinate = false;
      board[x_coordinate][y_coordinate] = computer_letter;
    }
  } 
  while (invalid_coordinate);
}

#endif // COMPUTER_MOVE_CHOOSERS_ARBITRARY_MOVE_CHOOSER_H_