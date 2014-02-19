#include<iostream>
#include<cstdio>

using namespace std;

#define MOD 1000000007

int t,m,n;

int matrix(int m, int n) {
	int dp[m][n];
	
	for(int i=0;i<m;i++) {
		dp[i][0] = 1;
	}
	for(int i=0;i<n;i++) dp[0][i] = 1;
		
	for(int i=1;i<m;i++) {
		for(int j=1;j<n;j++) {
			dp[i][j] = (int)((long long)dp[i-1][j]+(long long)dp[i][j-1])%MOD;
		}
	}
	
	return dp[m-1][n-1];
}

int main() {
	ios_base::sync_with_stdio(0);	
	
	cin>>t;
	
	while(t--) {
		cin>>m>>n;
		cout<<matrix(m,n)<<'\n';
	}
	
	return 0;
}
