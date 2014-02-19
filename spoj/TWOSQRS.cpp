#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	
	int t,count,flag;
	cin>>t;
	
	long long n,i;
	
	while(t--) {	
		cin>>n;
		flag=1;
		for(i=2;i*i<=n;i++) {
			count = 0;
			while(n%i==0) {
				count++;
				n = n/i;
			}
			if(count%2==1 and i%4==3) {
				flag = 0;
				break;
			}
		}
		if(n%4==3) flag = 0;
		
		if(flag) cout<<"Yes\n";
		else cout<<"No\n";
	}	
	
	return 0;
}
