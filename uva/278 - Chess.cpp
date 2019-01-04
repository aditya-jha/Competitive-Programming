//
// Created by Aditya Jha on 2018-12-27.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        char p;
        double m,n;

        cin>>p>>m>>n;

        if (p == 'r' || p == 'Q') {
            cout<<min(m,n)<<endl;
        } else if (p == 'k') {
            cout<<ceil(m*n/2)<<endl;
        } else if (p == 'K') {
            cout<<ceil(m/2) * ceil(n/2)<<endl;
        }
    }

    return 0;
}