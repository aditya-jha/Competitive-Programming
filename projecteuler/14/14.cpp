#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

#define max(a,b) (a>b?a:b)

int dp[2000001];

int collatz(long long int n) {
	if(n<2000000) {
		if(dp[n]>0) return dp[n];
		else {
			if(n%2==0) {
				dp[n]=1+collatz(n/2);
				return dp[n];
			} else {
				dp[n]=1+collatz(3*n+1);
				return dp[n];
			}
		}
	} else {
		if(n%2==0) return 1+collatz(n/2);
		return 1+collatz(3*n+1);
	}
}

int main() {
	memset(dp,0,sizeof(dp));
	dp[0]=0;dp[1]=1;dp[2]=2;dp[4]=3;dp[8]=4;dp[16]=5;
	
	int maxm=1,ind;
	for(long long int i=3;i<1000000;i++) {
		dp[i] = collatz(i);
		if(dp[i]>maxm) {
			maxm=dp[i];
			ind=i;
		}
	}
	cout<<ind<<endl;
	
	return 0;
}

