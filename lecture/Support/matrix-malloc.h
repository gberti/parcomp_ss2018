#ifndef RAC_PARPROG_WS2014_GB_MATRIX1_H
#define RAC_PARPROG_WS2014_GB_MATRIX1_H

#include <stdlib.h>

/* Simple matrix class, for use in exercises.
   Uses malloc instead of C++ vector class.

   Author: Guntram Berti, 2014-10-21
  
   2018-04-30: Added num_rows() / num_cols()

   Usage: Point compiler to location of this file using -I/path/to/directory
*/

namespace gb {

  namespace experimental {
  
    class matrix {
      double * x;
      int nrows, ncols;
    public:
    matrix() : nrows(0), ncols(0) { x = NULL;}
    matrix(int n) : nrows(n), ncols(n)
      { init(); }
    matrix(int nrows, int ncols) : nrows(nrows), ncols(ncols)
      { init(); }
    matrix(int nrows, int ncols, double v) : nrows(nrows), ncols(ncols)
      { init(v); }
    
      ~matrix() { free(x); x = NULL; }
      double  operator()(int i, int j) const { return x[i*ncols + j]; }
      double& operator()(int i, int j)       { return x[i*ncols + j]; }
      int num_rows() const { return nrows;}
      int num_cols() const { return ncols;}
    private:
      void init()      { x = (double*) malloc(nrows*ncols*sizeof(double)); }
      void init(double v) {
	init();
	for(int i = 0; i < nrows*ncols; ++ i)
	  x[i] = v;
      }
    };
  }
}

#endif
