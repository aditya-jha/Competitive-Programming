#include<iostream>

using namespace std;

int main() {
	long int sum = 2, prev = 1, curr = 2, res = 3;
	while(res<4000000) {
		res = prev+curr;
		if(res%2==0) sum+=res;
		prev = curr;
		curr = res;
	}
	
	cout << "sum is: " << sum << endl;
	
	return 0;
}
