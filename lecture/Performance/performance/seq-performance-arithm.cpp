#include <iostream>
#include <stdlib.h>
//#include <boost/lexical_cast.hpp>


void dummy(double *a, double* b); 

// call with program Nruns type 
int main(int argc, const char* argv[])
{
  int N     = 1000*1000*10;
  int Nruns = 10;
  if(argc > 1) {
    Nruns = atoi(argv[1]); //boost::lexical_cast<int>(argv[1]);
  }
  int type = 0;
  if(argc > 2) {
    type = atoi(argv[2]); //boost::lexical_cast<int>(argv[2]);
  }
  int print_i = 0;
  if(argc > 3) {
    print_i = atoi(argv[3]); //boost::lexical_cast<int>(argv[3]);
  }
  

  double * a = new double[N];
  double * b = new double[N];
  for(int i = 0; i < N; ++i) {
    a[i] = 1.0/(i+1);
    b[i] = 1.0/(i+2);
  }

  if(type == 1) {
    for(int k = 0; k < Nruns; ++k) {
      for(int i = 0; i < N; ++i) {
	double y = b[i];
	a[i] += y*3.0;
      }
      dummy(a,b);
    }
  }
  else if(type == 2) {
    double _1_6 = 1.0/6, _1_3 = 1.0/3;
    for(int k = 0; k < Nruns; ++k) {
      for(int i = 0; i < N; ++i) {
	double y = b[i];
	// -O3: (a) takes 2.5 times as long as (a2), (b) or (c)
	// -Ofast: (a) takes same time as the other cases
	// this case (type==2) with b or c takes as long as type==1 
        // a[i] +=  y*y*y*4.5 - y*y/6.0 + y/3.0  + 0.1; //(a)
	// a[i] +=  y*y*y*4.5 - y*y*_1_6 + y*_1_3 + 0.1; //(a2)	
	// a[i] +=              y*y*6.0 + y*3.0 + 0.1; //(b)
	// a[i]    +=  y*y*y*4.5 - y*y*6.0 + y*3.0 + 0.1; //(c)
	a[i] +=  y*y*(1-y)*y*0.1 + y*y*y*4.5 - y*y/6.0 + y/3.0  + 0.1; // (d)
      }
      dummy(a,b);
    }
  }
  else {
    std::cout << "type " << type << ": no action" << std::endl;
  }
  
  std::cout << a[print_i] << std::endl;
  
  return 0;
}
