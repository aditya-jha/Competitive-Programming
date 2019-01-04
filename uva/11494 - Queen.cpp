//
// Created by Aditya Jha on 2018-12-27.
//

#include<iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c, d;

    while(true) {
        cin>>a>>b>>c>>d;

        if (a==0) {
            break;
        }

        if (a == c && b == d) {
            cout<<0<<endl;
        } else if (a == c || b == d || (abs(c-a) == abs(d-b))) {
            cout<<"1"<<endl;
        } else {
            cout<<"2"<<endl;
        }
    }

    return 0;
}