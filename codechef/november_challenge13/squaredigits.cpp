#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdlib>

using namespace std;

bool digits(long long int n) {
	int temp;
	while(n!=0) {
		temp = n%10;
		if(temp==0) { n=n/10; continue;}
		else if(temp==1) { n=n/10; continue;}
		else if(temp==4) { n=n/10; continue;}
		else if(temp==9) { n=n/10; continue;}
		else return false;
	}
	
	return true;
}

int main() {
	vector<long long int> v;
	long long int sqq;
	for(long long int i=1;i<=100000;i++) {
		sqq = i*i;
		if(digits(sqq)) v.push_back(sqq);
	}
	int t,count;
	long long int a,b;
	scanf("%d",&t);
	while(t--) {
		scanf("%lld %lld",&a,&b);
		count=0;
		
		for(int i=0;v[i]<=b;i++) if(v[i]>=a) count++;
		
		printf("%d\n",count);
	}
	return 0;
}
