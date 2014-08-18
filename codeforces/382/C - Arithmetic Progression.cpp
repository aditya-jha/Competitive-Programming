#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	
	int n;
	cin>>n;
	
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	
	if(n==1) {
		cout<<"-1\n";
		return 0;
	}	
	
	
	
	sort(a,a+n);
	
	int diff[n],con=0;
	
	diff[0] = 0;
	
	for(int i=1;i<n;i++) {
		diff[i] = a[i] - a[i-1];
	}
	
	sort(diff+1,diff+n);
	
	int temp = diff[1],index=1;
	
	for(int i=2;i<n;i++) {
		if(diff[i] != temp) {
			temp = diff[i];
			con++;
			index = i;
		}
	}
	
	if(con>1) {
		cout<<"0\n";
		return 0;
	}
	if(con == 0) {
		cout<<"2\n";
		cout<<a[0]-temp<<" "<<a[n-1]+temp<<"\n";
	}
	else {
		temp = (a[index] + a[index-1])/2;
		if(temp-a[index-1] == a[index]-temp) {
			cout<<"1\n"<<temp<<"\n";
		}
	}
	
	return 0;
}
