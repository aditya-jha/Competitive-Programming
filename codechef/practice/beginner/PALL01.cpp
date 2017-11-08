//
// Created by Aditya Jha on 08/11/17.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);

    int t;
    string s;

    cin>>t;

    while (t--) {
        cin>>s;

        int i=0,j=s.length()-1;
        while (i<=j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else break;
        }

        if (i>j) {
            cout<<"wins\n";
        } else {
            cout<<"losses\n";
        }
    }

    return 0;
}