/**
 * @file chapter13_1.cpp
 */
#include <fstream>
#include <iostream>

int main( int argc, char* argv[] ) {

  // Get file name
  if( argc != 2 ) {
    std::cout << "Syntax: " << argv[0]<< " filename"<< std::endl;
    return 1;
  }

  // Should know how many lines are out there (N)
  std::ifstream input;
  std::string line;
  input.open( argv[1], std::ios::in );
  
  int N;
  int K = 2;

  N = 0; 
  if( input.is_open() ) {
    do {
      std::getline( input, line );
      N++;
    } while( !input.eof() );
  }
  N--;

  input.close();

  std::cout << "Number of lines: "<< N << std::endl;


  // Read them and get to the line (N-K)
  // Print the last K ones
  input.open( argv[1], std::ios::in );

  if( input.is_open() ) {
      
    for( int i = 0; i < N; ++i ) {
      std::getline( input, line );      
      if( i >= N-K) {
	std::cout << line << std::endl;
      }
    }
  }
  
  input.close();

  return 0;

}
