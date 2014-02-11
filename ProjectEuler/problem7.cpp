/**
 * @file problem7.cpp
 * @brief 10001st prime
 */
#include <iostream>
#include <stdio.h>
#include <math.h>

typedef long long int64_t;

/**< Functions */
bool FermatFactor( const int64_t & N, 
		   int64_t &_P1, 
		   int64_t &_P2 );
bool isSquare( int64_t _N );

/**
 * @function main 
 */
int main( int argc, char* argv[] ) {
    
  int64_t N = 3;
  int64_t prime = N;
  int64_t P1, P2;
  int primeOrder = 2;

  do {
    N = N +2;
     if( FermatFactor( N, P1, P2 ) == true ) {
			prime = N;
            primeOrder += 1;
	}
  } while( primeOrder != 10001 );

  std::cout <<" The 10001st prime  number is: "<<prime << std::endl;
  return 0;
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
