#include <cstdio>
#include <iostream>

using namespace std;

const int MOD = 1000000009;

int gcd (int a, int b, int &x, int &y) {
    if(a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int rev (int a, int mod) {
    int x, y;
    gcd(a, mod, x, y);
    x = (x % mod + mod) % mod;
    return x;
}

int choose[(1<<20) | 1];
int factor[(1<<20) | 1];

int main () {
    ios_base::sync_with_stdio(0);
    
    int k;
    cin>>k;
    
    if(k == 1) {
        cout<<"2\n2";
        return 0;
    }
    
    k = 1<<k;
    factor[0] = 1;
    
    for(int i = 1; i<=k; ++i) {
        factor[i] = ((long long)factor[i-1]*(long long)i)%(long long)MOD;
    }
    
    choose[(k/2)-1] = 1;
    
    for(int i=k/2; i<=k; i++) {
        int r = rev(i-(k/2)+1, MOD);
        choose[i] = ((long long)choose[i-1]*(long long)i)%((long long)MOD);
        choose[i] = (((long long)choose[i])*((long long)r))%((long long)MOD);
    }
    
    for(int i=1; i<=(k/2)-1; i++) {
        cout<<"0";
    }
    
    for(int i = k/2; i<k; ++i) {
        int ans = ((long long)choose[i-1]*(long long)factor[k/2])%(long long)MOD;
        ans = ((long long)ans*(long long)factor[k/2])%(long long)MOD;
        ans = (((long long)ans)*2)%MOD;
        
        cout<<ans<<endl;
    }
    
    cout<<factor[k]<<endl;
    
    return 0;
}
