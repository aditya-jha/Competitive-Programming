#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int n,m,l,a,b;
int mat[501][501];
long long E1,E2;

int main() {
	ios_base::sync_with_stdio(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) cin>>mat[i][j];
	}
	
	cin>>l;
	E1=0; E2=0;
	while(l--) {
		cin>>a>>b;
		
		if(E1==-1 and E2==-1) continue;
		
		if( E1 != -1) if(a<=n and b<=m) E1 += mat[a][b];
		else E1 = -1;
		
		if( E2 != -1) if(a<=m and b<=n) E2 += mat[b][a];
		else E2 = -1;
		
	}
	
	cout<<max(E1,E2)<<'\n';
	
	return 0;
}
