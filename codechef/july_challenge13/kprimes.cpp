#include<iostream>
#include<cmath>
using namespace std;

int check(int i);
bool isprime(int i);

int main() {
	int tests;
	cin>>tests;
		
	while(tests > 0) {
		int A,B,K;
		cin>>A>>B>>K;
		int value = 0;
		for(int i=A; i<=B; i++) {
			if(check(i) == K) value++;
		}
			
		cout<<value<<endl;
		tests--;
	}
	return 0;
}

bool isprime(int i) {
	if(i%2==0) return false;
	else if(i%3==0) return false;
	else {
		int j=5;
		while(j<int(sqrt(double(i)))) {
			if(i%j == 0) return false;
			j = j+2;
		}
	}
	return true;
}


int check(int i) {
	int prev=1, count=0, j=5;
	while(i!=1) {
		if(isprime(i)) {
			//cout<<"Prime: "<<i<<" prev: "<<prev<<" ";
			if(prev != i) {
				prev = i;
				count++;
			}
			i = 1;
		} else {
			if(i%2 == 0) {
				while(i%2==0) i=i/2;
				if(prev != 2) {
					prev = 2;
					count++;
				}
			} else if(i%3 == 0){
				while(i%3==0) i = i/3;
				//cout<<"i: "<<i<<" prev: "<<prev<<" ";
				if(prev != 3) {
					prev = 3;
					count++;
				}
			} else {
				if(i%j==0) {
					//cout<<"i: "<<i<<" prev: "<<prev<<" ";
					while(i%j==0) i = i/j;
					if(prev != j) {
						prev = j;
						count++;
					}
					j = j+2;
				} else j = j+2;
			}	
		}
	}
	return count;
}
