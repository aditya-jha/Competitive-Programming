//
// Created by Aditya Jha on 08/11/17.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t, n;
    vector<int> v;


    cin>>t;

    while (t--) {
        v.clear();

        for(int i=0; i<3; i++) {
            cin>>n;
            v.push_back(n);
        }

        sort(v.begin(), v.end());

        cout<<v[1]<<endl;
    }

    return 0;
}