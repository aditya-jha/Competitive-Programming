#include<iostream>
#include<string>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int main() {
    int t;
    cin>>t;

    for (int i=1; i<=t; i++) {
        vector<string> s;
        string c;
        int n;
        int maxV = INT_MIN;
        vector<int> v;

        for (int j=0; j<10; j++) {
            cin>>c>>n;
            s.push_back(c);
            v.push_back(n);
            maxV = max(maxV, n);
        }

        cout<<"Case #"<<i<<":\n";
        for (int j=0; j < 10; j++) {
            if (v[j] == maxV) {
                cout<<s[j]<<endl;
            }
        }
    }

    return 0;
}