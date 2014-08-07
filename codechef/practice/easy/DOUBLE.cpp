#include<iostream>
#include<cstdio>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int t,n;
    cin>>t;
    
    while(t--) {
        cin>>n;
        if(n==0) {
            cout<<n<<'\n';
        }    
        else {
            if(n%2==0) {
                cout<<n<<'\n';
            }    
            else {
                cout<<n-1<<'\n';
            }    
        }    
    }    
    
    return 0;
}    
