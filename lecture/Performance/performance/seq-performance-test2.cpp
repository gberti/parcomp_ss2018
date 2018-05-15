#include <iostream>
#include <stdlib.h>
//#include <boost/lexical_cast.hpp>


inline double sq(double x) { return x*x; }

int main(int argc, const char* argv[])
{
  int N     = 1000;
  int Nruns = 1000000;
  if(argc > 1) {
    N = atoi(argv[1]); //boost::lexical_cast<int>(argv[1]);
  }
  
  double * a = new double[N];
  for(int i = 0; i < N; ++i)
    a[i] = i;

  double sum = 0;
  for(int k = 0; k < Nruns; ++k) {
    double kx = k;
    for(int i = 0; i < N; ++i)
      sum += sq(a[i] + kx);
  }

  std::cout << sum << std::endl;
  
  return 0;
}
