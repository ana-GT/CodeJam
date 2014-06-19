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
  
  const int K = 2;
  std::string L[K];


  int lines = 0;
 
  while( input.good() ) {
    std::getline( input, line );
    if( !input.eof() ) {
      L[lines % K] = line;
      lines++;
    }
    
  }
  
 
  // If less than K lines were read, print them all
  int start, count;
  if( lines < K ) {
    start = 0;
    count = lines;
  } else {
    start = lines % K;
    count = K;
  }

  std::cout << "Count: "<< count << " and start: "<<start<<std::endl;
  std::cout << " and lines: "<<lines<<std::endl;
  for( int i = 0; i < count; ++i ) {
    std::cout << L[(start+i)%K] << std::endl;
  }

  input.close();

  return 0;

}
