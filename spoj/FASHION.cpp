#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    cin>>t;
    
    while(t--) {
        int n;
        cin>>n;
        int *a = new int[n];
        int *b = new int[n];
        
        for(int i=0;i<n;i++) cin>>a[i];    
        for(int i=0;i<n;i++) cin>>b[i];
        
        sort(a,a+n);
        sort(b,b+n);
        
        int sum=0;
        
        for(int i=0;i<n;i++) sum += a[i]*b[i];
        
        cout<<sum<<'\n';
        
        delete[] a, b;
    }    
    
    return 0;
    
}    
