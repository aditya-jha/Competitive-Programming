#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);

    int t, l, w, h;
    cin>>t;

    for (int i=1; i<=t; i++) {
        cin>>l>>w>>h;
        if (l<=20 && w<=20 && h<=20) {
            cout<<"Case "<<i<<": good\n";
        } else {
            cout<<"Case "<<i<<": bad\n";
        }
    }

    return 0;
}