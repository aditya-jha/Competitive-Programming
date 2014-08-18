#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	
	int m,l,c;	
	long long n,action;
	vector<int> v;
	
	cin>>m;
	
	for(int i=0;i<m;i++) {
		cin>>action;
		if(action==1) {
			cin>>l;
			v.push_back(l);
		} else {
			cin>>l>>c;
			for(int j=0;j<c;j++) {
				for(int p=0;p<l;p++) {
					v.push_back(v[p]);
				}
			}
		}
	}
	
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>action;
		cout<<v[action-1]<<" ";		
	}
	cout<<'\n';
	
	return 0;
}
