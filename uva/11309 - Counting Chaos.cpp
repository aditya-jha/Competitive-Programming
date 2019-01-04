//
// Created by Aditya Jha on 2018-12-28.
//

#include<iostream>
#include<string>
#include <algorithm>
#include<utility>

using namespace std;

bool isPalindrome(string s) {
    long i=0, j=s.size()-1;
    while(i<j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

pair<string, string> getTime(int hour, int minute) {
    string m = to_string(minute);
    string h = to_string(hour);

    pair<string, string> p;

    if (hour == 0) {
        p.first = m;
        if (m.length() == 1) {
            m = "0" + m;
        }
        p.second = "00:" + m;
    } else {
        if (m.length() == 1) {
            m = "0" + m;
        }

        p.first = h+m;

        if (h.length() == 1) {
            h = "0" + h;
        }

        p.second = h + ":" + m;
    }

    return p;
}

int main() {
    int t;
    cin>>t;

    getchar();

    while(t--) {
        string s;
        cin>>s;

        int hour = (s[0] - '0')*10 + (s[1] - '0');
        int minutes = (s[3] - '0')*10 + (s[4] - '0');

        while(true) {
            minutes++;
            if (minutes >= 60) {
                hour++;
                minutes = 0;
            }
            if (hour >= 24) {
                hour = 0;
            }

            pair<string, string> time = getTime(hour, minutes);
            if (isPalindrome(time.first)) {
                cout<<time.second<<endl;
                break;
            }
        }
    }

    return 0;
}