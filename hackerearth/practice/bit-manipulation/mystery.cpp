#include<iostream>
#include<cstdio>

using namespace std;

int count_bits(long long n) {
    int c = 0;
    while(n) {
        n = n & (n-1);
        c++;
    }
    
    return c;
}

int main() {
    // ios_base::sync_with_stdio(0);
    
    long long n;
    
    while(scanf("%lld", &n) != EOF) {
        // cout<<count_bits(n)<<endl;
        printf("%d\n", count_bits(n));
    }
    
    return 0;
}