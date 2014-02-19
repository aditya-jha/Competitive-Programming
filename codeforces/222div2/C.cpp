#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <utility>

using namespace std;

int scan_d() {
	int ip=getchar(),ret=0;
	for(;ip<'0'||ip>'9';ip=getchar());
	for(;ip>='0'&&ip<='9';ip=getchar())
		ret=ret*10+ip-'0';

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	
	int n,m,k;
	char mat[501][501];
	n = scan_d();
	m = scan_d();
	k = scan_d();
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) mat[i][j] = getchar();
		getchar();
	}
	
	int a=0,b;
	for(b=1;b<n-1;b++) {
		if(k==0) break;
		if(mat[a][b]=='.' and mat[a][b-1]=='#' and mat[a][b+1]=='#') {
			mat[a][b] = 'X'; k--;
		}
	}
	
	a=n-1;
	for(b=1;b<n-1;b++) {
		if(k==0) break;
		if(mat[a][b]=='.' and mat[a][b-1]=='#' and mat[a][b+1]=='#') {
			mat[a][b] = 'X';
			k--;
		}
	}
	
	a=0;
	for(b=1;b<n-1;b++) {
		if(k==0) break;
		if(mat[b][a]=='.' and mat[b-1][a]=='#' and mat[b+1][a]=='#') {
			mat[a][b] = 'X';
			k--;
		}
	}
	
	a=n-1;
	for(b=1;b<n-1;b++) {
		if(k==0) break;
		if(mat[b][a]=='.' and mat[b-1][a]=='#' and mat[b+1][a]=='#') {
			mat[a][b] = 'X';
			k--;
		}
	}
	int counter;
	for(int i=0;i<n;i++) {
		counter=0;
		for(int j=0;j<n;j++)
			if(mat[i][j]=='.') counter++;
		if(counter>=k) {
			for(int j=0;j<n;j++)
				if(mat[i][j]=='.') mat[i][j]='X';
		}
		k-=counter;
	}
	return 0;
}
