//
// Created by Aditya Jha on 2018-12-28.
//

#include<iostream>
#include<vector>

using namespace std;

int a[101];

bool isPalindrome(vector<int> s) {
    int i=0, j=s.size()-1;
    while(i<j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    for (int i=0; i<101;i++) {
        a[i] = i*i;
    }

    int t;
    cin>>t;
    getchar();

    for (int c = 1; c <=t; c++) {
        string s;

        getline(cin, s);

        vector<int> v;

        for (int i=0;i<s.length();i++) {
            char cc = s[i];
            if (cc >= 'a' && cc <= 'z') {
                v.push_back(cc - 'a');
            }
        }

        int magic = -1;
        for (int i=0;i<101;i++) {
            if (v.size() == a[i]) {
                if (isPalindrome(v)) {
                    magic = i;
                    break;
                }
            }
        }

        cout<<"Case #"<<c<<":"<<endl;
        if (magic > -1) {
            cout<<magic<<endl;
        } else {
            cout<<"No magic :("<<endl;
        }
    }

    return 0;
}