//
// Created by Aditya Jha on 08/11/17.
//

#include <iostream>

using namespace std;

int main() {
    int t,n;
    int even = 0, odd = 0;

    cin>>t;

    while (t--) {
        cin>>n;

        if(n%2) {
            odd++;
        } else even++;
    }

    if (even > odd) {
        cout<<"READY FOR BATTLE\n";
    } else {
        cout<<"NOT READY\n";
    }

    return 0;
}