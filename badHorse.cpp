/**
 * @file badHorse.cpp
 * @brief Template that opens a file and reads the stream
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

bool isBipartite( const std::vector<int> &_endA,
		  const std::vector<int> &_endB,
		  int _size );

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
  int T; // # Test cases
  int M; // # of baddies pairs
  std::string guyA, guyB; // temporal pair

  input.open( argv[1], std::ios::in );
  output.open( "badHorseResult.txt", std::ios::out );

  if( input.is_open() ) {
    std::getline( input, line );
    std::stringstream( line ) >> T;

    // For each test case
    for(int i = 0; i < T; ++i ) {
      std::getline( input, line );
      std::stringstream( line ) >> M;

      std::map<std::string, int> guys;
      std::map<std::string, int>::iterator it;
      std::vector<int> endA;
      std::vector<int> endB;

      // Get the M pairs
      for( int j = 0; j < M; ++j ) {
	std::getline( input, line );
	std::stringstream ss( line );
	std::getline( ss, guyA, ' ' );
	std::getline( ss, guyB, ' ' );
	
	it = guys.find(guyA);
	if( it == guys.end() ) {	  
	  guys[ guyA ] = guys.size() - 1;
	}
	
	it = guys.find( guyB );
	if( it == guys.end() ) {
	  guys[ guyB ] = guys.size() - 1;
	}

	endA.push_back( guys[guyA] );
	endB.push_back( guys[guyB] );
	
      } // end for each M pair
      
      
      if( isBipartite( endA, endB, guys.size() )  == true ) {
	output << "Case #"<<i+1<<": Yes"<< std::endl;
      } else {
	output << "Case #"<<i+1<<": No"<< std::endl;
      }
      
    } // end for each test case
    
  } else {
    std::cout << "[X] Error opening input file"<< std::endl;
  }
  
  input.close();
  output.close();
  
  return 0;
  
}

/**
 * @function isBipartite
 */
bool isBipartite( const std::vector<int> &_endA,
		  const std::vector<int> &_endB,
		  int _size ) {

  // Do a breadth-first search and assign colors
 

  std::vector< int > tree(_size, -1);
  std::vector< std::vector<int> > edges(_size);
  int j;

  for( int i = 0; i < _endA.size(); ++i ) {
    edges[ _endA[i] ].push_back( _endB[i] );
    edges[ _endB[i] ].push_back( _endA[i] );   
  }

  std::vector<int> queue;
  queue.push_back( 0 );
  tree[0] = 1;

  while( queue.size() > 0 ) {
    int n = queue[ queue.size() - 1];
    queue.pop_back();

    for( int i = 0; i < edges[n].size(); ++i ) {
      // If node was not colored
      if( tree[ edges[n][i] ] == -1 ) {
	// Add to the queue
	queue.push_back( edges[n][i] );
	// Color differently than the parent
	if( tree[n] == 1 ) { tree[ edges[n][i] ] = 2; } 
	else { tree[ edges[n][i] ] = 1; }  

      } 
      // If it was colored, check that it makes sense
      else {
	if( tree[n] == tree[ edges[n][i] ] ) { return false; }
      }
      
      
    }
  } // end while

  
  return true;
}
  
