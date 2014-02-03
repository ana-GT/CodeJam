#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>

bool isPalindrome( int _N );

int main( int argc, char* argv[] ) {
  
  int N;
  int maxPalind = 0;
  int mA, mB;

  for( int i = 999; i > 99; --i ) {
    for( int j = 999; j > 99; --j ) {
      N = i*j;
      if( isPalindrome(N) == true ) {
	if( N > maxPalind ) {
	  maxPalind = N;
	  mA = i; mB = j;
	}
      }
    }
  }

  std::cout <<"Max Palind is: "<< maxPalind<< ": "<<mA<<" x "<< mB << std::endl; 
  return 0;
}

bool isPalindrome( int _N ) {

  std::stringstream ss;
  ss << _N;
  std::string s = ss.str();

  int n = s.length();
  int n2 =  n / 2;
  for( int i = 0; i <= n2; ++i ) {
    if( s[i] != s[n-1-i] ) { return false; }
  }
  return true;
}
