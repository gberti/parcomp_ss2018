
#include "../../support/matrix.h"

#include <stdlib.h>
//#include <boost/lexical_cast.hpp>
#include <iostream>

#include <time.h>


int main(int argc, const char* argv[])
{
  int N = 1000;
  if(argc > 1)
    N    = atoi(argv[1]); //boost::lexical_cast<int>(argv[1]);
  int mode = 0;
  if(argc > 2)
    mode = atoi(argv[2]); //boost::lexical_cast<int>(argv[2]);

  struct timespec tm;
  clock_gettime(CLOCK_REALTIME, &tm);
  
  gb::matrix M(N,N, 1.0);
  double rowsum[N];
  for(int i = 0; i < N; i++) 
      rowsum[i] = 0.0;

  if(mode == 1) { 
    
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++)
	rowsum[i] += M(i,j);
    }
  }
  if(mode == 2) {     
    for(int j = 0; j < N; j++) {
      for(int i = 0; i < N; i++)
	rowsum[i] += M(i,j);
    }
  }

  std::cout << "rowsum[0] = " << rowsum[0] << std::endl;
  
  return 0;
}
