//
// Created by Aditya Jha on 2018-12-27.
//

#include<iostream>
#include<cmath>

using namespace std;

int main() {
    double a, b;

    while (true) {
        cin >> a >> b;

        if (a == 0 && b == 0) {
            break;
        }

        int sol = 1;
        if (a == 0 || b == 0) {
            sol = 0;
        } else if (a >= 3 && b >= 3) {
            sol = int(ceil(a * b / 2));
        } else if (a == 1 || b == 1) {
            sol = int(max(a, b));
        } else if (a == 2 || b == 2) {
            int m = int(max(a, b));
            sol = m / 4 * 4 + (m % 4 == 1 ? 2 : (m % 4 >= 2 ? 4 : 0));
        }

        cout << sol << " knights may be placed on a " << a << " row " << b << " column board." << endl;
    }

    return 0;
}