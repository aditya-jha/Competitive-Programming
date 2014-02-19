#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<cstring>

using namespace std;
 
#define MOD 1000000007
#define llu long long unsigned
#define lld long long
#define ld long

long scan_ld() {ld ip=getc(stdin),ret=0;for(;ip<'0'||ip>'9';ip=getc(stdin));for(;ip>='0'&&ip<='9';ip=getc(stdin))ret=ret*10+ip-'0';
	return ret;}

int main() {
	int t;
	long int n,k,ans;
	scanf("%d",&t);
	while(t--) {
		ans=0;
		scanf("%ld %ld",&n,&k);
		long int arr[n][k], A[k];
		for(long int i=0;i<n;i++) 
			for(long int j=0;j<k;j++) arr[i][j] = scan_ld();
		for(long int i=0;i<k;i++) A[i]=scan_ld();
		
		
		
		printf("%ld\n",ans);
	}
	return 0;
}
