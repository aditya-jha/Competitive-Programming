#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	
	int n,m,t,i,j,index,len;
	vector<int> v;

	cin>>n>>m;
	
	int a[m+1],flag=0,sum;
	for(int i=1;i<=m;i++) cin>>a[i];
	a[0]=0;
	i=0;
	j=0;
	len=0;
	while(n--) {
		cin>>t;
		if(t==-1) {
			len = v.size() - j;
			sum=0;
			while(a[i]<=len and i<=m) {
				i++;
				sum+=a[i-1];
				flag=1;
			}
			
			if(flag) j+=sum;
			flag=0;
		}
		else v.push_back(t); 
	}
	len = v.size()-j;
	if(len==0) cout<<"Poor stack!\n";
	else {
		for(;j<v.size();j++) cout<<v[j];
		cout<<'\n';
	}
	
	return 0;
	
}


