#include<iostream>
#include<cstdio>

using namespace std;

#define MOD 1000000007

int dp[10000][10000];
int t,m,n;

void matrix() {
	//int dp[m][n];
	
	for(int i=0;i<10000;i++) {
		dp[i][0] = 1;
		dp[0][i] = 1;
	}
	
	for(int i=1;i<10000;i++) {
		for(int j=1;j<10000;j++) {
			dp[i][j] = (int)((long long)dp[i-1][j]+(long long)dp[i][j-1])%MOD;
		}
	}
	
	//return dp[m-1][n-1];
}

int main() {
	ios_base::sync_with_stdio(0);
	matrix();
	
	
	cin>>t;
	
	while(t--) {
		cin>>m>>n;
		cout<<dp[m-1][n-1]<<'\n';
	}
	
	return 0;
}
