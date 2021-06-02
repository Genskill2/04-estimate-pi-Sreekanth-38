#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>




int main(void) {
  float pi;
  for (int i=0; i<5; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) > 0.15)) {
      printf("Estimate with just %d iterations is %f which is too accurate.\n", i, pi);
      abort();
    }
  }

  for (int i=500; i<3000; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) < 0.01)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi);
      abort();
    }
  }
}
float wallis_pi(int x){
float pi =1.0;
int i=1;
float num=2, den =1.0;
for(i=1; i<=x; i++)
{
	pi*=(num/den);
	((i%2)==1)?(den+=2.0L):(num+=2.0L);
}
return pi*= 2.0;
}
