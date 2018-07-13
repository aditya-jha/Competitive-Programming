#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main() {
    int a, b, f, n;

    while(1) {
        cin>>a>>b;

        if (a == -1 && b == -1) {
            break;
        }

        if (a > b) {
            f = 100 - a + b;
            n = a - b;
        } else {
            f = b - a;
            n = 100 + a - b;
        }

        cout<<min(f, n)<<endl;
    }

    return 0;
}