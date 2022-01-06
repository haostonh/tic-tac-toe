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
      case 2:
        std::cout << "2" << std::endl;
      default:
        std::cout << "Exiting the Game" << std::endl;
        break;
    }

    // Validate if anyone has won yet

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
    case 2:
      Player1VsPlayer2();
    default:
      std::cout << "Not a Valid Player Count" << std::endl;
      return 0;
  }

  return 0;
}