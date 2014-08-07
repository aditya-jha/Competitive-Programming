#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int t,n,k,a;
    cin>>t;
    
    while(t--) {
        cin>>n>>k;
        
        int count=0, con=0;
        while(n--) {
            cin>>a;
            if(a%2==0) count++;
            else con++;
        }    
        
        if(con==0 and k==0) cout<<"NO\n";
        else if(count>=k) cout<<"YES\n";
        else cout<<"NO\n";
    }    
    
    return 0;
}    
