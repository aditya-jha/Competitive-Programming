#include<iostream>
#include<cmath>
using namespace std;

int nextprime(int i);
int check(int i);
int isprime(int i);

int main() {
	int t; //test cases
	cin>>t;
	while(t>0) {
		int A,B,K, value =0;
		cin>>A>>B>>K;
		//cout<<"A: "<<A<<" B: "<<B<<" K: "<<K<<endl;
		for(int i=A; i<=B; i++) {
			if(check(i) == K) value++;
			//cout<<check(i)<<" ";
		}
		//cout<<check(7)<<endl<<check(17);
		cout<<value<<endl;		
		
		t--;
	}
	return 0;
}

int nextprime(int i) {
	if(i==2) return 3;
	else if(i==3) return 5;
	else {
		int j = i+2;
		if(isprime(j)) return (j);
		else nextprime(j);
	}
}

int isprime(int i) {
	if(i%2==0) return 0;
	else if(i%3==0) return 0;
	else {
		int j=5;
		while(j<sqrt(double(i))) {
			if(i%j == 0) return 0;
			j = j+2;
		}
	}
	return 1;
}


int check(int i) {
	int count=0, prime = 2;
	while(i!=1 and prime <= i) {
		if(isprime(i)) {
			if(prev != i) {
				prev = i;
				count++;
			}
			i = 1;
		} else {
			if(i%prime == 0) {
				i=i/prime;
				count++;
			}
			prime = nextprime(prime);
		}
		
	}
	return count;
}
