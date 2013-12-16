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
      printf("Case %d \n", i+1);
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
      
      for( it = guys.begin(); it != guys.end(); ++it ) {
	std::cout << it->first << " => " << it->second << '\n';
      }
      
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

  for( int i = 0; i < _size; ++i ) {

    for( int ij = 0; ij < edges[i].size(); ++ij ) {
     
      j = edges[i][ij];
   
      // i is colored
      if( tree[i] != -1 ) {
	
	// if j is colored
	if( tree[j] != -1 ) {
	  if( tree[i] == tree[j] ) { return false; } // If same color, NO BIPARTITE
	}
	// If j is not colored, color it with a different color than i
	else {
	  if( tree[i] == 1 ) { tree[j] = 2; }
	  else { tree[j] = 1; }
	}

      }

      // i is not colored
      else {

	// if j is colored
	if( tree[j] != -1 ) {
	  if( tree[j] == 1 ) { tree[i] = 2; }
	  else { tree[i] = 1; }
	}
	// if j is not colored
	//Check if there is not yet a constraint
	for( int k = 0; k < edges[i].size(); ++k ) {
	  if( tree[ edges[i][k] ] == 1 ) { tree[i] = 2; tree[j] = 1; break; }
	  else if( tree[ edges[i][k] ] == 2 ) { tree[i] = 1; tree[j] = 2; break; }
	}

	//Check if there is not yet a constraint
	for( int k = 0; k < edges[j].size(); ++k ) {
	  if( tree[ edges[j][k] ] == 1 ) { if( tree[j] == 1 ) { return false; } else {tree[j] = 2; tree[i] = 1; break; } }
	  else if( tree[ edges[j][k] ] == 2 ) { if( tree[j] == 2 ) { return false; } else  { tree[j] = 1; tree[i] = 2; break; } }
	}
	
	if( tree[i] == -1 && tree[j] == -1 ) { tree[i] = 1; tree[j] = 2; }


      }

    }

  }

  return true;
}
  
