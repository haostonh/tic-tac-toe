#include"board_checkers/simplistic_board_checker.h"
#include"computer_move_choosers/arbitrary_move_chooser.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<sstream>
#include<string>
using namespace std;

int BoardChecker(char board[3][3]);
int ComputerBoardChooser(char board[3][3], char computer_letter);

int GetNumPlayers() {
  int num_players;

  while (!(num_players == 1 || num_players == 2)) {
    std::cout << "Enter the number of players that will be playing: ";
    std::cin >> num_players;
    std::cout << std::endl;

    if (!(num_players == 1 || num_players == 2)) {
        std::cout << "Invalid Number of Players, Try Again" << std::endl;

    }
  }
  
  return num_players;
}

void BoardPrinter(char board[3][3]) {
  std::cout << "          X-Axis  " << std::endl;
  std::cout << "         1   2   3" << std::endl;
  std::cout << "       1 " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << std::endl;
  std::cout << "         ---------" << std::endl;
  std::cout << "Y-Axis 2 " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << std::endl;
  std::cout << "         ---------" << std::endl;
  std::cout << "       3 " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << std::endl;
  std::cout << std::endl;
}

void BoardChooser(char board[3][3], char player_letter) {
  int x_axis_coord, y_axis_coord;
  vector<int> valid_coord_nums = {1, 2, 3};
  bool invalid_coords = true;

  // Check for validility of coordinates
  do {
    std::cout << "Choose X-Axis Coordinate: ";
    std::cin >> x_axis_coord;
    std::cout << "Choose Y-Axis Coordinate: ";
    std::cin >> y_axis_coord;

    vector<int>::iterator x_axis_iter = std::find(valid_coord_nums.begin(),valid_coord_nums.end(),x_axis_coord);
    vector<int>::iterator y_axis_iter = std::find(valid_coord_nums.begin(),valid_coord_nums.end(),y_axis_coord);
    if (x_axis_iter != valid_coord_nums.end() && y_axis_iter != valid_coord_nums.end()){
      invalid_coords = false;
    } else if (x_axis_iter == valid_coord_nums.end() && y_axis_iter == valid_coord_nums.end()){
      std::cout << std::endl << "Please enter a valid x-axis coordinate and y-axis coordinate!" << std::endl << std::endl;
    } else if (x_axis_iter == valid_coord_nums.end() && y_axis_iter != valid_coord_nums.end()) {
      std::cout << std::endl << "Please enter a valid x-axis coordinate!" << std::endl << std::endl;
    } else if (x_axis_iter != valid_coord_nums.end() && y_axis_iter == valid_coord_nums.end()) {
      std::cout << std::endl << "Please enter a valid y-axis coordinate!" << std::endl << std::endl;
    }
  } 
  while (invalid_coords);

  board[y_axis_coord - 1][x_axis_coord - 1] = player_letter;
}

int Player1VsComputer(char board[3][3], char player_1, char computer) {
  int player_turn = 1;
  bool player_won = false;

  for (int turn = 1; turn <= 9; turn++) {
    // Player Makes the Move
    switch (player_turn) {
      case 1:
        std::cout << "Player 1's Turn" << std::endl;
        BoardChooser(board, player_1);
        BoardPrinter(board);
        player_turn = 2;
        break;
      case 2:
        std::cout << "Computer's Turn" << std::endl;
        ComputerBoardChooser(board, computer);
        BoardPrinter(board);
        player_turn = 1;
        break;
      default:
        std::cout << "Exiting the Game" << std::endl;
        break;
    }

    // Validate if anyone has won yet
    switch (BoardChecker(board, player_1, computer)) {
      case 1:
        std::cout << "Player 1 has won!" << std::endl;
        player_won = true;
        break;
      case 2:
        std::cout << "Computer has won!" << std::endl;
        player_won = true;
        break;
      default:
        continue;
    }

    if (player_won) {
      break;
    }
  }
  return 0;
}

int Player1VsPlayer2(char board[3][3], char player_1, char player_2) {
  int player_turn = 1;
  bool player_won = false;

  for (int turn = 1; turn <= 9; turn++) {
    // Player Makes the Move
    switch (player_turn) {
      case 1:
        std::cout << "Player 1's Turn" << std::endl;
        BoardChooser(board, player_1);
        BoardPrinter(board);
        player_turn = 2;
        break;
      case 2:
        std::cout << "Player 2's Turn" << std::endl;
        BoardChooser(board, player_2);
        BoardPrinter(board);
        player_turn = 1;
        break;
      default:
        std::cout << "Exiting the Game" << std::endl;
        break;
    }

    // Validate if anyone has won yet
    switch (BoardChecker(board, player_1, player_2)) {
      case 1:
        std::cout << "Player 1 has won!" << std::endl;
        player_won = true;
        break;
      case 2:
        std::cout << "Player 2 has won!" << std::endl;
        player_won = true;
        break;
      default:
        continue;
    }

    if (player_won) {
      break;
    }
  }

  return 0;
}

int main() {
  int num_players;
  char player_1, player_2, computer;
  char board[3][3] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
  srand(time(NULL));

  std::cout << "Welcome to Tic Tac Toe!\n" << std::endl;
  num_players = GetNumPlayers();
  
  do {
    std::cout << "Player 1: Choose X or O: ";
    std::cin >> player_1;
    if (!(player_1 == 'X' || player_1 == 'O')) {
      std::cout << "Not a Tic-Tac-Toe letter, try again" << std::endl << std::endl;
    }
  } while (!(player_1 == 'X' || player_1 == 'O'));

  switch (player_1) {
    case 'X':
      player_2, computer = 'O';
      break;
    case 'O':
      player_2, computer = 'X';
      break;
    default:
      std::cout << "Player 1's letter not found" << std::endl;
      return -1;
  }


  std::cout << "Here is what the playing field will look like: " << std::endl << std::endl;
  BoardPrinter(board);
  std::cout << std::endl;

  switch (num_players) {
    case 1:
      Player1VsComputer(board, player_1, computer);
      break;
    case 2:
      Player1VsPlayer2(board, player_1, player_2);
      break;
    default:
      std::cout << "Not a Valid Player Count" << std::endl;
      return -1;
  }

  return 0;
}