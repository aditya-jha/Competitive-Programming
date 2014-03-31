#include<iostream>
#include<string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int t,sum;
    cin>>t;
    
    string s;
    while(t--) {
        cin>>s;
        sum=0;
        
        for(int i=0;i<s.length();i++) {
            if(s[i]!='_') sum+=(s[i]-'0');
        }    
        if(sum%9 == 0) {
            cout<<"0 or 9\n";
        }    
        else {
            sum = sum%9;
            cout<<9-sum<<endl;
        }    
    }    
    
    return 0;
}    
