#include<stdio.h>

long long int gcd(long long int a, long long int b) {
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main() {
	long int t;
	scanf("%ld",&t);
	while(t--) {
		long long int N,M;
		scanf("%lld %lld",&N,&M);
		
		if(N==1) printf("%lld\n",M);
		else if(M==1) printf("%lld\n",N);
		else if(N==M) printf("%lld\n",N);
		else {
			if(N>M) printf("%lld\n",1+gcd(N-1,M-1));
			else printf("%lld\n",1+gcd(M-1,N-1));
		}
			
	}
	return 0;
}
