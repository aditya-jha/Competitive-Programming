#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	
	int n;
	cin>>n;
	
	int a[n];
	
	for(int i=0;i<n;i++) cin>>a[i];
	
	int s=0,l=n-1;
	int sereja=0,duma=0;
	
	for(int i=0;i<n;i++) {
		if(i%2==0) {
			if(a[s]>a[l]) { sereja += a[s]; s++; }
			else { sereja += a[l]; l--; }
		}
		else {
			if(a[s]>a[l]) { duma += a[s]; s++; }
			else { duma += a[l]; l--; }
		}
	}
	
	cout<<sereja<<" "<<duma<<'\n';
	
	return 0;
}
