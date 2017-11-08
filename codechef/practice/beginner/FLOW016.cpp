//
// Created by Aditya Jha on 09/11/17.
//

#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a%b);
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    int t, a, b;
    cin>>t;

    while (t--) {
        cin>>a>>b;

        int g = gcd(a, b);
        long long lcm =  ((long long)a * (long long)b)/(long long)g;

        cout<<g<<" "<<lcm<<endl;
    }

    return 0;
}