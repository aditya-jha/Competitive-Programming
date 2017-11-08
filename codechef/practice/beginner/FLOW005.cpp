//
// Created by Aditya Jha on 08/11/17.
//

#include <iostream>

using namespace std;

int totalD = 6;
int denominations[6] = {100, 50, 10, 5, 2, 1};

int count(int n) {
    int c = 0;
    for(int i=0; i<totalD; i++) {
        c += (n/denominations[i]);
        n = n%denominations[i];
    }
    return c;
}

int main() {
    int t,n;
    cin>>t;

    while (t--) {
        cin>>n;

        cout<<count(n)<<endl;
    }

    return 0;
}