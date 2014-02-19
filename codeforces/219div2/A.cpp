#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	
	int k;
	int map[10];
	char temp,aa[5];
	
	for(int i=0;i<10;i++) map[i]=0;
	
	cin>>k;
	
	k = 2*k;
	
	cin.getline(aa,5);

	for(int i=0;i<16;i++) {
		cin>>temp;
		if(temp!='.') {
			map[temp-'0']++;
		}
	}
	
	for(int i=1;i<10;i++) {
		if(map[i]>k) {
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	
	return 0;
}
