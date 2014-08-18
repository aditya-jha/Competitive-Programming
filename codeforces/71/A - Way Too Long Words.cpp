#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    string s;
    
    cin>>t;
    
    while(t--) {
        cin>>s;
        
        if(s.length() > 10) {
            cout<<s[0]<<s.length()-2<<s[s.length()-1]<<"\n";
        }    
        else cout<<s<<"\n";
    }    
    
    return 0;
}    
