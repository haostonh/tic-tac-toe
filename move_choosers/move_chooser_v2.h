#ifndef MOVE_CHOOSERS_MOVE_CHOOSER_V2_H_
#define MOVE_CHOOSERS_MOVE_CHOOSER_V2_H_

#include<iostream>
#include<sstream>
#include<string>
#include<regex>

void BoardChooser(char board[3][3], char player_letter) {
  bool invalid_coords = true;
  int x_axis_coord; 
  int y_axis_coord;
  std::string str_x_axis_coord = "";
  std::string str_y_axis_coord = "";
  std::stringstream ss_x_axis_coord;
  std::stringstream ss_y_axis_coord;

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

    if (std::regex_match(str_x_axis_coord, std::regex("[1-3]")) && std::regex_match(str_y_axis_coord, std::regex("[1-3]"))) {
      ss_x_axis_coord.clear();
      ss_y_axis_coord.clear();
      ss_x_axis_coord.str("");
      ss_y_axis_coord.str("");
      invalid_coords = false;
    }
  } 
  while (invalid_coords);

  board[y_axis_coord - 1][x_axis_coord - 1] = player_letter;  
}

#endif // MOVE_CHOOSERS_MOVE_CHOOSER_V2_H_