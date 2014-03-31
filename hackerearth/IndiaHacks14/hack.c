#include <stdio.h>
#define ll long long
#define m 1000000007
#defin s(a) scanf("%lld",&a)

ll t,n,x,y,z;

/* function that returns nth Fibonacci number */
ll fib() {
    int F[2][2] = {{2014,69},{1,0}};
    power(F, n-1);
    return F[0][0];
}
 
/* Optimized version of power() in method 4 */
void power(int F[2][2], int n) {
    if(n == 0 || n == 1) return;
    int M[2][2] = {{2014,69},{1,0}};
    power(F, n/2);
    multiply(F, F);
    if (n%2 != 0) multiply(F, M);
}
 
void multiply(int F[2][2], int M[2][2]) {
    x=(F[0][0]*M[0][0] + F[0][1]*M[1][0])%m;
    y=(F[0][0]*M[0][1] + F[0][1]*M[1][1])%m;
    z=(F[1][0]*M[0][0] + F[1][1]*M[1][0])%m;
    w=(F[1][0]*M[0][1] + F[1][1]*M[1][1])%m;
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

int main() {      
      s(t);
      while(t--) {
          s(n);
          printf("%d\n",fib(n));
      }    
  return 0;
}
