#ifndef RAC_PARPROG_WS2014_GB_MATRIX_H
#define RAC_PARPROG_WS2014_GB_MATRIX_H

#include <vector>

/* Simple matrix class, for use in exercises

   Author: Guntram Berti, 2014-10-21
  
   2018-04-30: Added num_rows() / num_cols()

   Usage: Point compiler to location of this file using -I/path/to/directory
 */

namespace gb {
  
  class matrix {
    std::vector<double> x;
    int nrows, ncols;
  public:
    matrix() : nrows(0), ncols(0) {}
    matrix(int n) : nrows(n), ncols(n)
    { init(); }
    matrix(int nrows, int ncols) : nrows(nrows), ncols(ncols)
    { init(); }
    matrix(int nrows, int ncols, double v) : nrows(nrows), ncols(ncols)
    { init(v); }

    double  operator()(int i, int j) const { return x[i*ncols + j]; }
    double& operator()(int i, int j)       { return x[i*ncols + j]; }
    int num_rows() const { return nrows;}
    int num_cols() const { return ncols;}
  private:
    void init()      { x.resize(nrows*ncols); }
    void init(double v) {
      std::vector<double> newx(nrows*ncols,v);
      x.swap(newx);
    }
  };

}

#endif
