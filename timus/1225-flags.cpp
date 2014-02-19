#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

long long int dp[50];

long long int solve(int n) {
	if(n<0) return 0;
	if(n==0) return 1;
	
	long long int &ret = dp[n];

	if(ret==-1) ret = solve(n-1)+solve(n-2);
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	cout<<2*solve(n-1)<<'\n';
	//putchar('\n');
	return 0;
}
