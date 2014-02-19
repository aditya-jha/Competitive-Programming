#include<iostream>
#include<cstdio>
#include<string.h>
#include<vector>
#include<cmath>
using namespace std;

bool inprimes[100001];
vector<int> v;

void sieve() {
	memset(inprimes,true,sizeof(inprimes));
	inprimes[0]=inprimes[1]=false;
	
	for(int i=2;i<100001;i++) 
		if(inprimes[i])
			for(int j=i+i;j<100001;j+=i) 
				inprimes[j]=false;
}

int main() {
	int t;
	long long int m,n,i,j,k,exp;
	sieve();
	scanf("%d",&t);
	while(t--) {
		scanf("%lld %lld",&m,&n);
		if(n<100001) {
		}
		else {
			bool fiprimes[n-m+1];
			memset(fiprimes,true,sizeof(fiprimes));
			
			for(i=2;i*i<=n;i++) {
				if(inprimes[i]) {
					k=m/i;
					if(i*k<m)k++;
					for(j=i*k;j<=n;j+=i) fiprimes[j-m]=false;
				}
				for(i=0;i<n-m+1;i++)
					if(fiprimes[i]) printf("%lld\n",i+m);
			}
		}	

	}
	
	return 0;
}
