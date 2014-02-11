#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

int main( int argc, char*argv[] ) {
 
  if( argc != 2 ) {
    std::cout << "Syntax: "<<argv[0]<<" "<<argv[1]<<std::endl;
    return -1;
  }

  std::ifstream input;
  std::string line;

  int T = 100; // Number of numbers to be added :)
  std::vector<std::string> ns; // String with numbers
  int d = 50;
  std::string s;
  input.open( argv[1], std::ios::in );

  if( input.is_open() ) {
    
    for( int i = 0; i < T; i++ ) {
      std::getline( input, line );
      ns.push_back( line );
    }

    // Sum
    int rem;
    char c; int a;
    std::vector<int> number;
    int sum;

    sum = 0;
    rem = 0;
    for(int ind = d-1; ind >= 0; --ind ) {

      sum = rem;
      for( int i = 0; i < T; ++i ) {
	c = ns[i][ind];
	a = atoi( &c );
	sum += a;
      }

      if( ind != 0 ) {
	number.push_back( sum % 10 );
	rem = sum / 10;   
      }
      else {
	while( sum / 10 != 0 ) {
	  number.push_back( sum % 10 );
	  sum = sum / 10;
	}  
	number.push_back( sum );
      }
    }
    std::cout << "First 10 digits should be"<<std::endl;
    for( int i = number.size() - 1; i >= 0; --i ) {
      std::cout<<number[i];
    }
    std::cout << std::endl;

  } else {
    std::cout << "[X] Error opening input file"<< std::endl;
  }
  
  input.close();

  return 0;
}


