#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);    
    
    long long n,lim;
    cin>>n;
    
    while(n!=0) {
        lim = (long long)sqrt((double)n);
        
        if(lim*lim == n) cout<<"yes\n";
        else cout<<"no\n";
        
        cin>>n;
    }  
    return 0;      
}    

