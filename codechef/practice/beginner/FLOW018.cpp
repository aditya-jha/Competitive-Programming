//
// Created by Aditya Jha on 08/11/17.
//

#include <iostream>
#include <vector>

using namespace std;

vector<long long> v;

void pre() {
    v.push_back(1);

    for(long long i=1; i<21; i++) {
        v.push_back(v[i-1]*i);
    }
}

int main() {
    pre();

    int t,n;

    cin>>t;

    while (t--) {
        cin>>n;

        cout<<v[n]<<endl;
    }

    return 0;
}


