/**
 * @file fileFixIt.cpp
 * @brief Calculate how many mkdir we need
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

int num_mkdir( std::vector<std::string> &_vecM,
	       std::vector<std::string> &_vecN );

void oneLevelUp( std::string &_s );

/**
 * @function main
 */
int main( int argc, char* argv[] ) {

  if( argc != 2 ) {
    std::cout << "Syntax: "<<argv[0]<<" "<<argv[1]<<"\n"<<std::endl;
    return -1;
  }

  std::ifstream input;
  std::ofstream output;
  std::string line;
  std::vector<std::string> vecM;
  std::vector<std::string> vecN;

  int T; // # Test cases
  int N; // # of existing folders
  int M; // # of folders you want to create
  int num; // # of makedir commands

  input.open( argv[1], std::ios::in );
  output.open( "fileFixItResult.txt", std::ios::out );

  if( input.is_open() ) {
    std::getline( input, line );
    std::stringstream( line ) >> T;

    // For each test case
    for(int i = 0; i < T; ++i ) {
      std::getline( input, line );
      std::stringstream( line ) >> M >> N;

      vecM.resize(0);
      vecN.resize(0);

      // Get the M directories existing already
      for( int j = 0; j < M; ++j ) {
	std::getline( input, line );
	vecM.push_back( line );
      }
	
      // Get the N directories to create
      for( int j = 0; j < N; ++j ) {
	std::getline( input, line );
	vecN.push_back( line );
      }

      num = num_mkdir( vecM, vecN );
      
      output << "Case #"<<i+1<<": "<<num<< std::endl;
      
    } // end for each test case
    
  } else {
    std::cout << "[X] Error opening input file"<< std::endl;
  }
  
  input.close();
  output.close();
  
  return 0;
  
}

/**
 * @function num_mkdir
 */
int num_mkdir( std::vector<std::string> &_vecM,
	       std::vector<std::string> &_vecN ) {


  std::string test;
  bool found;
  int counter;

  counter = 0;
  for( int i = _vecN.size() -1; i >= 0; --i ) {

    // 1. Check if directory to create does not exist already
    test = _vecN[i];
    _vecN.pop_back();

    found = false;
    do {
      for( int j = 0; j < _vecM.size(); ++j ) {
	if( test.compare( _vecM[j] ) == 0 ) {
	  found = true; break; // No operation needed
	}
      }

      if( found == true ) { break; }
      else { 
	// Add the full path
	_vecM.push_back( test );
	// Add for the last element added
	counter++;	
	// Change the test one level up
	oneLevelUp( test );
      }

    } while( test.length() > 0 );

  }

  return counter;
}

/**
 * @function oneLevelUp
 * @brief Go up one level of directory by searching for "/" backwards
 */
void oneLevelUp( std::string &_s ) {

  std::string newS;
  for( int i = _s.length() -1; i >= 0; i-- ) {
    if( _s[i] == '/' ) {
      newS = _s.substr( 0, i );
      _s = newS;
      break;
    }
  }

}
