/**< Special Pythagorean Triplet */
#include <iostream>
#include <math.h>

int main( int argc, char* argv[] ) {

  int c; int a; int b;
   
  int maxC = 707; // sqrt(1000^2/2)
  int y; int x;
  int dis;

  for( c = maxC; c >= 1; --c ) {
  
      y = 1000 - c;
      x = c*c;
      
      dis = 2*x - y*y;
      if( dis < 0  ) { continue; }

      a = ( y + sqrt( dis ) ) / 2; 
      b = y - a;
      if( a <= 0 || b <= 0 ) { continue; }
      if( a*a + b*b == c*c ) { break; }

      a = ( y - sqrt(dis) ) / 2;
      b = y -a;
      if( a <= 0 || b <= 0 ) { continue; }
      if( a*a + b*b == c*c ) { break; }

  }

  std::cout << "Number a, b and c are: "<<a<<", "<<b<<", "<<","<<c<<std::endl;
  std::cout << "And their product is: "<<a*b*c<<std::endl;
  return 0;
}
