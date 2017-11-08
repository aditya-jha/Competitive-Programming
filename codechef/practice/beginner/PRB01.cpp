//
// Created by Aditya Jha on 08/11/17.
//

#include <iostream>

using namespace std;

int primes[100001];

void preComp() {
    for(int i=1; i<100001; i++) {
        primes[i] = 1;
    }

    for(int i=2; i*i<100001; i++) {
        if (primes[i]) {
            for (int j=2; i*j<100001; j++) {
                primes[i*j] = 0;
            }
        }
    }
}

int main() {
    preComp();

    int t,n;
    cin>>t;

    while (t--) {
        cin>>n;
        if (primes[n]) {
            cout<<"yes\n";
        } else {
            cout<<"no\n";
        }
    }
    return 0;
}