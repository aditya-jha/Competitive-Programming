#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int long long maxn = 1e10;
long long a[100];

void fibo() {
	a[0]=0;
	a[1]=1;
	
	long long sum = a[0]+a[1];
	
	for(int i=2;sum<=maxn;i++) {
		a[i] = sum;
		sum = a[i]+a[i-1];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	
	fibo();
		
	int t;
	long long N;
	
	cin>>t;
	
	while(t--) {
		cin>>N;
		if(binary_search(a,a+50,N)) cout<<"IsFibo\n";
		else cout<<"IsNotFibo\n";
	}
	
	return 0;
}
