#include <fstream>
#include <iostream>
#include <sstream>

int main( int argc, char *argv[] ) {

  std::string line;
  int n;

    do {    
      std::getline( std::cin, line );
      std::stringstream( line ) >> n; 
      if( n != 42 ) {
        std::cout << n << std::endl;
      } else {
        break;
      }
    } while(  n != 42 );
  

  return 0;
}
