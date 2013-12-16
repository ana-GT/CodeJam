/**
 * @file template.cpp
 * @brief Template that opens a file and reads the stream
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

/**
 * @function main
 */
int main( int argc, char* argv[] ) {

  if( argc != 2 ) {
    std::cout << "Syntax: "<<argv[0]<<" "<<argv[1]<<std::endl;
    return -1;
  }

  std::ifstream input;
  std::ofstream output;
  std::string line;


  input.open( argv[1], std::ios::in );
  output.open( "templateResult.txt", std::ios::out );

  if( input.is_open() ) {
    std::getline( input, line );
  } else {
    std::cout << "[X] Error opening input file"<< std::endl;
  }

  input.close();
  output.close();

  return 0;

}
