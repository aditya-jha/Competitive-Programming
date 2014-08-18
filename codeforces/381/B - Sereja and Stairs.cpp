#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

#define node pair<int,int>

int main() {
	ios_base::sync_with_stdio(0);
	
	int m,temp;
	cin>>m;
	
	int a[5001];
	for(int i=0;i<5001;i++) a[i]=0;
		
	for(int i=0;i<m;i++) {
		cin>>temp;
		a[temp]++;
	}
	
	int maxi;
	for(int i=5000;i>0;i--) {
		if(a[i]>0) {
			maxi = i;
			break;
		}
	}
	
	vector<int> f,s;
	for(int i=1;i<maxi;i++) {
		if(a[i]!=0) {
			if(a[i]>1) {
				f.push_back(i); s.push_back(i);
			} else f.push_back(i);
		}
	}
	
	cout<<f.size()+s.size()+1<<'\n';
	
	for(int i=0;i<s.size();i++) cout<<s[i]<<" ";
	cout<<maxi<<" ";
	for(int i=f.size()-1;i>-1;i--) cout<<f[i]<<" ";
	
	
	cout<<'\n';
	
	return 0;
}
