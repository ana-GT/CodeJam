/**
 * @file moist.cpp
 * @brief Template that opens a file and reads the stream
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int sortLexi( std::vector<std::string> &_names );


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
  output.open( "moistResult.txt", std::ios::out );

  int T; // Number of test cases
  int N; // Number of ice skaters
  std::vector<std::string> names;
  int moves;

  if( input.is_open() ) {
    std::getline( input, line );
    std::stringstream( line ) >> T;

    // For each test case
    for( int i = 0; i < T; ++i ) {
      names.resize(0);

      std::getline( input, line );
      std::stringstream( line ) >> N;
      for( int j = 0; j < N; ++j ) {
	std::getline( input, line );
	names.push_back( line );
      }

      moves = sortLexi( names );

      output << "Case #"<<i+1<<": "<<moves<<std::endl;

    }

  } else {
    std::cout << "[X] Error opening input file"<< std::endl;
  }

  input.close();
  output.close();

  return 0;

}

/**
 * @function sortLexi
 */
int sortLexi( std::vector<std::string> &_names ) {

  int  r;
  int counter;
  std::string x;

  counter = 0;
  for( int i = 1; i < _names.size(); ++i ) {
    
    x = _names[i];
    
    for( int j = i-1; j >= 0; --j ) {
      r = _names[i].compare( _names[j] );
      
      if( r > 0 ) { continue; }
      if( r <= 0 ) {
	for( int k = j; k <= i-1; ++k ) {
	  _names[k+1] = _names[k];
	} 
	_names[j] = x; 
	
	counter++;
      }
      
    }      
    
  } // for names
  
  return counter;
  
}
