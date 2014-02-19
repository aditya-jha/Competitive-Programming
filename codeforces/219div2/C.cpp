#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<cstring>

using namespace std;
 
#define MOD 1000000007
#define llu long long unsigned
#define lld long long
#define ld long
 

int temp,n,counter=0,last;
vector<int> v;

bool search(int k) {
	int i=last;
	for(;i<v.size();i++) {
		if(v[i]>=(2*k)) {
			v[i]=0;
			last = i+1;
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	
	
	
	cin>>n;
	
	for(int i=0;i<n;i++) {
		cin>>temp;
		v.push_back(temp);
	}
	
	sort(v.begin(),v.end());
	
	temp = v.size()/2;
	last = temp;
	
	for(int i=0;i<temp;i++) {
		if(search(v[i])) counter++;
		else break;
	}
	
	cout<<n-counter<<"\n";
	
	return 0;
}
