/**< Euler 5 */

#include <iostream>

typedef long long int64_t;

int64_t gcd( const int64_t &A, const int64_t &B);
int64_t lcm( const int64_t &A, const int64_t &B );

/** */
int main( int argc, char* argv[] ) {


  int64_t small = 1;

  for( int64_t i = 2; i <= 20; ++i ) {
    small = lcm( small, i );
  }

  std::cout << " LCM for numbers less than 20: "<< small << std::endl;

  return 0;
}

int64_t lcm( const int64_t &A, const int64_t &B ) {

  return (A*B)/gcd(A,B);
}

int64_t gcd( const int64_t &_A, const int64_t &_B) {
  
  int A, B;
  A = _A; B = _B;

  if( A == B ) { return A; }
  if( A > B ) {
    while( A > B ) {
      A = A-B;
    }
    return gcd( A, B); 
  }
  if( B > A ) { 
    while( B > A ) {
      B = B-A;
    }
    return gcd( A, B); 
  }
}
