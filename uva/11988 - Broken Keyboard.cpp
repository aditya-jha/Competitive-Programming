//
// Created by Aditya Jha on 2018-12-31.
//

#include<iostream>
#include<string>
#include<list>

using namespace std;

int main() {
    string s;

    while(getline(cin, s)) {
        list<char> l;
        list<char>::iterator itr = l.begin();

        for (int i=0;i<s.length();i++) {
            if (s[i] == '[') {
                itr = l.begin();
            } else if (s[i] == ']') {
                itr = l.end();
            } else {
                l.insert(itr, 1, s[i]);
            };
        }

        for (itr = l.begin(); itr != l.end(); itr++) {
            cout<<*itr;
        }
        cout<<endl;
    }

    return 0;
}