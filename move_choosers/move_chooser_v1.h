#ifndef MOVE_CHOOSERS_MOVE_CHOOSER_V1_H_
#define MOVE_CHOOSERS_MOVE_CHOOSER_V1_H_

#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using std::vector;

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
    } else {
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
    
    ss_x_axis_coord.clear();
    ss_y_axis_coord.clear();
    ss_x_axis_coord.str("");
    ss_y_axis_coord.str("");
  } 
  while (invalid_coords);

  board[y_axis_coord - 1][x_axis_coord - 1] = player_letter;
}

#endif // MOVE_CHOOSERS_MOVE_CHOOSER_V1_H_