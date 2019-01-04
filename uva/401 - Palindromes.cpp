//
// Created by Aditya Jha on 2018-12-28.
//

#include<iostream>
#include<string>

using namespace std;

bool isPalindrome(string s) {
    int i=0, j=s.length()-1;
    while(i<j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

bool isMirrored(string s) {
    char m[s.length()];

    for (int i=0;i<s.length();i++) {
        char c = s[i];
        switch (c) {
            case 'A':
                m[i] = 'A';
                break;
            case 'E':
                m[i] = '3';
                break;
            case 'H':
                m[i] = 'H';
                break;
            case 'I':
                m[i] = 'I';
                break;
            case 'J':
                m[i] = 'L';
                break;
            case 'L':
                m[i] = 'J';
                break;
            case 'M':
                m[i] = 'M';
                break;
            case 'O':
                m[i] = 'O';
                break;
            case 'S':
                m[i] = '2';
                break;
            case 'T':
                m[i] = 'T';
                break;
            case 'U':
                m[i] = 'U';
                break;
            case 'V':
                m[i] = 'V';
                break;
            case 'W':
                m[i] = 'W';
                break;
            case 'X':
                m[i] = 'X';
                break;
            case 'Y':
                m[i] = 'Y';
                break;
            case 'Z':
                m[i] = '5';
                break;
            case '1':
                m[i] = '1';
                break;
            case '2':
                m[i] = 'S';
                break;
            case '3':
                m[i] = 'E';
                break;
            case '5':
                m[i] = 'Z';
                break;
            case '8':
                m[i] = '8';
                break;
            default:
                return false;
        }
    }

    int i=0, j=s.length()-1;
    while(i<j) {
        if (m[i] != s[j]) {
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
        bool pal = isPalindrome(s);
        bool ism = isMirrored(s);

        if (pal && ism) {
            cout<<s<<" -- is a mirrored palindrome."<<endl;
        } else if (pal) {
            cout<<s<<" -- is a regular palindrome."<<endl;
        } else if (ism) {
            cout<<s<<" -- is a mirrored string."<<endl;
        } else {
            cout<<s<<" -- is not a palindrome."<<endl;
        }
        cout<<endl;
    }

    return 0;
}