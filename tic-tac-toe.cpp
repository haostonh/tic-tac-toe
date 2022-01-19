#include<iostream>
using namespace std;

int GetNumPlayers() {
  int num_players = 0;
    
  while (num_players != 1 && num_players != 2) {
    std::cout << "Enter the number of players that will be playing: " << std::endl;
    std::cin >> num_players;

    if (num_players != 1 && num_players != 2) {
        std::cout << "Invalid Number of Players, Try Again" << std::endl;
    }
  }
  
  return num_players;
}

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

int Player1VsComputer() {
  return 0;
}

int Player1VsPlayer2() {
  int player_turn = 1;
  char board[3][3] = {' '};

  for (int turn = 1; turn <= 9; turn++) {
    // Player Makes the Move
    switch (player_turn) {
      case 1:
        std::cout << "1" << std::endl;
        break;
      case 2:
        std::cout << "2" << std::endl;\
        break;
      default:
        std::cout << "Exiting the Game" << std::endl;
        break;
    }

    // Validate if anyone has won yet
    switch (BoardChecker(board)) {
      case 1:
        std::cout << "Player 1 has won!" << std::endl;
        break;
      case 2:
        std::cout << "Player 2 has won!" << std::endl;
        break;
      default:
        continue;
    }
  }

  return 0;
}

int main() {
  int num_players;

  std::cout << "Welcome to Tic Tac Toe!\n" << std::endl;
  num_players = GetNumPlayers();
  
  // Temporary Fix for Choosing what Letter P1 or P2/Computer Gets
  char player_1 = 'X';
  char player_2 = 'O';
  char computer = 'O';

  std::cout << "Here is what the playing field will look like: " << std::endl;
  std::cout << " |  | " << std::endl;
  std::cout << "------" << std::endl;
  std::cout << " |  | " << std::endl;
  std::cout << "------" << std::endl;
  std::cout << " |  | " << std::endl;

  switch (num_players) {
    case 1:
      Player1VsComputer();
      break;
    case 2:
      Player1VsPlayer2();
      break;
    default:
      std::cout << "Not a Valid Player Count" << std::endl;
      return 0;
  }

  return 0;
}