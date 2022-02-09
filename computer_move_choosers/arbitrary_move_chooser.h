#include<random>

int ComputerBoardChooser(char board[3][3], char computer_letter) {
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