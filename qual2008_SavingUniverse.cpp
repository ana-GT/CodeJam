/**
 * @file template.cpp
 * @brief Template that opens a file and reads the stream
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int getMinSwitches( const std::vector<std::string> &_engines,
                    const std::vector<std::string> &_queries,
                    int pos );

/**
 * @function main
 */
int main( int argc, char* argv[] ) {

  if( argc != 2 ) {
    std::cout << "Syntax: "<<argv[0]<<" "<<argv[1]<<std::endl;
    return -1;
  }

  std::ifstream input;
  std::ofstream output;
  std::string line;


  input.open( argv[1], std::ios::in );
  output.open( "savingUniverseResult.txt", std::ios::out );

  int N;
  int S;
  int Q;
  std::vector<std::string> engines;
  std::vector<std::string> queries;

  if( input.is_open() ) {
    std::getline( input, line );
    std::stringstream(line) >> N;
    std::cout << "Number of cases: "<< N << std::endl;
    
    for( int i = 0; i < N; ++i ) {
       // Read engines names
      std::getline( input, line );
      std::stringstream(line) >> S;

      engines.resize(0);
      for( int j = 0; j < S; ++j ) {
        std::getline( input, line );
        engines.push_back( line );
      }
      
      // Read queries
      std::getline( input, line );
      std::stringstream(line) >> Q;

      queries.resize(0);
      for( int j = 0; j < Q; ++j ) {
        std::getline( input, line );
        queries.push_back( line );
      }
    
      // Solve it
      output << "Case #"<<i+1<<": "<< getMinSwitches( engines, queries, 0 ) << std::endl;
    }

  } else {
    std::cout << "[X] Error opening input file"<< std::endl;
  }

  input.close();
  output.close();

  return 0;

}

/**
  *
  */
int getMinSwitches( const std::vector<std::string> &_engines,
                    const std::vector<std::string> &_queries,
                    int pos  ) {

  std::vector<std::string> engines = _engines;

  std::vector<std::string>::iterator it;
  for( int j = pos; j < _queries.size(); ++j ) {
   

    it = std::find( engines.begin(), engines.end(), _queries[j] );
    if( it != engines.end() ) {
      engines.erase( it );

      if( engines.size() == 0 ) {
        return 1 + getMinSwitches( _engines, _queries, j );
      }

    } 


  }

  return 0;
}
