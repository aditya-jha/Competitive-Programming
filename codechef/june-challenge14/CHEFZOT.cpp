#include<iostream>

#define max(a,b) (a>b?a:b)

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int n, count=0, max=0;    
    cin>>n;
    
    int *a = new int[n]; 
    
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if(a[i]==0) {
            if(count>max) max=count;
            count=0;
        }    
        else count++;
    }    
    
    if(count>max) max=count;
    
    cout<<max<<endl;
    
    delete[] a;
    
    return 0;
}    
