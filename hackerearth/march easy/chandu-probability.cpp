#include<iostream>
using namespace std;

int GCD( int a, int b ) {
    if(b == 0) return a;
    else return GCD(b,a%b);
}    

long long fact(int n) {
    long long m=1;
    while(n>1) {
        m *= n;
        n--;
        
    }   
    return m; 
}    


int main() {
    ios_base::sync_with_stdio(0);
    
    int t,n,m,c;
    cin>>t;
    
    while(t--) {
        cin>>n>>m;
        cout<<fact(n)<<endl;
        cout<<1 - ( fact(m) * fact(m) *fact (m) / (fact(n) * fact (n) ) )<<'\n';
        //cout<<m/c<<'/'<<n/c<<'\n';
    }    
    
    return 0;
}    
