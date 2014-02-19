#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int a[26]={0};

int main() {
	string s;

	cin>>s;
	
	for(int i=0; i<s.length(); i++) {
		a[int(s[i])-97]++;
	}	
	
	for(int i=0; i<26; i++) {
		if(a[i] != 0) {
			int d = a[i]/2;
			while(d>0) { printf("%c",i+97); d--; }
		}
	}
	//cout<<int('a')<<" "<<int('z')<<endl;
	//cout<<s<<"\n";
	return 0;
}
