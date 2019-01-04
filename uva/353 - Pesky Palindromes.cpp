//
// Created by Aditya Jha on 2018-12-28.
//

#include<iostream>
#include<string>
#include<set>

using namespace std;

bool isPalindrome(string s) {
    unsigned long i=0, j=s.size()-1;
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

    while(cin>>s) {
        set<string> sset;
        set<string>::iterator itr;

        for (int i=0;i<s.length();i++) {
            for(int j=i;j<s.length();j++) {
                sset.insert(s.substr(i, j-i+1));
            }
        }

        int pals = 0;
        for (itr = sset.begin(); itr != sset.end(); itr++) {
            if (isPalindrome(*itr)) {
                pals++;
            }
        }

        cout<<"The string '"<<s<<"' contains "<<pals<<" palindromes."<<endl;
    }

    return 0;
}