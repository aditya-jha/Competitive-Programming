#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int n,t;
    cin>>n;

    long long sum=0,req=0;
    
    for(int i=0;i<n;i++) {
        cin>>t;
        sum+=t;
    }    
    
    req = ((long long)n*((long long)n+1))/2;
    
    if(req == sum) cout<<"YES\n";
    else cout<<"NO\n";
    
    return 0;
}    
