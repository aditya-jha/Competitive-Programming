//
// Created by Aditya Jha on 2018-12-28.
//

#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int a, b;

    while(true) {
        cin>>a>>b;

        if (a == 0) {
            break;
        }

        int n[a+1];
        for (int i=0;i<=a;i++) {
            n[i] = 0;
        }

        int c[b];
        for (int i=0;i<b;i++) {
            cin>>c[i];
        }

        for (int i=0; i<b;i++) {
            for (int j=i+1; j<b;j++) {
                n[abs(c[i]-c[j])] = 1;
            }
        }

        bool all = true;
        for (int i=1;i<=a;i++) {
            if (n[i] == 0) {
                all = false;
                break;
            }
        }

        if (all) {
            cout<<"Y\n";
        } else {
            cout<<"N\n";
        }
    }

    return 0;
}