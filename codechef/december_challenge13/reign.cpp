#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>

#define getcx getchar_unlocked

#define max(a,b) (a>b?a:b)

using namespace std;

inline int in( ) {
	int n=0;
	
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	
	while( ch >= '0' && ch <= '9' )
		n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
		
	return n*sign;
}

long long int reign(int a[], int n, int k) {
	long long int sol[100010], sol2[100010], ans[100010], max_sum=0;
	int i,j,ith,jth;
	
	sol[0] = a[0];
	sol2[n-1] = a[n-1];
	
	j=n-k-1;
	ith = j;
	for(i=1;i<j;i++) {
		sol[i] = max(a[i],sol[i-1]+a[i]);
	}
	
	j--;

	ans[n-1] = a[n-1];
	
	for(i=n-2;i>k;i--) {
		sol2[i] = max(a[i],sol2[i+1]+a[i]);
		ans[i] = max(sol2[i],ans[i+1]);
	}
	
	//for(i=0;i<n;i++) cout<<sol[i]<<" ";
	//cout<<endl;
	
	max_sum = a[0]+ans[k+1];
	
	i=1; j = k+2;
	
	while(i<ith and j<n) {
		max_sum = max(max_sum,sol[i]+ans[j]);	
		i++; j++;
	}
	
	return max_sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	int t,n,k;
	int a[100010];
	
	t = in();
	
	while(t--) {
		n = in();
		k = in();
		
		for(int i=0;i<n;i++) a[i] = in();
		
		printf("%lld\n",reign(a,n,k));	
	}
	return 0;
}
