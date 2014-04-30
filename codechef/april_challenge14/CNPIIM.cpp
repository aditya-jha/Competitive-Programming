#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

#define lld long long unsigned

lld getVal(lld val) {
    lld lim = (lld)sqrt((double)val), sol = 0;
    for(lld i=1;i<=lim;i++) {
        sol += (val/i);
    }    
    sol *= 2;
    sol -= (lim*lim);
    
    return sol;
}    
 
int main(){
    ios_base::sync_with_stdio(0);
    
    int t;
    cin>>t;
    
    while(t--) {
        lld sol=0,lim, n;
        cin>>n;
        
        lim = (n+1)/2;
        for(lld i=1;i<lim;i++) {
            sol += getVal((i*(n-i)) - 1);
        }    
        
        sol *= 2;
        
        if(n%2 == 0) {
            sol += getVal((n/2)*(n/2) - 1);
        }    
        
        cout<<sol<<'\n';
    }
    
    return 0;    
}

