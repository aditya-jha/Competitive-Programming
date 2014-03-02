#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int t,n;
    unsigned long long x;
    
    cin>>t;
    
    while(t--) {
        cin>>n;
        
        x = n/2;
        
        cout<<x*(x/2) - (x/2)*(x/2)<<'\n';
    }    
    
    return 0;
}    
