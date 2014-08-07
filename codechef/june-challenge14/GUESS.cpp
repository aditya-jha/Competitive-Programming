#include<iostream>
#include<cstdio>

using namespace std;

long long gcd(long long a, long long b) {
    if(b==0) return a;
    return gcd(b,a%b);
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    long long n,m,sol,g,mul;
    
    cin>>t;
    
    while(t--) {
        cin>>n>>m;
        sol = 0;
        
        if(n%2!=0) {
            sol += (((n/2)+1)*(m/2));
        }    
        else {
            sol += ((n/2)*(m/2));
        }    
        if(m%2!=0) {
            sol += (((m/2)+1)*(n/2));
        }    
        else {
            sol += ((n/2)*(m/2));
        }    
        
        mul = m*n;
        g = gcd(mul, sol);
        
        cout<<sol/g<<"/"<<mul/g<<endl;
    }    
    
    return 0;
}    
