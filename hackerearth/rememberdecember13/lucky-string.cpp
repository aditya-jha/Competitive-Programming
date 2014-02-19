#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

unsigned long long sum[17],val=1;

int main() {
	ios_base::sync_with_stdio(0);
	
	sum[0]=0;
	for(int i=1;i<17;i++) {
		val*=2;
		sum[i] = val*i+sum[i-1];
	}
	for(int i=0;i<17;i++) cout<<sum[i] <<" ";
	cout<<endl;
	int t,n,index,coun;
	cin>>t;
	
	while(t--) {
		cin>>n;
		index=0;
		if(n<3) index = 1;
		else {
			while(sum[index]<n) index++;
		}
		n = n-sum[index-1];		
		
		long long total = sum[index]-sum[index-1];
		
		while(total!=1) {
			if(n>=total/2) {
				n = n-n/2;
				total = n/2;
			} else total = n/2;
		}
		
		if(n<=index) cout<<"Hacker\n";
		else cout<<"Earth\n";
	}
	
	return 0;
}
