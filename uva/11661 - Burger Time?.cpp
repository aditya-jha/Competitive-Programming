#include<iostream>
#include<string>
#include<climits>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    int t;
    while(1) {
        cin>>t;

        if (t == 0) {
            break;
        }

        string s;
        cin>>s;

        vector<int> r, d;
        char lastFound = 'A';
        int result = INT_MAX, diff=INT_MAX;
        for (int i=0; i<s.length(); i++) {
            if (s[i] == 'Z') {
                result = 0;
            } else if (s[i] == 'R') {
                r.push_back(i+1);
            } else if (s[i] == 'D') {
                d.push_back(i+1);
            }
        }

        if (result == 0) {
            cout<<result<<endl;
        } else {
            for (int i=0; i<d.size(); i++) {
                    for (int j=0; j<r.size(); i++) {
                        diff = r[j] - d[i];
                        result = min(result, abs(diff));
                    }
                }
            cout<<result<<endl;
        }
    }

    return 0;
}