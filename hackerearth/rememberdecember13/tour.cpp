#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;

int n,p,cost[1002][1002];
string s[1005];
int key[1005];

int hashh(string a) {
	int len=a.length(),con=0;
	
	for(int i=0;i<len;i++) con+=(int)a[i];
	con = con%1001;
	while(true) {
		if(key[con]==0) {
			return con;
		} else con++;
		if(con>1001) con=0;
	}
}

int search(string a) {
	int len=a.length(),con=0;
	
	for(int i=0;i<len;i++) con+=(int)a[i];
	con = con%1001;
	
	while(true) {
		if(s[key[con]].compare(a) == 0) return key[con];
		else con++;
		if(con>1001) con=0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	int temp,curr=1;
	long long sum=0;
	cin>>n;
	
	memset(key,0,sizeof(key));
	
	for(int i=1;i<=n;i++) {
		cin>>s[i];	
		temp = hashh(s[i]);
		key[temp] = i;
		//cout<<temp<<endl;
	}
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) cin>>cost[i][j];
	}
	
	cin>>p;
	string c;
	
	while(p--) {
		cin>>c;
		temp = search(c);
		//cout<<temp<<endl;
		sum += (long long)cost[curr][temp];
		curr = temp;
	}
	
	cout<<sum<<'\n';
	
	return 0;
}
