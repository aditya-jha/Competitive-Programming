#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	
	int t,counter,flag;
	long long int sol,L,D,S,C;
	
	cin>>t;
	while(t--) {
		cin>>L>>D>>S>>C;
		counter=1;
		sol = S;
		flag=0;
		//cout<<sol<<endl;
		while(counter<D) {
			sol*=(1+C);
			if(sol>=L) {
				cout<<"ALIVE AND KICKING\n";
				flag=1;
				break;
			}
			counter++;
			
		}
		//cout<<sol<<endl;
		if(sol<L) cout<<"DEAD AND ROTTING\n";
		else if(flag==0 and sol>=L) cout<<"ALIVE AND KICKING\n";
	}
	
	return 0;
}
