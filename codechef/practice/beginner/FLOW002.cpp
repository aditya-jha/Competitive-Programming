//
// Created by Aditya Jha on 08/11/17.
//

#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);

    int t,a,b;

    cin>>t;

    while (t--) {
        cin>>a>>b;

        cout<<a%b<<endl;
    }

    return 0;
}