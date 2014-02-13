/**
 * @file allYourBase.cpp
 * @brief Calculate how many mkdir we need
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <math.h>

typedef long long int64_t;

int64_t getMinSeconds( std::string _s );

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

  int T; // # Test cases
  int64_t sec; // Minimum number of seconds

  input.open( argv[1], std::ios::in );
  output.open( "allYourItResult.txt", std::ios::out );

  if( input.is_open() ) {
    std::getline( input, line );
    std::stringstream( line ) >> T;

    // For each test case
    for(int i = 0; i < T; ++i ) {
      std::getline( input, line );
      sec = getMinSeconds( line );

      output << "Case #"<<i+1<<": "<<sec<< std::endl;
      
    } // end for each test case
    
  } else {
    std::cout << "[X] Error opening input file"<< std::endl;
  }
  
  input.close();
  output.close();
  
  return 0;
  
}


int64_t getMinSeconds( std::string _s ) {
  
  std::map<char, int> roll;
  std::map<char,int>::iterator it;
  std::vector<int64_t> num( _s.length() ); 

  int64_t value;
  int64_t base = 0;
  int counter = 0;

  // Store all the characters in a vector
  for( int i = 0; i < _s.length(); ++i ) {
    char c = _s[i];

    if( i == 0 ) {
      roll.insert( std::pair<char,int>( c, 1 ) );
      num[i] = 1;
    }

    else {
      it = roll.find(c);
      // If not yet, add 1 to possible base
      if( it == roll.end() ) {
	roll.insert( std::pair<char,int>(c, counter) );
	num[i] = counter;
	counter++; if( counter == 1 ) { counter = 2; }
      }
      else {
       num[i] = it->second;
      }

    }
  
  }

  // Base cannot be unary, so pop the next smallest
  // if that is the case
  base = roll.size();
  if( base == 1 ) { base = 2; }

  // Now calculate the minimum number
  int64_t result = 0;
  
  

  int lastInd = num.size() - 1;
  int64_t added;
  for( int i = 0; i < num.size()-1; ++i ) {
    result = result*base + num[i]*base;
  } 

  result = result + num[num.size() - 1];

  return result;
}
