#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int maxn=101;

bool graph[maxn][maxn];
int n,m;

bool bpm(int u, bool seen[], int matchR[]) {
	for (int v = 1; v <= n; v++) {
		if (graph[u][v] && !seen[v]) {
			seen[v] = true;
		
			if (matchR[v] < 0 || bpm(matchR[v], seen, matchR)) {
				matchR[v] = u;
				return true;
			}
		}
	}
	
	return false;
}

int maxBPM() {
	int matchR[n+1];
	memset(matchR, -1, sizeof(matchR));
	
	int result = 0;
	
	for (int u = 1; u <= n; u++) {
		bool seen[n+1];
		memset(seen, 0, sizeof(seen));
 

		if (bpm(u, seen, matchR)) result++;
	}

	for(int i=1;i<=n;i++) cout<<matchR[i]<<" ";
	cout<<endl;
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	
	int t,a,b,sol;
	cin>>t;
	
	while(t--) {
		cin>>n>>m;
		
		for(int i=0;i<=n;i++) 
			for(int j=0;j<=n;j++) graph[i][j]=0;
		
		for(int i=0;i<m;i++) {
			cin>>a>>b;
			graph[a][b] = true;
			graph[b][a] = true;
		}		
		
		if(n%2 != 0) { cout<<"NO\n"; continue; }
		if(m<(n/2)) { cout<<"NO\n"; continue; }
		
		sol = maxBPM();
		
		if(n==sol) cout<<"YES\n";
		else cout<<"NO\n";
		
	}
	
	return 0;	
}
