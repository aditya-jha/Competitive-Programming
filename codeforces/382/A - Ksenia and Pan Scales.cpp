#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	
	string scale,use;
	cin>>scale;
	
	int index=0;
	
	while(scale[index] != '|') {
		index++;
	}
	
	cin>>use;
	
	string l,r;
	int left = index;
	int right = scale.length() - index - 1;
	
	for(int i=0;i<use.length();i++) {
		if(left<right) {
			l += use[i];
			left++;	
		}
		else {
			r += use[i];
			right++;
		}
	}
	
	if(left == right) {
		for(int i=0;i<index;i++) cout<<scale[i];
		cout<<l<<'|';
		
		for(int i=index+1;i<scale.length();i++) cout<<scale[i];
		cout<<r<<'\n';
	}
	else {
		cout<<"Impossible\n";
	}
	
	return 0;
}
