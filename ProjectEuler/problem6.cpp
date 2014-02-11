/**< problem6.cpp */

#include <iostream>

int main( int argc, char* argv[] ) {

  int N = 100;
  long S1;
  long S2;
  long S;

  S1 = N*(N+1)*(2*N+1) / 6;
  S2 = ( N*(N+1)/2 )*( N*(N+1)/2 );
  S = S2 - S1;
  std::cout << "Result is: "<<S<<std::endl;

  return 0;
}
