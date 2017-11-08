//
// Created by Aditya Jha on 08/11/17.
//

#include<iostream>
#include<string>

using namespace std;

int main() {
    int t;
    string s;

    cin>>t;

    while (t--) {
        cin>>s;

        int sum = 0;

        for (int i = 0; i < s.length(); ++i) {
            sum += (s[i] - '0');
        }

        cout<<sum<<endl;
    }

    return 0;
}