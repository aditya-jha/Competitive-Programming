#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int k;
    float x;
    
    cin>>k;
    cin>>x;
    
    while(k--) {
        int m,n,l,r,u,d;
        
        cin>>m>>n>>l>>r>>u>>d;
        
        int ans=0;
        
        float z = floor(x/(1.41*n));
        ans += l*(floor(0.5*z));
        
        ans += r*ceil(0.5*z);
        
        z = floor(x/(1.41*m));
        ans += d*floor(0.5*z);
        
        ans += u*ceil(0.5*z);
        
        cout<<ans<<endl;
    }    
    
    return 0;
}    
