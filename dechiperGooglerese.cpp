#include <iostream>
#include <map>
#include <string>
#include <assert.h>

int main( int argc, char* argv[] ) {

  std::map<char, char> googlerese;

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
      if(   c == ' ' ) { std::cout << "Found a white space" << std::endl; }
      // Got a character not found before
      if( googlerese.find(c) == googlerese.end() ) {
	googlerese[c] = cg;
      }

    }
  }


  // Add q
  googlerese['q'] = 'z';
  googlerese['z'] = 'q';

  std::cout << "By the end of mapping we got googlerese register "<< googlerese.size() << std::endl;
  
  std::cout << "Googlerese mapping: "<< std::endl;
  std::map<char,char>::iterator it;
  for( it = googlerese.begin(); it != googlerese.end(); ++it ) {
    std::cout << it->first << ": "<< it->second << std::endl;
  }
  

  // Time to read input
  
  return 0;
}
