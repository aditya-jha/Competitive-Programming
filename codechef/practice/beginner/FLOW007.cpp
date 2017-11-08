//
// Created by Aditya Jha on 08/11/17.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int t;
    string s;

    cin>>t;

    while (t--) {
        cin>>s;

        reverse(s.begin(), s.end());

        int i=0;
        while (s[i] == '0' && i < s.length()) {
            i++;
        }

        while (i<s.length()) {
            cout<<s[i];
            i++;
        }
        cout<<endl;
    }

    return 0;
}