#include<stdlib.h>
#include<time.h>

#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>

#include"board_checkers/simplistic_board_checker.h"
#include"computer_move_choosers/arbitrary_move_chooser.h"

using std::cin;
using std::cout;
using std::endl;
using std::find;
using std::getline;
using std::vector;

int BoardChecker(char board[3][3]);
void ComputerBoardChooser(char board[3][3], char computer_letter);

int GetNumPlayers() {
  int num_players;
  std::string str_num_players;
  std::stringstream ss_num_players;

  while (!(num_players == 1 || num_players == 2)) {
    std::cout << "Enter the number of players that will be playing: ";
    std::getline(std::cin,str_num_players);
    
    ss_num_players << str_num_players;
    ss_num_players >> num_players;

    if (ss_num_players.fail()) {
      ss_num_players.clear();
      ss_num_players.str("");
      std::cout << "Not Valid Characters, Try Again\n" << std::endl;
      continue;
    }

    if (!(num_players == 1 || num_players == 2)) {
      std::cout << "Invalid Number of Players, Try Again\n" << std::endl;
    }
  }
  
  return num_players;
}

void BoardPrinter(char board[3][3]) {
  std::cout << "          X-Axis  \n";
  std::cout << "         1   2   3\n";
  std::cout << "       1 " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
  std::cout << "         ---------" << "\n";
  std::cout << "Y-Axis 2 " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
  std::cout << "         ---------" << "\n";
  std::cout << "       3 " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
  std::cout << std::endl;
}

void BoardChooser(char board[3][3], char player_letter) {
  bool invalid_coords = true;
  int x_axis_coord; 
  int y_axis_coord;
  std::string str_x_axis_coord;
  std::string str_y_axis_coord;
  std::stringstream ss_x_axis_coord;
  std::stringstream ss_y_axis_coord;
  vector<int> valid_coord_nums = {1, 2, 3};
  vector<int>::iterator x_axis_iter;
  vector<int>::iterator y_axis_iter;
  
  // Check for validility of coordinates
  do {
    std::cout << "Enter X-Axis Coordinate: ";
    std::getline(std::cin,str_x_axis_coord);
    std::cout << "Enter Y-Axis Coordinate: ";
    std::getline(std::cin,str_y_axis_coord);

    // Check to ensure coordinates are in the range for integers 
    ss_x_axis_coord << str_x_axis_coord;
    ss_y_axis_coord << str_y_axis_coord;
    ss_x_axis_coord >> x_axis_coord;
    ss_y_axis_coord >> y_axis_coord;

    if (ss_x_axis_coord.fail() || ss_y_axis_coord.fail()) {
      std::cout << "Not a valid x-axis coordinate or y-axis coordinate integer, try again\n" << std::endl;
      ss_x_axis_coord.clear();
      ss_y_axis_coord.clear();
      ss_x_axis_coord.str("");
      ss_y_axis_coord.str("");
      continue;
    }

    // Checking if coordinates fall out of the range
    x_axis_iter = std::find(valid_coord_nums.begin(),valid_coord_nums.end(),x_axis_coord);
    y_axis_iter = std::find(valid_coord_nums.begin(),valid_coord_nums.end(),y_axis_coord);
    if (x_axis_iter != valid_coord_nums.end() && y_axis_iter != valid_coord_nums.end()){
      invalid_coords = false;
    } else if (x_axis_iter == valid_coord_nums.end() && y_axis_iter == valid_coord_nums.end()){
      std::cout << std::endl << "Please enter a valid x-axis coordinate and y-axis coordinate!\n\n";
    } else if (x_axis_iter == valid_coord_nums.end() && y_axis_iter != valid_coord_nums.end()) {
      std::cout << std::endl << "Please enter a valid x-axis coordinate!\n\n";
    } else if (x_axis_iter != valid_coord_nums.end() && y_axis_iter == valid_coord_nums.end()) {
      std::cout << std::endl << "Please enter a valid y-axis coordinate!\n\n";
    }
  } 
  while (invalid_coords);

  board[y_axis_coord - 1][x_axis_coord - 1] = player_letter;
}

int Player1VsComputer(char board[3][3], char player_1, char computer) {
  bool player_won = false;
  int player_turn = 1;

  for (int turn = 1; turn <= 9; turn++) {
    // Player Makes the Move
    switch (player_turn) {
      case 1:
        std::cout << "Player 1's Turn\n";
        BoardChooser(board, player_1);
        BoardPrinter(board);
        player_turn = 2;
        break;
      case 2:
        std::cout << "Computer's Turn\n";
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
  bool player_won = false;
  int player_turn = 1;

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
  const int board_size = 3;
  char board[board_size][board_size] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
  char player_1, player_2, computer;
  int num_players;
  std::string str_player_letter;
  std::stringstream ss_player_letter;

  srand(time(NULL));

  std::cout << "Welcome to Tic Tac Toe!\n\n";
  num_players = GetNumPlayers();
  
  do {
    std::cout << "Player 1: Enter X or O: ";
    std::getline(std::cin,str_player_letter);
    
    ss_player_letter << str_player_letter;
    ss_player_letter >> player_1;

    if (!(player_1 == 'X' || player_1 == 'O')) {
      std::cout << "Not a Tic-Tac-Toe letter, try again\n" << std::endl;
      ss_player_letter.clear();
      ss_player_letter.str("");
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

  std::cout << std::endl << "Here is what the playing field will look like: \n\n";
  BoardPrinter(board);
  std::cout << "\n";

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