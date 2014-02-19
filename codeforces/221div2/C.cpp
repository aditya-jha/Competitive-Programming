#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	
	string s;
	cin>>s;
	
	vector<int> v;
	
	for(int i=0;i<s.length();i++) {
		v.push_back(s[i]-'0');
	}
	
	
	
	return 0;
}
