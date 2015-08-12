#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        string s;
        cin>>s;

        int dot = s.find('.');
        if(dot == -1) {
            cout<<"1\n";
        }
        else {
            int val = 0;
            for(int i=s.length()-1;i>dot;i--) {
                val = val*10 + s[i] - '0';
            }
            cout<<pow(10.0,s.length()-dot-1)/val<<endl;
        }
    }
    return 0;
}
