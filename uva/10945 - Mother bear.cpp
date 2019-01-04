//
// Created by Aditya Jha on 2018-12-28.
//

#include<iostream>
#include<string>
#include<vector>

using namespace std;

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
    string s;

    while(true) {
        getline(cin, s);

        if (s == "DONE") {
            break;
        }

        if (s.length() == 0) {
            cout<<"You won't be eaten!"<<endl;
            continue;
        }

        vector<int> v;

        for (int i=0;i<s.length();i++) {
            char c = s[i];
            if (c >= 'A' && c <= 'Z') {
                v.push_back(c - 'A');
            } else if (c >= 'a' && c <= 'z') {
                v.push_back(c - 'a');
            }
        }

        if (isPalindrome(v)) {
            cout<<"You won't be eaten!"<<endl;
        } else {
            cout<<"Uh oh.."<<endl;
        }
    }

    return 0;
}