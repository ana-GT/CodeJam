/**
 * @file alienLanguage.cpp
 * @author A. Huaman
 */
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

int main( int argc, char* argv[] ) {

	std::ifstream input;
	std::ofstream output;
	std::string line;
	std::vector<std::string> vocab;

	int L, D, N;

	if( argc != 2 ) {
		std::cout << "Syntax: "<<argv[0]<<" "<<argv[1] << std::endl;
		return -1;
	}

	input.open( argv[1], std::ios::in );
	output.open( "alienResults.txt", std::ios::out );

	if( input.is_open() ) {

		// Get L, D and N
		std::getline( input, line );
		std::stringstream( line ) >> L >> D >> N;
		std::cout << "L:" << L << " D: "<< D << " N: "<< N << std::endl;

		// Get the D words
		vocab.resize(D);
		for( int i = 0; i < D; ++i ) {
			std::getline( input, line );
			vocab[i] = line;
		}

		// Get the test cases
		for( int i = 0; i < N; ++i ) {
			std::getline( input, line );
			output << "Case #"<<i+1<<": "<<line<< std::endl;
		}

	} else {
		std::cout << "Error opening file "<< std::endl;
		return -1;
	}

	for(int i = 0; i < D; ++i ) {
		std::cout << vocab[i] << std::endl;
	}

	input.close();
	output.close();

	std::cout << "Alien language "<< std::endl;

	return 0;
}
