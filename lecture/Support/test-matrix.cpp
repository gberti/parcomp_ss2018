

#include "matrix.h"
#include <cassert>


int main() {

  int N = 5;
  gb::matrix M(N);
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      M(i,j) = i*N+j;

   for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      assert( M(i,j) == i*N+j);
}
