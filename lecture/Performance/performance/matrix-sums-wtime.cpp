
#include "../../support/matrix.h"

#include <stdlib.h>
//#include <boost/lexical_cast.hpp>
#include <iostream>

#include <omp.h>

int main(int argc, const char* argv[])
{
  int N = 1000;
  if(argc > 1)
    N    = atoi(argv[1]); //boost::lexical_cast<int>(argv[1]);
  int mode = 0;
  if(argc > 2)
    mode = atoi(argv[2]); //boost::lexical_cast<int>(argv[2]);

  // output resolution of omp clock
  double secs_per_clock_tick = omp_get_wtick();
  std::cout << "clock resolution: " << secs_per_clock_tick << " s" << std::endl;

  double t_init, t_alloc = 0;
  double t0 = omp_get_wtime();
  gb::matrix M(N,N);
  double t1 = omp_get_wtime();
  t_alloc = t1-t0;
  
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++)
      M(i,j) = 1.0;
  }
  
  double rowsum[N];
  for(int i = 0; i < N; i++) 
      rowsum[i] = 0.0;
  double t2 = omp_get_wtime();
  t_init = t2-t1;

  
  double t_loop = 0;
  if(mode == 1) { 
    double t_start = omp_get_wtime();    
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++)
	rowsum[i] += M(i,j);
    }
    t_loop = omp_get_wtime() - t_start;
  }
  if(mode == 2) {
    double t_start = omp_get_wtime();    
    for(int j = 0; j < N; j++) {
      for(int i = 0; i < N; i++)
	rowsum[i] += M(i,j);
    }
    t_loop = omp_get_wtime() - t_start;
  }

  std::cout << "rowsum[0] = " << rowsum[0] << "\n"
	    << "time used for row sum:    " << t_loop << "\n"
	    << "time used for allocation: " << t_alloc << "\n"
	    << "time used for init:       " << t_init << "\n"
	    << "time init + alloc:        " << t_alloc+t_init << "\n"
	    << std::endl;
  
  return 0;
}
