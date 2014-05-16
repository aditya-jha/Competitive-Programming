#include<iostream>
#include<cstdio>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    long long m,n,k,i;
    
    cin>>t;
    
    while(t--) {
        cin>>n>>k>>m;
        
        if(k==1) {
            cout<<n<<'\n';
            continue;    
        }    
        
        for(i=0;i<m;i++) {
            if(n%k==0) {
                n = n/k;
            }    
            else {
                break;
            }    
        } 
        m = m-i;   
        if(m%2==0) cout<<n<<'\n';
        else cout<<n*k<<'\n';    
    }       
    
    return 0;
}    
