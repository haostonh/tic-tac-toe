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

int main() {
  int num_players;

  std::cout << "Welcome to Tic Tac Toe!\n" << std::endl;
  num_players = GetNumPlayers();
  
  // Temporary Fix for Choosing what Letter P1 or P2/Computer Gets
  char player_1 = 'X';
  char player_2 = 'O';
  char computer = 'O';

  return 0;
}