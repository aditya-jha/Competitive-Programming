#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int t,n;
    cin>>t;
    
    while(t--) {
        cin>>n;
        
        int *a = new int[n];
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }    
        
        sort(a,a+n);
        
        for(int i=2;i<n;i+=2) {
            swap(a[i],a[i-1]);
        }    
        
        for(int i=0;i<n;i++) cout<<a[i]<<" ";
        cout<<"\n";
        
        delete[] a;
    }    
    
    return 0;
}    
