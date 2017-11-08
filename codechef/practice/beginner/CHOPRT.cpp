//
// Created by Aditya Jha on 08/11/17.
//

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);

    int t;
    long long a,b;

    cin>>t;

    while (t--) {
        cin>>a>>b;

        if (a<b) {
            cout<<"<\n";
        } else if(a>b) {
            cout<<">\n";
        } else cout<<"=\n";
    }

    return 0;
}