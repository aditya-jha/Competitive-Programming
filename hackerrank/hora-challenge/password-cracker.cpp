#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include<utility>
#include<set>
using namespace std;

set<string> ss;

bool startsWith(string a, string b, int start) {
    if (b.length() > (a.length() - start)) {
        return false;
    }

    bool found = true;
    for (int i=start, j = 0; i<a.length() && j<b.length(); i++, j++) {
        if (a[i] == ' ') {i++;}
        if (a[i] != b[j]) {
            found = false;
            break;
        }
    }

    return found;
}

pair<string, bool> generatePairs(vector<string> matches, string result, string attempt, string current) {
    vector<pair<string, bool> > a;
    
    if (ss.find(current) != ss.end()) return make_pair(current, false);
    ss.insert(current);
    
    if (current.length() > attempt.length()) return make_pair(current, false);
    else if (current == attempt) return make_pair(result, true);
    for (int i=0; i<matches.size(); i++) {
        string newString = current + matches[i];
        if (startsWith(attempt, newString, 0)) {
            a.push_back(generatePairs(matches, result + matches[i] + " ", attempt, newString));
        }
    }
    for (int i =0; i<a.size(); i++) {
        if (a[i].second) {
            return a[i];
        }
    }
    return make_pair("", false);
}

string passwordCracker(vector <string> pass, string attempt) {
    vector<string> matches, result;
    for (int i=0; i<pass.size(); i++) {
        if (attempt.find(pass[i]) != std::string::npos) {
            matches.push_back(pass[i]);
        }
    }

    pair<string, bool> ret = generatePairs(matches, "", attempt, "");

    if (ret.second) {
        return ret.first.substr(0, ret.first.length() -1);
    }

    return "WRONG PASSWORD";
}

int main() {
    int t, n;
    string s;

    cin>>t;
    while(t--) {
        cin>>n;

        vector<string> v;
        while(n--) {
            cin>>s;
            v.push_back(s);
        }
        cin>>s;
        ss.clear();
        cout<<passwordCracker(v, s)<<endl;
    }

    return 0;
}