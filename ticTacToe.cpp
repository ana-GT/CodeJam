/**
 * @file ticTacToe.cpp
 * @brief Qualification 2013
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::string getTableStatus( char table[][4] );
bool checkWinner( char row[], std::string &_result );

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
  int T; // Number of test cases
  char table[4][4];
  std::string result;

  input.open( argv[1], std::ios::in );
  output.open( "ticResult.txt", std::ios::out );

  if( input.is_open() ) {
    std::getline( input, line );
    std::stringstream( line ) >> T;

    for( int i = 0; i < T; ++i ) {

    	for( int j = 0; j < 4; ++j ) {
    		std::getline( input, line );
    		for( int k = 0; k < 4; ++k ) {
    			table[j][k] = line.c_str()[k];
    		} // end reading each element in a line
    	} // End reading all rows
    	std::getline( input, line ); // space between cases

    	result = getTableStatus( table );
    	std::cout<<"Result for "<<i<<": "<<result<<std::endl;
    	output << "Case #"<<i+1<<": "<<result<<std::endl;

    } // End reading T cases


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
std::string getTableStatus( char table[][4] ) {

	std::string result;


	// Check if somebody won in row or column
	char rowOption[4];
	char columnOption[4];
	char diag1Option[4];
	char diag2Option[4];

	for( int i = 0; i < 4; ++i ) {
		for( int j = 0; j < 4; ++j ) {
			rowOption[j] = table[i][j];
			columnOption[j] = table[j][i];
		}

		if( checkWinner( rowOption, result ) == true ) { return result; }
		if( checkWinner( columnOption, result ) == true ) {return result; }
	}


	// Check diagonals
	for( int i = 0; i < 4; ++i ) {
			diag1Option[i] = table[i][i];
			diag2Option[i] = table[i][3-i];
	}

	if( checkWinner( diag1Option, result ) == true ) { return result; }
	if( checkWinner( diag2Option, result ) == true ) { return result; }

	// Check if it is not over yet
	for( int i = 0; i < 4; ++i ) {
		for( int j = 0; j < 4; ++j ) {
			if( table[i][j] == '.' ) { return std::string( "Game has not completed" );}
		}
	}

	// If it is over, then draw
	return std::string( "Draw" );

}

bool checkWinner( char row[], std::string &_result ) {


	if( row[0] == row[1] && row[0] == row[2] && row[0] == row[3] ) {
		if( row[0] == 'X') { _result = std::string("X won"); return true; }
		else if( row[0] == 'O') { _result = std::string("O won"); return true; }

	}

	if( row[1] == 'T' &&  row[0] == row[2] && row[0] == row[3] ) {
		if( row[0] == 'X') { _result = std::string("X won"); 	return true; }
		else if( row[0] == 'O') { _result = std::string("O won"); 	return true; }

	}

	if( row[2] == 'T' &&  row[0] == row[1] && row[0] == row[3] ) {
		if( row[0] == 'X') { _result = std::string("X won"); 	return true; }
		else if( row[0] == 'O') { _result = std::string("O won"); 	return true; }
		}

	if( row[3] == 'T' &&  row[0] == row[1] && row[0] == row[2] ) {
		if( row[0] == 'X') { _result = std::string("X won"); 	return true; }
		else if( row[0] == 'O') { _result = std::string("O won"); 	return true; }
		}

	if( row[0] == 'T' &&  row[1] == row[2] && row[1] == row[3] ) {
		if( row[1] == 'X') { _result = std::string("X won"); 	return true; }
		else if( row[1] == 'O') { _result = std::string("O won"); 	return true; }
		}

	_result = std::string( "Ridiculous" );
	return false;
}
