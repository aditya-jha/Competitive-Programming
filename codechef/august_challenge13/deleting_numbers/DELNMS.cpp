#include<iostream>
using namespace std;

int main() {
	int n;	
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	cout<<n<<endl;
	for(int i=n; i>0; i--) cout<<i<<" 1\n";
	return 0;
}
