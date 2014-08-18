#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;

bool primes[1000001];

void sieve() {
    memset(primes, true, sizeof(primes));
    primes[0] = primes[1] = false;
    
    int lim = sqrt(double(1000001));
    
    for(int i=2;i<lim;i++) {
        if(primes[i]) {
            for(int j=2*i;j<1000001;j+=i) {
                primes[j] = false;
            }    
        }    
    }        
}

int main() {
    ios_base::sync_with_stdio(0);
    
    sieve();
    
    int t,n;
    cin>>t;
    
    while(t--) {
        cin>>n;
        
        for(int i=2,j=0;i<1000001,j<n;i++) {
            if(primes[i]) {
                cout<<i<<" ";
                j++;
            }    
        }    
        cout<<"\n";
    }    
    
    return 0;
}    
