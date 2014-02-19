#include<iostream>
using namespace std;

int main() {
	int t;
	unsigned long long int N,K;
	cin>>t;
	while(t>0) {
		cin>>N>>K;
		if(N == 0) cout<<"0 0\n";
		else {
			if(K == 0) cout<<"0 "<<N<<"\n";
			else cout<<N/K<<" "<<N%K<<"\n";
		}
		
		t--;
	}
	return 0;
}
