#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

bool primes[10005];
int arr[10005],ss;
vector<int> pp;

void sieve(int n) {

	memset(primes,true,n*sizeof(int));
	memset(arr,0,n*sizeof(int));
	
	primes[0]=primes[1]=false;
	
	for(int i=2;i<n;i++) { 
		if(primes[i]) {
			pp.push_back(i);			
			for(int j=i+i;j<n;j+=i) 
				primes[j]=false;
		}
	}
}

void primefactor(int n) {
	for(int i=0;pp[i]<=n && i<pp.size();i++) {
		while(n%pp[i]==0) {
			arr[pp[i]]++;
			//cout<<n<<" ";
			n = n/pp[i];
		}
	}
	//cout<<endl;
}

int main() {
	//ios_base::sync_with_stdio(0);
	
	int n;
	//cin>>n;
	scanf("%d",&n);
	n++;
	sieve(n);
	
	//for(int i=0;i<pp.size();i++) cout<<pp[i]<<" ";
	//cout<<endl;
	
	for(int i=2;i<n;i++) {
		//cout<<"i: "<<i;//<<endl;
		if(primes[i]) {
			//cout<<" isprime\n";
			arr[i]++;
		} else {
			//cout<<" is not prime\n";
			primefactor(i);
		}
	}
	
	for(int i=0;i<pp.size()-1;i++) {
		//cout<<pp[i]<<"^"<<arr[pp[i]]<<" * ";
		printf("%d^%d * ",pp[i],arr[pp[i]]);
	}
	
	//cout<<pp[pp.size()-1]<<"^"<<arr[pp[pp.size()-1]]<<"\n";
	printf("%d^%d\n",pp[pp.size()-1],arr[pp[pp.size()-1]]);
		
	return 0;
}
