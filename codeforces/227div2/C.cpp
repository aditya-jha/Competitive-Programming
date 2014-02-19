#include<iostream>
#include<string>

using namespace std;

long long count=0;

void split(string s) {
	//cout<<s<<endl;
	int len = s.length();
	if(len == 0) return;
	
	if(len == 1) {
		//cout<<s<<endl;
		count++;
		return;
	}
	
	int mid = len/2;
	if(len%2 == 0) {
		if(s[mid]>s[0]) mid++;
		else if(s[mid] == s[0]) {
			for(int i=mid,j=0;i<len;i++,j++) {
				if(s[i]>s[j]) { mid++; break; }
			}
		}

		
		
		while(mid<len and s[mid]=='0') mid++;
		
		if(mid == len) {
			//cout<<s<<endl;
			count++;
			return;
		}
		else {
		string s1,s2;
		
		for(int i=0;i<mid;i++) s1 += s[i];
		for(int i=mid;i<len;i++) s2 += s[i];
		
		cout<<s1<<" "<<s2<<endl;
		
		split(s1);
		split(s2);
		}
	}
	else {
		mid++;
		//cout<<s<<" "<<mid<<endl;
		while(mid<len and s[mid]=='0') mid++;
		//cout<<s<<" "<<mid<<endl;
		if(mid == len) { 
		//	cout<<s<<endl;
			count++; return; 
		}		
		else {
		string s1,s2;
		for(int i=0;i<mid;i++) s1 += s[i];
		for(int i=mid;i<len;i++) s2 += s[i];
		
		cout<<s1<<" "<<s2<<endl;
		
		split(s1);
		split(s2);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	
	string in;
	cin>>in;

	split(in);
	
	cout<<count<<'\n';
		
	return 0;
}
