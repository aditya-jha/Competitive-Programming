#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 1000001;

bool primes[1000001];
vector<long long> v;

void sieve() {
    memset(primes, true, sizeof(primes));
    
    primes[0] = primes[1] = false;
    
    for(long long i=2;i<maxn;i++) {
        if(primes[i]) {
            v.push_back(i*i);            
            for(long long j=2*i;j<maxn;j+=i) primes[j] = false;
        }    
    }    
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    sieve();
    
    int n;
    long long a;
    
    cin>>n;
    
    while(n--) {
        cin>>a;
        
        if(binary_search(v.begin(), v.end(), a)) {
            cout<<"YES\n";
        }    
        else cout<<"NO\n";
    }    
    
    return 0;
}    
