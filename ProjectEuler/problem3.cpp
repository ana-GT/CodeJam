/**
 * @file problem3.cpp
 */
#include <iostream>
#include <stdio.h>
#include <math.h>

typedef long long int64_t;

/**< Functions */
int64_t BP( const int64_t & N );

bool FermatFactor( const int64_t & N, 
		   int64_t &_P1, 
		   int64_t &_P2 );
bool isSquare( int64_t _N );

/**
 * @function main 
 */
int main( int argc, char* argv[] ) {
  
  int64_t N = 600851475143;
  
  // 1. Get rid of factors of 2 
  do {
    if( N % 2 == 0 ) {
      N = N / 2;
    } else {
      break;
    } 
  } while(true);

  // 2. Get the biggest prime
  int64_t bigPrime = BP(N);
  std::cout <<" The biggest prime factor of number "<<N<<" is: "<< bigPrime << std::endl;
  return 0;
}

/**< Biggest Prime */
int64_t BP( const int64_t &N ) {
  
  int64_t P1, P2;
  int64_t BP1, BP2;

  if( FermatFactor( N, P1, P2 ) == true ) {
    return N;  
  }

  BP1 = BP( P1 );
  BP2 = BP( P2 );
  
  // Return the biggest prime of these two guys
  return BP1 > BP2 ? BP1:BP2;

}

/**< Fermat Factor method to get primes */
bool FermatFactor( const int64_t &N, 
		   int64_t &_P1, 
		   int64_t &_P2 ) {

  int64_t a,b, b2;

  a = ceil( sqrt(N) );
  b2 = a*a - N;
  while( isSquare(b2) == false ) {
    a++;
    b2 = a*a - N;
  }

  _P1 = a + sqrt(b2); // Return bigger prime
  _P2 = a - sqrt(b2); // Return smaller prime

  if( _P2 == 1 ) { return true; }
  else { return false; }
}

/** isSquare */
bool isSquare( int64_t _N ) {
  int64_t sq;

  sq = ceil( sqrt(_N) );
  if( sq*sq == _N ) { return true; }
  else { return false; }
}
