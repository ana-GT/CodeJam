/**
 * @file problem8.cpp
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

int main( int argc, char *argv[] ) {

  if( argc != 2 ) {
    std::cout << "Syntax: "<< argv[0]<<" "<<argv[1] << std::endl;
  }

  std::ifstream input;
  std::string line;
  int Lines = 20;
  std::vector<int> nums;
  std::string allStrings;

  input.open( argv[1], std::ios::in );
  if( input.is_open() ) {
    for( int i = 0; i < Lines; ++i ) {
      std::getline( input, line );
      allStrings.append( line );
    }
  }
  input.close();
  std::cout << "All strings: " << allStrings << std::endl;

  // Save numbers in nums
  char c; int a;
  for( int i = 0; i < allStrings.length(); ++i ) {
    c = allStrings[i];
    a = atoi(&c);
    nums.push_back(a);
  }

  // Calculate biggest multiplication of 5 consecutive numbers
  int prod;
  int maxProd = -1000;

  for( int i = 0; i < nums.size() - 5; ++i ) {
    prod = 1;
    for( int j = i; j <= i+4; ++j ) {
      prod *= nums[j];
    }  
    if( prod > maxProd ) { maxProd = prod; }
  }

  std::cout << "MaxProd is: "<< maxProd << std::endl;
    return 0;
}
