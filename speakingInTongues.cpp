/**
 * @file template.cpp
 * @brief Template that opens a file and reads the stream
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <assert.h>
#include <map>

std::map<char, char> googlerese;

void parseGooglerese();
std::string translate( std::string _line );

/**
 * @function main
 */
int main( int argc, char* argv[] ) {
  
  // Get parse map
  parseGooglerese();

  // Let's do it
  if( argc != 2 ) {
    std::cout << "Syntax: "<<argv[0]<<" "<<argv[1]<<std::endl;
    return -1;
  }

  std::ifstream input;
  std::ofstream output;
  std::string line;


  input.open( argv[1], std::ios::in );
  output.open( "googlereseResult.txt", std::ios::out );

  int T;
  if( input.is_open() ) {
    std::getline( input, line );
    std::stringstream(line) >> T;

    for( int i  = 0; i < T; ++i ) {
      std::getline( input, line );
      output << "Case #"<<i+1<<": "<<translate(line)<<std::endl;
    }

  } else {
    std::cout << "[X] Error opening input file"<< std::endl;
  }

  input.close();
  output.close();

  return 0;

}

/**
 * @function translate
 */
std::string translate( std::string _line ) {
  int n = _line.length();
 std::string output( n, ' ');

  for( int i = 0; i < n; ++i ) {
	output.at(i) = googlerese.find( _line.at(i) )->second;
  }
  return output;
}

/**
 * @function parseGooglerese
 */
void parseGooglerese() {

  std::string input[3];  
  std::string output[3];
  input[0] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
  input[1] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
  input[2] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
  

  output[0] = "our language is impossible to understand";
  output[1] = "there are twenty six factorial possibilities";
  output[2] = "so it is okay if you want to just give up";

  char c;
  char cg;
  for( int i = 0; i < 3; ++i ) {
    assert( input[i].length() == output[i].length() );
    for( int j = 0; j < input[i].length(); ++j ) {
      c = input[i].at(j);
      cg = output[i].at(j);
      // Got a character not found before
      if( googlerese.find(c) == googlerese.end() ) {
	googlerese[c] = cg;
      }

    }
  }

  // Add q
  googlerese['q'] = 'z';
  googlerese['z'] = 'q';

}
