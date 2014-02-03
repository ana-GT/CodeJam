#include <iostream>

int main( int argc, char* argv[] ) {
  int N, sum;
  std::cin >> N;
  
  sum = 0;
  for( int num = 0; num < N; ++num ) {
    if( num % 3 == 0 ) { sum += num; }
    else if( num % 5 == 0 ) { sum += num; }
  }

  std::cout << " Sum of multiples of 3 and 5 below "<<N<<" is: "<< sum << std::endl;

  return 0;
}
