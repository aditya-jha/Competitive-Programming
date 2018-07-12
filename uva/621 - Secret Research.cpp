#include<iostream>
#include<string>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        string s;
        cin>>s;

        int l = s.length();
        int j = l-1;
        int k = l-2;
        int m = l-3;

        if (l>=5 && s[m] == '0' && s[m-1] == '9' && s[m-2] == '1') {
            cout<<"?\n";
        }  else if (l>=4 && s[k] == '0' && s[m] == '9' && s[m-1] == '1' ) {
            cout<<"?\n";
        } else if (l>=3 && s[m] == '3' && s[j] == '4') {
            cout<<"*\n";
        } else if (l>=2 && s[k] == '3' && s[j] == '5') {
            cout<<"-\n";
        } else if (l>=2 && s[k] == '7' && s[j] == '8') {
            cout<<"+\n";
        } else if (l>=1 && (s[j] == '1' || s[j] == '4')) {
            cout<<"+\n";
        } 
    }
    
    return 0;
}