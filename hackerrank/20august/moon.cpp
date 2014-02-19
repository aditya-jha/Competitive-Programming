#include<iostream>
#include<vector>
using namespace std;

unsigned long long int combinations(int n) {
	return n*(n-1)/2;
}

int main() {
	cout<<combinations(100000)<<endl;
	return 0;
}
