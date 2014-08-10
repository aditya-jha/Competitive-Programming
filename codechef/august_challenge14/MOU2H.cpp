#include<iostream>
#include<cstdio>

using namespace std;

const int maxn = 4000000;
const int mod = 1000000009;

int n;
int a[1000001], dp[8000001];

int main () {
    ios_base::sync_with_stdio(0);
    
	int t,d;
	cin>>t;
	
	for(int i=0;i<8000001;i++) dp[i] = 0;
	
	while (t--) {
		cin>>n>>d;
		
		for (int i=1; i<n; i++) {
			cin>>a[i-1];
			a[i-1] = a[i-1] - d;
			d = a[i-1] + d;
		}
		
		int ans = 0;
		
		for (int i=0; i<(n-1); i++) {
			int temp = dp[a[i] + maxn];
			dp[a[i] + maxn] = (ans+1)%mod;
			ans = (ans + (dp[a[i] + maxn] - temp)%mod)%mod;
		}
		
		for (int i=0; i<(n-1); i++) {
			dp[a[i] + maxn] = 0;
		}
		
		ans += mod;
		
		cout<<ans%mod<<"\n";
	}
	
	return 0;
}
