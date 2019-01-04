//
// Created by Aditya Jha on 2018-12-27.
//

#include<iostream>
#include<set>
#include<cmath>

using namespace std;

int main() {
    while (true) {
        int a,b, c;

        cin >> a >> b;

        if (a == 0 && b == 0) {
            break;
        }

        set<int> x, y;
        set<int>::iterator itr;

        for (int i=0; i<a; i++) {
            cin>>c;
            x.insert(c);
        }

        for (int i=0; i<b; i++) {
            cin>>c;
            y.insert(c);
        }

        int uniqueA = 0, uniqueB = 0;

        for (itr = x.begin(); itr != x.end(); itr++) {
            int elem = *itr;
            if (y.find(elem) == y.end()) {
                uniqueA++;
            }
        }

        for (itr = y.begin(); itr != y.end(); itr++) {
            int elem = *itr;
            if (x.find(elem) == x.end()) {
                uniqueB++;
            }
        }

        cout<<min(uniqueA, uniqueB)<<endl;
    }

    return 0;
}