/**
 * @file dancingWithTheGooglers.cpp
 * @brief 
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

bool fx( int _i, int _j );
int danceTest( int _N, int _S, int _p, std::vector<int> _t );

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
  output.open( "dancingResult.txt", std::ios::out );

  int T;
  int N; int S; int p;
  std::vector<int> t;
  int maxGooglers;

  if( input.is_open() ) {
    std::getline( input, line );
    std::stringstream(line) >> T;
    std::cout << "Number of cases: "<< T << std::endl;

    for( int i = 0; i < T; ++i ) {
      std::getline( input, line );
      std::stringstream lineStream(line);

      lineStream >> N;
      lineStream >> S;
      lineStream >> p;
      t.resize(N);
      for( int j = 0; j < N; ++j ) {
	lineStream >> t[j];
      }
      maxGooglers = danceTest( N, S, p, t );
      output << "Case #"<<i+1<<": "<<maxGooglers << std::endl;
    }

  } else {
    std::cout << "[X] Error opening input file"<< std::endl;
  }

  input.close();
  output.close();

  return 0;

}

/**
 *
 */
int danceTest( int _N, 
	       int _S, 
	       int _p, 
	       std::vector<int> _t ) {
  /*
  std::cout << " Checking case with "<<_N<<" dancers. Surprises: "<<_S<<
    " at least with a maximum of "<<_p<<std::endl;
  for( int i = 0; i < _t.size(); ++i ) {
    std::cout << _t[i]<<" ";
  }
  std::cout << std::endl;
  */
  std::vector<int> t = _t;

  // 1. Sort
  std::sort( t.begin(), t.end(), fx );

  // 2. The smallest _S will be surprises,  the rest will be normal
  int count = 0;
  int x; int a;

  //-- Surprise
  for( int i = 0; i < _S; ++i ) {
    x = t[i];
    if( (x+4) % 3 == 0 ) { a = (x+4) / 3; if( a >= _p  && a >= 0 && a <= 10 ) { count++; continue; } }
    if( (x+3) % 3 == 0 ) { a = (x+3) / 3; if( a >= _p  && a >= 0 && a <= 10 ) { count++; continue; } }
    if( (x+2) % 3 == 0 ) { a = (x+2) / 3; if( a >= _p  && a >= 0 && a <= 10 ) { count++; continue; } }
    if( (x+1) % 3 == 0 ) { a = (x+1) / 3; if( a >= _p  && a >= 0 && a <= 10 ) { count++; continue; } }

    if( (x) % 3 == 0 ) { a = (x) / 3; if( a+1 >= _p && a >= 0 && a <= 10 ) { count++; continue; } }   
    
    if( (x-1) % 3 == 0 ) { a = (x-1) / 3; if( a+1 >= _p  && a >= 0 && a <= 10 ) { count++; continue; } }

    if( (x-2) % 3 == 0 ) { a = (x-2) / 3; if( a+2 >= _p  && a >= 0 && a <= 10 ) { count++; continue; } }
    if( (x-3) % 3 == 0 ) { a = (x-3) / 3; if( a+2 >= _p  && a >= 0 && a <= 10 ) { count++; continue; } }
    if( (x-4) % 3 == 0 ) { a = (x-4) / 3; if( a+2 >= _p  && a >= 0 && a <= 10 ) { count++; continue; } }

  }

  //-- Normal
  for( int i = _S; i < _N; ++i ) {
    x = t[i];
    
    if( (x+2) % 3 == 0 ) { a = (x+2) / 3; if( a >= _p  && a >= 0 && a <= 10) { count++; continue; } }
    if( (x+1) % 3 == 0 ) { a = (x+1) / 3; if( a >= _p  && a >= 0 && a <= 10) { count++; continue; } }
    if( (x) % 3 == 0 )   { a = (x) / 3; if( a >= _p  && a >= 0 && a <= 10) { count++; continue; } }
    if( (x-1) % 3 == 0 ) { a = (x-1) / 3; if( a+1 >= _p  && a >= 0 && a <= 10) { count++; continue; } }
    if( (x-2) % 3 == 0 ) { a = (x-2) / 3; if( a+1 >= _p  && a >= 0 && a <= 10 ) { count++; continue; } }       
  } 
  std::cout << std::endl;
  return count;
}

/**
 * @function fx
 */
bool fx( int _i, int _j ) { return (_i < _j ); }
