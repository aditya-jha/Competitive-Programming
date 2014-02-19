#include<iostream>
#include<cmath>

using namespace std;

bool isprime(long long int n) {
	if(n==2) return true;
	if(n==3) return true;
	if(n%2==0) return false;
	if(n%3==0) return false;
	for(long long int i=5;i<=sqrt(double(n));i+=2) {
		if(n%i==0) return false;		
	}
	return true;
}

int main() {
	long long int n = 600851475143;
	if(isprime(n)) {
		cout << "largest prime is: " << n << endl;
	} else {
		//cout << "Not prime: " << n << endl;
		for(double i=2;i<n;i++) {
			double j = n/i;
			//cout << "j: " << j << endl;
			if(j != floor(j)) continue;
			//j = long long int(j);
			if(isprime(j)) {
				cout << "largest prime is: " << (long long int)j << endl;
				break;
			} //else cout << "Not prime: " << (long long int)j << endl;	
		}	
	}
	return 0;
}
