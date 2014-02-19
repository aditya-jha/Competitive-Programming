#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int a[100001],b[100001];

int main() {
	ios_base::sync_with_stdio(0);
	
	int n,x,y;
	cin>>n;
		
	for(int i=0;i<100001;i++) a[i] = b[i] = 0;
		
	for(int i=0;i<n;i++) {
		cin>>x>>y;
		a[x]++;
		b[y]++;
	}	
		
	int moves = 1e9;
	for(int i=0;i<100001;i++) {
		if(a[i]>=(n-n/2)) moves=0;
		else if(a[i]+b[i]>=(n-n/2)) {
			int req = (n-n/2) - a[i];
			moves = min(moves,req);
		}
	}
	
	if(moves == 1000000000) cout<<"Impossible\n";
	else cout<<moves<<'\n';
	
	return 0;
}
