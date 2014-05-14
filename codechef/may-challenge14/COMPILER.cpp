#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>

using namespace std;

int longestprefix(string s) {
    int prefix = 0, open = 0, close = 0;
    
    for(int i=0;i<s.length();i++) {
        if(s[i] == '<') open++;
        else close++;
        
        if(close > open) break;
        else if(close == open) {
            prefix += (2*open);
            open = 0;
            close = 0;
        }    
    }    
    
    return prefix;
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    string s;
    cin>>t;
    
    while(t--) {
        cin>>s;
        cout<<longestprefix(s)<<'\n';
    }    
    
    return 0;
}    
