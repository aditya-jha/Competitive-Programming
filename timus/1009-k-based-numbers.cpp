#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

long long int dp[20][2];
int k;

long long int sol(int n,int z) {
	if(z==2) return 0;
	if(n==1) {
		if(z==1) return k-1;
		else return k;
	}

	long long &ans = dp[n][z];

	if(ans==-1) {
		if(z==1) ans=0;
		else ans=sol(n-1,1);
		ans += (k-1)*sol(n-1,0);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);

	int n;
	long long a;

	cin>>n>>k;
	memset(dp,-1,sizeof(dp));
	
	a = (k-1)*sol(n-1,0);

	cout<<a<<endl;
	return 0;
}
