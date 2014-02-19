#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<string.h>
#include<cstring>
#include<stack>
#include<queue>
#include<cassert>
#include<cmath>
#define min(a,b) (a>b?b:a)

using namespace std;

long long int fact(long int n) {
	if(n==0) return 1;
	long long int fa=1;
	for(int i=1; i<=n; i++) { fa*=i; fa = fa%1000000007; }
	
	return fa;
}

int main() {
	long int t,n,m,k;
	scanf("%ld",&t);
	while(t--) {
		scanf("%ld %ld %ld",&n,&m,&k);
		long int r = (k+1)*m;
		long long int num = 1,mul=fact(m);
		if(r>(n-r)) {
			long long int den = fact(n-r);
			for(int i=n; i>r; i--) { num*=i; num = num%1000000007; }
			long long int ncr = num/den;
			printf("%lld\n",(ncr*mul)%1000000007);	
		} else {
			long long int den = fact(r);
			for(int i=n; i>(n-r); i--) { num*=i; num = num%1000000007; }
			long long int ncr = num/den;
			printf("%lld\n",(ncr*mul)%1000000007);
		}

	}
}
	
