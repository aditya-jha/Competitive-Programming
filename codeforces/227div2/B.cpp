#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

vector<int> v,com;

int main() {
	ios_base::sync_with_stdio(0);
	
	int n,m,temp;
	cin>>n>>m;
	
	for(int i=0;i<n;i++) {
		cin>>temp;
		v.push_back(temp);
	}
	
	for(int i=0;i<m;i++) {
		cin>>temp;
		com.push_back(temp);
	}
	
	int i=0,j=0;
	
	while(i<m and j<n) {
		if(com[i]>=v[j]) {
			i++; j++;
		}
		else i++;
	}
	
	if(j==n) cout<<"0\n";
	else cout<<n-j<<'\n';	
	
	return 0;
}
