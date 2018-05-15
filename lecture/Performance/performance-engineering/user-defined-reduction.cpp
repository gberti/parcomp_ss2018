
#include <iostream>
#include <float.h>

double my_min(double x, double y) 
 { return (x <= y ? x : y); }

#pragma omp declare reduction \
  (mymin : double : omp_out = my_min(omp_out, omp_in)) \
  initializer(omp_priv=double(DBL_MAX))



int main()
{
  const int N = 100;
  double a[N];
  for(int i = 0; i < N; ++i) {
    a[i] = N-i;
  }
  double x = a[0];
  #pragma omp parallel for reduction(mymin: x) 
  for (int i = 0 ; i < N; ++i ) { 
    x = my_min(x,  a[i]);
  }

  std::cout << "min = " << x << std::endl;

  return 0;
}
