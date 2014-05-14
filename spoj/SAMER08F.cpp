#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int a[101];
    a[0] = 0;
    
    for(int i=1;i<101;i++) {
        a[i] = i*i + a[i-1];
    }    
    
    int n;
    cin>>n;
    
    while(n) {
        cout<<a[n]<<"\n";
        cin>>n;
    }    
    
    return 0;
}    
