#include<iostream>
#include<string>

using namespace std;

int main() {
    int t;
    cin>>t;
    getchar();
    while(t--) {
        string s;
        int m = 0, f = 0;
        getline(cin, s);

        for (int i=0; i<s.length(); i++) {
            if (s[i] == 'M') m++;
            else if (s[i] == 'F') f++;
        }
        if (m == f && m>=2) cout<<"LOOP\n";
        else cout<<"NO LOOP\n";
    }

    return 0;
}