/**
 * @file credit.cpp
 * @brief Quick-start practice of CodeJam 2010
 * @author A. Huaman Q.
 * @date 2013/12/11
 */
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

/**
 * @function main
 */
int main( int argc, char *argv[] ) {

	if( argc != 2 ) {
		std::cout << "Enter the filename as argument!" << std::endl;
		return -1;
	}

	int N;
	int C;
	int I;
	int p;
	std::vector<int> P;

	std::ifstream input;
	std::ofstream output;

	input.open( argv[1], std::ios::in );
	output.open( "testOutput.txt", std::ios::out );

	if( input.is_open() ) {

		// Get the number of cases N:
		input >> N;
		// For each case
		for( int i =0; i < N; ++i ) {
			input >> C;
			input >> I;
			P.resize(0);

			for( int j = 0; j < I; ++j ) {
				input >> p;
				P.push_back(p);
			}

			// Get the result
			int p1, p2;
			bool found = false;

			for( int k = 0; k < I-1; ++k ) {
				p1 = P[k];
				if( p1 > C ) { continue; }

				for( int m = k+1; m < I; ++m ) {
					p2 = P[m];
					if( p2 > C ) { continue; }
					if( p1 + p2 == C ) {
						output << "Case #"<<i+1<<": "<<k+1<<" "<<m+1<<"\n";
						found = true; break;
					}
				}
				if(found) {break;}
			}
		}
	} // end if



	input.close();
	output.close();

	std::cout<<"Credit problem ended!"<< std::endl;

	return 0;
}
