#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int t,x,y,n;
    cin>>t;
    
    while(t--) {
        cin>>n>>x>>y;
        
        int *a = new int[n];
        int *b = new int[n];
        
        for(int i=0;i<n;i++) cin>>a[i]>>b[i];
        
        sort(a,a+n);
        sort(b,b+n);
        
        long long count=0;
        for(int i=0;i<n;i++) {
            if(a[i]<b[i]) {
                count += (((long long)b[i]-(long long)a[i])*(long long)x);
            }    
            else if(a[i]>b[i]) {
                count += (((long long)a[i]-(long long)b[i])*(long long)y);
            }    
        }    
        
        cout<<count<<'\n';
        
        delete[] a,b;
    }    
}    
