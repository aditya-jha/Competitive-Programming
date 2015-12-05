include <iostream>
using namespace std;

long long phi(long long n) {
	long long result = n;
	for(long long i=2;i*i <= n;i++) {
		if (n % i == 0) result -= result / i;
		while (n % i == 0) n /= i;
	}
	if (n > 1) result -= result / n;
	return result;
}

int main() {
	int t;
	cin>>t;

	while(t--) {
		long long n;
		cin>>n;

		long long sol = 0;
		for(long long i=1; i*i<=n;i++) {
			if(n%i==0) {
				sol += phi(i);
				if(n/i != i) sol += phi(n/i);
			}
		}
		cout<<sol<<endl;
	}
	return 0;
}
