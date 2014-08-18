#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;

long long mod;
bool primes[100000];

void sieve() {
    memset(primes, true, sizeof(primes));
    primes[0] = primes[1] = false;
    
    for(int i=2;i*i<100000;i++) {
        if(primes[i]) {
            for(int j=2*i;j<100000;j+=i) {
                primes[j] = false;
            }    
        }    
    }        
}    

long long modular_expo(long long a, long long n) {
    long long ret = 1;
    while(n>0) {
        if(n%2!=0) {
            ret = (ret*a)%mod;
        }    
        a = (a*a)%mod;
        n = n >> 1;
    }    
    return ret%mod;
}    

bool fermats_test(long long a, long long n) {
    
    long long val = modular_expo(a,n);
    
    if(val == a) return true;
    else return false;
}    

int main() {
    
    sieve();
    
    long long n;
    bool flag;
    
    scanf("%lld",&n);
    
    while(n!=0) {
        flag = 1;
        mod = n;
        
        if(primes[n]) {
            printf("%lld is normal.\n",n);
        }    
        else {
            for(int i=2;i<n;i++) {
                if(fermats_test(i,n) == false) {
                    flag = 0;
                    break;
                }
            }
            
            if(flag) printf("The number %lld is a Carmichael number.\n",n);
            else printf("%lld is normal.\n",n);
        }  
        
        scanf("%lld",&n);
    }
    
    return 0;
}        
