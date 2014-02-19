#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<string.h>
#include<cstring>
#include<stack>
#include<queue>
#include<cassert>
#include<cmath>
#define min(a,b) (a>b?b:a)

using namespace std;
//int index;
long int N;
long int arr[1000000][10];
//long int dp[1000000], way[1000000];

void open(long int n, long int count, long int p, long int dp[], long int way[]) {
	if(n==N) {if(count<dp[n]) { dp[n]=count; way[n+1] = p; } }
	else {
		//if(dp[n]!=1000001) dp[n] = min(dp[n],count);
		if(count<dp[n]) { dp[n]=count; way[n+1] = p; }
		//dp[n] = min(dp[n],count);
		for(int i=1; i<=arr[n][0]; i++) {
			if(arr[n][i]-1>n) open(arr[n][i]-1, count+1,n+1,dp,way);
		}
	}
	//return dp[n];
}


int main() {
	int t,m;
	scanf("%d",&t);
	while(t--) {
		scanf("%ld",&N);
		long int* dp = new long int[N+1];
		long int* way = new long int[N+1];
		//for(int i =0; i<N; i++) { dp[i]=1000001; way[i]=0;}
		memset(dp, 1000001, sizeof(long int) * N);
		memset(way, 0, sizeof(long int) * (N+1));
		for(int i=0; i<N-1; i++) {
			scanf("%ld",&arr[i][0]);
			for(int j=1; j<=arr[i][0]; j++) scanf("%ld",&arr[i][j]);
		}
		//index=0;
		open(0,0,1,dp,way); //way[0]=0;
		printf("%ld\n",dp[N-1]);
		//for(int i=1; i<N; i++) if(way[i+1]!=way[i-1]) printf("%ld ",way[i]);
		//printf("%ld\n",way[N]);
		int k=N;
		vector<long int>v;
		while(k>0) {
			v.push_back(way[k]);
			k=k-way[k];
		}
		for(int i=v.size()-1; i>-1; i--) printf("%ld ",v[i]);
		printf("\n");//,way[N]);
/*
		for(int i=0; i<N-1; i++) {
			scanf("%d",m);
			for(int j=0; j<m; j++) scanf("%ld",arr[i][j]);
		}
*/
	}
	return 0;
}
