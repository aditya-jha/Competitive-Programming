#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define llu long long unsigned

bool prime[100010];
llu count;

void sieve() {
    for(int i=0;i<100010;i++) prime[i] = true;
    
    prime[0] = prime[1] = false;
    
    int lim = ceil(sqrt(100010));
	for(int i=2;i<=lim;i++) {
		if(prime[i]) {
			for(int j=i*i;j<=n;j+=i) { //i*i may not be able to hold int, check will solving questions
				primes[j]=false;				
			}
		}
	}
}    

llu modexp(llu x, llu y, llu MOD) {
	if(y==0) return 1;
	
	llu z = modexp(x,y/2,MOD);
	llu tt;
	
	if(y%2==0) {
	    tt = z*z;
	    count += tt/MOD;
        return tt%MOD;
        //return (((x*z)%MOD)*z)%MOD;
	}	    
	else {
	    tt = x*z;
	    count += tt/MOD;
	    tt = (tt%MOD)*z;
	    count+=tt;
	    return tt%MOD;
	}	
}

void factors(int n, int p)  {
    int count = 0;
    while(n>=p) {
        n = n/p;
        count += n; 
    }    
    return count;
}    

vector<llu> v;

void solve(int n, llu b) {
    int *dp = dp[n+1];
    dp[0] = dp[1] = 1;
    count = 0;
    
    for(int i=2;i<=n;i++) {
        if(prime[i]) dp[i] = factors(n,i);
        else dp[i] = 0;
    }    
    
    for(int i=2;i<=n;i++) {
        if(dp[i]>0) v.push_back(modexp(i,dp[i],b));
    }    
    
    
}    
