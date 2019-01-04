//
// Created by Aditya Jha on 2018-12-28.
//

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

struct Guess {
    int val = 0;
    string reply = "";
};

string solve(vector<Guess> &v) {
    int start = 1, end = 10;

    for (int i=0; i<v.size(); i++) {
        string reply = v[i].reply;
        int val = v[i].val;

        if (reply == "too high") {
            end = min(end, val - 1);
        } else if (reply == "too low") {
            start = max(start, val + 1);
        } else {
            if (val >= start && val <= end) {
                return "Stan may be honest";
            } else {
                return "Stan is dishonest";
            }
        }

    }
}

int main() {
    int n;
    string s, ss;

    vector<Guess> v;

    while(true) {
//        getline(cin, ss);
//        n = stoi(ss);

        cin>>n;

        if (n == 0) {
            break;
        }

        getchar();

        getline(cin, s);

        Guess guess;
        guess.val = n;
        guess.reply = s;

        v.push_back(guess);

        if (s == "right on") {
            cout<<solve(v)<<endl;
            v.clear();
        }
    }

    return 0;
}