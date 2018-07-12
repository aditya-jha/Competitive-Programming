#include<iostream>
#include<string>

using namespace std;

bool isOne(string s) {
    if (s.length() == 3) {
        int len = 0;
        if (s[0] == 'o') {
            len++;
        }
        if (s[1] == 'n') {
            len++;
        }
        if (s[2] == 'e') {
            len++;
        }

        if (len >= 2) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool isTwo(string s) {
    if (s.length() == 3) {
        int len = 0;
        if (s[0] == 't') {
            len++;
        }
        if (s[1] == 'w') {
            len++;
        }
        if (s[2] == 'o') {
            len++;
        }

        if (len >= 2) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool isThree(string s) {
    if (s.length() == 5) {
        int len = 0;
        if (s[0] == 't') {
            len++;
        }
        if (s[1] == 'h') {
            len++;
        }
        if (s[2] == 'r') {
            len++;
        }
        if (s[3] == 'e') {
            len++;
        }
        if (s[4] == 'e') {
            len++;
        }

        if (len >= 4) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        string s;
        cin>>s;

        if (isOne(s)) {
            cout<<"1\n";
        } else if (isTwo(s)) {
            cout<<"2\n";
        } else if (isThree(s)) {
            cout<<"3\n";
        } 
    }

    return 0;
}