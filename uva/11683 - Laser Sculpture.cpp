//
// Created by Aditya Jha on 2018-12-24.
//

#include<iostream>

using namespace std;

int v[10001];

int solve(int start, int end, int currentHeight) {
    if (currentHeight == -1 || (start > end)) {
        return 0;
    }

    int counts = 0, newEnd = end;

    for (int i = start; i <= end; i++) {
        if (v[i] > currentHeight) {
            counts += solve(i+1, end, currentHeight);
            newEnd = i - 1;
            break;
        } else {
            counts = 1;
        }
    }

    return counts + solve(start, newEnd, currentHeight-1);
}

int main() {
    int a, b;

    while (1) {
        cin >> a >> b;

        if (a == 0 || b == 0) {
            break;
        }

        for (int i = 0; i < b; i++) {
            cin >> v[i];
        }

        cout<<solve(0, b-1, a-1)<<endl;
    }

    return 0;
}