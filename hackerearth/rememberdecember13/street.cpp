#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<vector<int> > v(10005,vector<int>());
int n,q,x,y;

bool visit[100005];

int dist(int a,int day) {
	if(a==y) return day;
	
	visit[a] = true;
	
	queue<int> Q;
	Q.push(a);
	
	while(!Q.empty()) {
		int node = Q.front();
		Q.pop();
		for(int i=0;i<v[node].size();i++) {
			if(day%2!=0) {
				if(v[node][i]>
			}
		}
	}
	
}

int main() {
	int t;
	cin>>t;
	
	
	cin>>n;
	
	for(int i=0;i<n;i++) {
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	cin>>q;
	
	while(q--) {
		for(int i=0;i<=n;i++) visit[i] = false;
		cin>>x>>y;
		cout<<dist(x,y)<<'\n';
	}
	
	return 0;
}
