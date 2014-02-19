#include<iostream>
#include<cstdio>

#define MOD 1000000007

using namespace std;

long long int factorial(long int n) {
	long long int f = 1;
	while(n>1) {
		f = f*n;
		if(f>=MOD) f = f%MOD;
		n--;
	}
	return f%MOD;
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		long int n,m,q,k;
		scanf("%ld %ld %ld %ld",&n,&m,&q,&k);
		
		/*
		long int min = 1, max = q+min;
		long long int count = 0;
		
		while(max<=m) {
			count++;
			min++;
			max++;
		}
		*/
	//	if(count>0) {
			printf("%lld\n",((m-q)*factorial(n))%MOD);	
	//	} else printf("0\n");
	
	}
	return 0;
}

