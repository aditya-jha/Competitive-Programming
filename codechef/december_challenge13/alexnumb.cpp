#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int t,n,tem;
	unsigned long long int counter;
	cin>>t;
	while(t--) {
		vector<int> v;
		counter=0;
		cin>>n;
		for(int i=0;i<n;i++) {
			cin>>tem;
			v.push_back(tem);
		}

		//n--;
		//count = (n*(n+1))/2;
		
		for(int i=1;i<n;i++) counter+=(n-i);

		cout<<counter<<'\n';
	}
	return 0;
}
