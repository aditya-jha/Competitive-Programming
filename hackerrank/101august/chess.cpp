#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	int t,n;
	cin>>t;
	while(t>0) {
		cin>>n;
		int a[n], b[n], count = 0;
		for(int i=0; i<n; i++) cin>>a[i];
		for(int i=0; i<n; i++) cin>>b[i];

		int i=0;
		while(i<n) {
			if(count%2==0) {
				while(i<n) {
					if(b[i]-a[i]!=1 or b[i]-a[i]!=-1) { count++; i++; break; }
					i++;
				}
			} else {
				while(i<n) {
					if(b[i]-a[i]!=1 or b[i]-a[i]!=-1) { count++; i++; break; }
					i++;
				}
			}
		}		

		if(count%2==0) printf("player-1\n");
		else printf("player-2\n");
		t--;
	}
	return 0;
}
