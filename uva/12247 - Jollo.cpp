//
// Created by Aditya Jha on 2018-12-27.
//

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool all[53];

int getNumber(int start) {
    int sol = start;
    while (sol < 53) {
        if (!all[sol]) {
            return sol;
        }
        sol++;
    }
    return -1;
}

int main() {
    int n;
    vector<int> a,b;

    while(true) {
        a.clear();
        b.clear();

        for (int i=0; i<53; i++) {
            all[i] = false;
        }

        for (int i=0; i<3; i++) {
            cin>>n;
            all[n] = true;
            a.push_back(n);
        }

        for (int i=3; i<5; i++) {
            cin>>n;
            all[n] = true;
            b.push_back(n);
        }

        if (n == 0) {
            break;
        }

        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());

        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());

        if (a[0] > b[0] && a[1] > b[1]) {
            cout<<"-1"<<endl;
        } else if (a[0] > b[0] && a[1] < b[1]) {
            cout<<getNumber(a[1] + 1)<<endl;
        } else if (a[0] < b[0] && a[1] > b[1]) {
            cout<<getNumber(a[0] + 1)<<endl;
        } else if (a[0] < b[0] && a[0] < b[1]) {
            cout<<getNumber(1)<<endl;
        } else if (a[0] < b[0] && a[1] < b[1]) {
            cout<<getNumber(a[1])<<endl;
        }
    }

    return 0;
}