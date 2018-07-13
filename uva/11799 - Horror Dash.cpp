#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;

int main() {
    int t;
    cin>>t;

    for (int i=1;i<=t; i++) {
        int n,s, sol = INT_MIN;
        cin>>n;

        while(n--) {
            cin>>s;
            sol = max(sol, s);
        }

        cout<<"Case "<<i<<": "<<sol<<endl;
    }

    return 0;
}