#include<iostream>
using namespace std;

unsigned long long foo(unsigned long long int n, unsigned long long int r) {
    unsigned long long ans = 1;//,den=1,temp;
    
    if(r>n/2) r = n-r;
    
    for(int i=0;i<r;i++) {
        ans *= (n-i);
        ans /= (i+1);
    }        
    
    return ans;
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    unsigned long long n,k;
    cin>>t;
    
    while(t--) {
        cin>>n>>k;
        
        if(n==k) {
            cout<<"1\n";
        }    
        else {
            cout<<foo(n-1,n-k)<<'\n';
        }    
    }    
    return 0;
}    
