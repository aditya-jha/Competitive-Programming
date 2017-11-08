//
// Created by Aditya Jha on 08/11/17.
//

#include <cstdio>

using namespace std;

int main() {
    int t;
    long long q,a;
    double p;

    scanf("%d", &t);

    while (t--) {
        scanf("%lld", &q);
        scanf("%lld", &a);
        p = q*a;
        if (q>1000) {
            p = p - (0.10*p);
        }
        printf("%lf\n", p);
    }

    return 0;
}