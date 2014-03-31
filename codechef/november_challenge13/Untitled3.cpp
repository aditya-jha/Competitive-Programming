#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;


string pattern, text;
int patt=0, txt=0;
int alphaInPattern[30];
int lenPatt, lenText;

bool perform() {
	int i=lenPatt;
	int flag=1;
	
	while(i<text.length()) {
		if(txt == patt) {
		    
			int *dp = new int[30];
			for(int i=0;i<30;i++) dp[i] = 0;
			flag=1;
			
			for(int j=i-lenPatt;j<i;j++) {
				dp[text[j]-'a']++;
			}
			
			for(int j=0;j<30;j++) {
				if(dp[j]!=alphaInPattern[j]) {
					flag = 0;
					delete[] dp;
					return false;
				}
			}
			if(flag) {
				delete[] dp;
				return true;
			}
			delete[] dp;
		}
		txt += (int)(text[i]-'a');
		txt -= (int)(text[i-lenPatt]-'a');
		i++;
	}	
}

int main()  {
	int t;
	cin>>t;
	
	while(t--) {
		cin>>pattern>>text;
		
		lenPatt = pattern.length();
		lenText = text.length();
		
		for(int i=0;i<lenPatt;i++) {
			patt += (int)(pattern[i]-'a');
			alphaInPattern[pattern[i]-'a']++;
		}
		
		if(lenPatt > lenText) {
			cout<<"NO\n";
			continue;
		}
		
		for(int i=0;i<lenPatt;i++) {
			txt += (int)(text[i] - 'a');
		}
		
		if(perform()==true) cout<<"YES\n";
		else cout<<"NO\n";
		
		
	}
	
	return 0;
}
