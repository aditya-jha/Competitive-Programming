//
// Created by Aditya Jha on 2018-12-24.
//

#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<utility>

using namespace std;

string getHex(int dec) {
    stringstream ss;
    ss << std::hex << dec;
    string su = ss.str();
    if (su.length() == 1) {
        su = "0" + su;
    }
    transform(su.begin(), su.end(), su.begin(), ::toupper);
    return su;
}

int main() {
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        int a[101], activeIndex = 0;
        for (int j = 0; j < 101; j++) {
            a[j] = 0;
        }

        string s;
        cin >> s;

        for (int j = 0; j < s.length(); j++) {
            if (s[j] == '>') {
                activeIndex = (activeIndex + 1) % 100;
            } else if (s[j] == '<') {
                if (activeIndex == 0) {
                    activeIndex = 99;
                } else {
                    activeIndex -= 1;
                }
            } else if (s[j] == '+') {
                a[activeIndex] = (a[activeIndex] + 1) % 256;
            } else if (s[j] == '-') {
                if (a[activeIndex] == 0) {
                    a[activeIndex] = 255;
                } else {
                    a[activeIndex] -= 1;
                }
            }
        }

        cout << "Case " << i << ": ";
        for (int j = 0; j < 99; j++) {
            cout << getHex(a[j]) << " ";
        }
        cout << getHex(a[99]) << endl;
    }

    return 0;
}