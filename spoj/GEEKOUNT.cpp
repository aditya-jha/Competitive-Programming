#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define maxn 1000000001

vector<int> v;

bool iseven(int a) {
	int temp=1;
	while(a!=0) {
		temp*=(a%10);
		a=a/10;
	}
	if(temp%2==0) return true;
	return false;
}

void pre() {
	for(int i=1;i<maxn;i+=2) {
		//if(iseven(i)) { v.push_back(i); }//cout<<i<<endl; }
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	
	pre();
	cout<<v.size();
	
	int t,n,l,r;
	cin>>t;
	
	while(t--) {
		cin>>n;
			
		
	}
	
	
	return 0;
}
