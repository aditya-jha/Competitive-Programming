#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int n,k;
int a[1000010];

int main() {
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	
	long long counter=0;
	for(int i=0;i<n;i++) {
		int index = 1;
		double sum = a[i];
		if(sum>=k) {
			counter++;
			//cout<<sum<<endl;
		}
		for(int j=i+1;j<=n;j++) {
			index++;
			sum += a[j];
			if((sum/index)>=k) {
				counter++;
				//cout<<i<<" "<<j<<endl;
			}
		}
	}
	
	cout<<counter<<'\n';
	
	return 0;
}
	
