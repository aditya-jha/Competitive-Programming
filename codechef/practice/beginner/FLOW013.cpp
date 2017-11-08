//
// Created by Aditya Jha on 08/11/17.
//

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);

    int t,a,b,c;
    cin>>t;

    while (t--) {
        cin>>a>>b>>c;

        if ((a+b+c==180) && a>0 && b>0 && c>0) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }

    return 0;
}