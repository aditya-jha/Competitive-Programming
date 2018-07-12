#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);

	int sum = 0;
	while(1) {
		sum = 120;
		int a, b, c, d;
		cin>>a>>b>>c>>d;
		
		if (a == 0 && b == 0 && c == 0 && d == 0) {
			break;
		}

		if (b > a) {
			sum += (40 - b + a);
		} else {
			sum += (a - b);
		}

		if (c > b) {
			sum += (c - b);
		} else {
			sum += (40 - b + c);
		}

		if (d > c) {
			sum += (40 - d + c);
		} else {
			sum += (c - d);
		}

		cout<<sum*9<<endl;
	}

	return 0;
}