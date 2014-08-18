#include<iostream>
#include<cstdio>
#include<climits>
#include<vector>

#define min(a,b) (a>b?b:a)

using namespace std;

int n,m;
int table[1002][1002];
int mat[1002][1002];
vector<int> x,y;

int func(int a, int b, int count) {
	if(table[a][b] = 'D') mat[a][b] = count+1;	
	char r='I';
	while(true) {
		if(table[
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cin>>table[i][j];
			if(table[i][j]=='D') {
				x.push_back(i)
				y.push_back(j);
			}
		}
	}
	
	for(int i=0;i<v.size();i++) {
		val = func(x[i],y[j],0);
	}
	
	return 0;
}
