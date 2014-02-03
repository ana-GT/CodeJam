#include <iostream>

int main( int argc, char* argv[] ) {

  int p1, p2, pn;
  int sum;

  p1 = 1;
  p2 = 2;

  sum = 2; /**< Init with first even-valued term */
  for(;;) {
    
    pn = p1 + p2;
    if( pn > 4000000 ) { break; }

    if( pn % 2 == 0 ) { sum += pn; }    

    p1 = p2;
    p2 = pn;    
  }

  std::cout << "Sum of even-valued Fibonacci numbers less or equal than four millions is: "<< sum<< " and by the way, the last considered number (not necessarily added)  was: "<< pn <<std::endl;

  return 0;
}
