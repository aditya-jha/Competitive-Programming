#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct _ {_() {ios_base::sync_with_stdio(0);}} _;

string s;

int fucn(int i, int j) {
	int len = i + (j-i+1)/2;
	for(int k=i,p=j; k<len; k++,p--) if(s[k]!=s[p]) return 0;	
	return 1;
}

int main() {

	cin>>s;
	//int length = s.length(), half = length/2;
	//int dp[length][length];
	/*
	for(int i=0; i<length; i++) {
		dp[i][i]=1;
		for(int j=i+1; j<length; j++) {
			dp[i][j] = 1+dp[i][j-1]+fucn(s,i,j);
		}
	}
	
	for(int i=0; i<length; i++) {
		for(int j=i; j<length; j++) cout<<dp[i][j]<<" ";
		cout<<endl;
	}

	*/
	int t,a,b;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&a,&b);
/*
		int count=dp[a][b];
		for(int i=a+1; i<b; i++) {
			count+=(dp[i][b]-(b-i+1));
		}
*/
		long long int count=0;//b-a+1;
		for(int i=a; i<=b; i++) {
			for(int j=i; j<=b; j++) { count+=fucn(i,j); cout<<fucn(i,j)<<endl; }
		}
		
		printf("%lld\n",count);
	}
	
	
	return 0;
}
