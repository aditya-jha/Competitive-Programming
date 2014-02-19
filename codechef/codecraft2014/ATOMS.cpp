#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

const long long maxn = 1e18;

int main() {

	ios_base::sync_with_stdio(0);

	int t,i;
	cin>>t;
	//t = scan_d();
	
	long long n,m,k,temp;
	
	while(t--) {
		cin>>n>>k>>m;
		//n = scan_lld(); k = scan_lld(); m = scan_lld();
		
		if(m<n) {
			cout<<"0\n";
			continue;
		}
		temp = m/n;
		/*
		for(i=1;k<=temp;i++) {
			k*=k;
		}
		*/
		cout<<(int)(log10(temp)/log10(k))<<'\n';
	}
	
	return 0;
}
