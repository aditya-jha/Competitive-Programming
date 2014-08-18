#include <cstdlib>
#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b) { 
    return ( b != 0 ? gcd(b, a % b) : a ); 
}

pair<int, int> extended_gcd(int a, int b) {
    pair<int,int> p;
    if (a % b == 0) {
        p.first = 0;
        p.second = 1;
        
        return p;
    } 
    else {
        p = extended_gcd(b, a % b);
        
        int temp = p.first;
        p.first = p.second;
        p.second = temp-(p.first*(a/b));
        
        return p;
    }
}

int main() {
    int a, b, d, x, y;

    while (scanf("%d %d",&a,&b) == 2) {
          d = gcd(a, b);
          
          pair<int,int> result = extended_gcd(a, b);

          cout << result.first << " " << result.second << " " << d << endl;

    }

    return 0;
}

