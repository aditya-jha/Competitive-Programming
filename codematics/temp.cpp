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
//	for(int k=i; k<2*len; k++) cout<<s[k]<<" ";
	return 1;
}

int main() {

	cin>>s;
	int length = s.length();
	long int size = (length*(length+1))/2;
	int dp[size], store[length];
	int k=0;
	for(int i=0; i<length; i++) {
		dp[k]=1; store[i]=k; k++;
		for(int j=i+1; j<length; j++) {
			dp[k] = 1+dp[k-1]+fucn(i,j);
			k++;
		}
	}
/*	
	for(int i=0; i<size; i++) {
		cout<<dp[i]<<endl;
	}

*/	
	int t,a,b;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&a,&b);
		long long int count=dp[store[a]+b-a];

		for(int i=a+1; i<b; i++) {
			count+=(dp[store[i]-i+b]-(b-i+1));
		}

		
		printf("%lld\n",count);

	}
	
	
	return 0;
}
