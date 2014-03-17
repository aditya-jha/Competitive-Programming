#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>

using namespace std;


vector<int> pp;
long long counter = 0;
long long start = 8589934592LL, end = 17179869184LL;

void sieve() {
	bool *primes = new bool[1000001];
	for(int i=0;i<1000001;i++) primes[i]=true;
	primes[0]=primes[1]=false;
	
	for(int i=2;i<1000001;i++) {
		if(primes[i]) {
			pp.push_back(i);
			for(int j=i+i;j<1000001;j+=i) primes[j]=false;
		}
	}	
	pp.push_back(10000000);
	delete[] primes;
}


void segmented_sieve(long long a,long long b) {
	long index = b-a+1;
	
	bool *arr = new bool[index+1];
	for(long long int i=0;i<index;i++) arr[i]=true;

	int lim = (int)sqrt((double)b);
	for(int i=0;pp[i]<lim;i++) {
		long long int j=a/pp[i];
		if(j*pp[i]<a) j++;
		
		for(j=j*pp[i];j<=b;j+=pp[i]) arr[j-a]=false;
	}
	
	for(int i=0;i<index;i++) {
		if(arr[i]==true) {
          if((i+a)%4 == 3 and (i+a)<=end) counter++;
      }    
	}

	delete[] arr;
}

int main() {
	
	sieve();
	
	for(long long i=start;i<=end;i+=1000000) {
	    
	    segmented_sieve(i,i+1000000);
	    
	    cout<<i<<endl;
	}    
	
	cout<<"sol: "<<counter<<endl;
	
	getchar();
	return 0;
	
}
//184661253
