#include<iostream>
using namespace std;

int getPlayers() {
    int numPlayers = 0;
    
    while (numPlayers != 1 && numPlayers != 2) {
        std::cout << "Enter the number of players that will be playing: " << std::endl;
        std::cin >> numPlayers;
        
        if (numPlayers != 1 && numPlayers != 2) {
            std::cout << "Invalid Number of Players, Try Again" << std::endl;
        }
    }
    
    return numPlayers;
}

int main() {
    int numPlayers;

    std::cout << "Welcome to Tic Tac Toe!\n\n" << std::endl;
    numPlayers = getPlayers();
    

    return 0;
}