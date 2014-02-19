#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>

using namespace std;

int scan_d() {
	int ip=getchar_unlocked(),ret=0;
	for(;ip<'0'||ip>'9';ip=getchar_unlocked());
	for(;ip>='0'&&ip<='9';ip=getchar_unlocked())
		ret=ret*10+ip-'0';

	return ret;
}

void print_d(int n) {
	int i=10;
	char output_buffer[11];output_buffer[10]='\n';
	
	do {
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	} while(n);
	
	do {
		putchar_unlocked(output_buffer[i]);
	} while(++i<11);
}

vector<int> pp;

void sieve() {
	bool *primes = new bool[100001];
	for(int i=0;i<100001;i++) primes[i]=true;
	primes[0]=primes[1]=false;
	
	for(int i=2;i<100001;i++) {
		if(primes[i]) {
			pp.push_back(i);
			for(int j=i+i;j<100001;j+=i) primes[j]=false;
		}
	}	
	pp.push_back(1000000);
	delete[] primes;
}


void segmented_sieve(int a,int b) {
	int index = b-a+1;
	
	bool *arr = new bool[index+1];
	for(int i=0;i<index;i++) arr[i]=true;

	int lim = sqrt(b);
	for(int i=0;pp[i]<lim;i++) {
		int j=a/pp[i];
		if(j*pp[i]<a) j++;
		
		for(j=j*pp[i];j<=b;j+=pp[i]) arr[j-a]=false;
	}
	
	for(int i=0;i<index;i++) {
		if(arr[i]==true) print_d(i+a);
	}

	delete[] arr;
}

int main() {
	ios_base::sync_with_stdio(0);
	sieve();
	
	int t,l,r;

	t = scan_d();
	while(t--) {
		l = scan_d();
		r = scan_d();
		if(r<100001) {
			for(int i=0;pp[i]<=r;i++) {
				if(pp[i]>=l) print_d(pp[i]);
			}
		}
		else segmented_sieve(l,r);
		putchar('\n');
	}
}
