#include<iostream>
#include<string>

using namespace std;

int main() {
	string s,t;
	
	cin>>s>>t;
	
	int curr=0,slept=0;
	
	curr = 60*(10*s[0] + s[1]) + (10*s[3] + s[4]);
	
	//cout<<curr<<endl;
	
	slept = 60*(10*t[0] + t[1]) + (10*t[3] + t[4]);
	
	if(slept == 0) {
		cout<<s<<endl;
		return 0;
	}
	
	
	if(curr<=slept) curr += 1440;
	
	int diff = curr-slept;
	
	int min = diff%60;
	int hr = diff/60;
	//cout<<hr<<endl;
	if(hr==24) {
		cout<<"00:00\n";
		return 0;
	}
	
	if(hr/10 == 0) cout<<"0"<<hr<<":";
	else cout<<hr<<":";
	
	if(min/10 == 0) cout<<"0"<<min<<"\n";
	else cout<<min<<'\n';
	
	return 0;
}
