#include<iostream>
#include<cstdio>
#include<cstring>

int main() {
    ios_base::sync_with_stdio(0);
    
    int t,n,p,h;
    cin>>t; 
    
    while(t--) {
        cin>>n;
        cin>>p;
        
        int map[n+1];
        
        for(int j=0;i<=n;j++) map[j] = 0;
        
        for(int i=0;i<p;i++) {
            cin>>h;
            for(int j=h;j<=n;j+=h) map[j] = 1;
        }    
        
        int count = 0;
        for(int i=1;i<=n;i++) {
            if(i%7 != 0 and i%7 != 6 and map[i] != 0) count++;    
        }    
        
        cout<<count<<"\n";
    }    
    
    return 0;
}    
