#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define LL long long

int MOD;

pair<LL, pair<LL, LL> > extendedEuclid(LL a, LL b) {
    if(a == 0) return make_pair(b, make_pair(0, 1));
    pair<LL, pair<LL, LL> > p;
    p = extendedEuclid(b % a, a);
    return make_pair(p.first, make_pair(p.second.second - p.second.first*(b/a), p.second.first));
}
 
long long modInverse(LL a, LL m) {
    return (extendedEuclid(a,m).second.first + m) % m;
}

long long int modexp(long long int x,long long int y) {
	if(y==0) return 1;
	
	long long int z = modexp(x,y/2);
	
	if(y%2==0) return (z*z)%MOD;
	else return (((x*z)%MOD)*z)%MOD;
}

long long mul(long long n) {
    long long m=n,st=n-2, en=n;
    if(n%2==0) {
        while(st>0) {
            m = (m*(en+st))%MOD;
            en += st;
            st -= 2;
        }    
    }    
    return m%MOD;
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    cin>>t;
    
    while(t--) {
        int n,p;
        cin>>n>>p;
        MOD = p;
        
        long long den = modInverse(modexp(6,p))%MOD;
        long long num = mul(3*n);
        
        cout<<num*den<<'\n';
    }    
    return 0;
}    
