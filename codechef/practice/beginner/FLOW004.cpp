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

        cout<<(s[0] - '0') + (s[s.length()-1] - '0')<<endl;
    }

    return 0;
}