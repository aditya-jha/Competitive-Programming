#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<iterator>

using namespace std;

bool checkAnagram(string a, string b) {
    if (a.length() != b.length()) {
        return false;
    }

    int elems[27];
    for (int i=0; i<27; i++) {
        elems[i] = 0;
    }

    for (int i=0; i<a.length(); i++) {
        elems[a[i]-'a']++;
        elems[b[i]-'a']--;
    }

    for (int i=0; i<27; i++) {
        if (elems[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int t;
    string s;

    cin>>t;

    while(t--) {
        cin>>s;

        map<string, int> m;
        map<string, int>::iterator itr;
        for (int i=0; i<s.length(); i++) {
            for (int j=1; j<=s.length()-i; j++) {
                string sub = s.substr(i, j);
                sort(sub.begin(), sub.end());
                if (m.count(sub) == 0) {
                    m[sub] = 0;
                } else {
                    m[sub] += 1;
                }
            }
        }

        int count = 0;
        for (itr = m.begin(); itr != m.end(); itr++) {
            int c = itr->second;
            count += (c * (c+1))/2;
        }    
        cout<<count<<endl;
    }

    return 0;
}