/**
 * @file captainHammer.cpp
 * @brief Template that opens a file and reads the stream
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>

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
  int T; // Number of test cases
  int V, D; // Velocity and horizontal distance
  double theta;

  input.open( argv[1], std::ios::in );
  output.open( "hammerResult.txt", std::ios::out );

  if( input.is_open() ) {
    std::getline( input, line );
    std::stringstream( line ) >> T;
    
    for( int i = 0; i < T; i++ ) {
      std::getline( input, line );
      std::stringstream( line ) >> V >> D;
      theta  = (0.5)*asin( 9.8 * D / (V*V) )*180.0 / M_PI;
      std::cout.precision(8);
      output << "Case #"<<i+1<<": "<<std::fixed<<theta<<std::endl;
    }

  } else {
    std::cout << "[X] Error opening input file"<< std::endl;
  }

  output.close();
  input.close();

  return 0;
}

