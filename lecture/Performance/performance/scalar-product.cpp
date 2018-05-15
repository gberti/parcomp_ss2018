#include <iostream>
#include <vector>
#include <omp.h>

double scalar_product(double * a, double * b, int nelems)
{

  double sum = 0.0;
  std::vector<double> local_sum;
  #pragma omp parallel
  {
    int nt = omp_get_num_threads();
    #pragma omp master
      local_sum.resize(nt);
    #pragma omp barrier
    int tid = omp_get_thread_num();
    local_sum[tid] = 0;
    
    #pragma omp for 
    for(int i = 0; i < nelems; ++i) {
      local_sum[tid] += a[i]*b[i];
    }
  }
  for(int i = 0; i < local_sum.size(); ++i)
    sum += local_sum[i];
  
  return sum;
}


int main()
{
  const int N = 100000;
  double a[N], b[N];
  for(int i = 0; i < N; ++i) {
    a[i] = b[i] = 1;
  }

  double sum = scalar_product(a,b,N);

  std::cout << "sum = " << sum << std::endl;
}
