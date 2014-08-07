#include<iostream>
#include<cstdio>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int t,n;
    cin>>t;
    
    while(t--) {
        cin>>n;
        if(360%n==0) {
            cout<<"y ";
        }    
        else {
            cout<<"n ";
        }    
        if(n>360) {
            cout<<"n ";
        }    
        else {
            cout<<"y ";
        }    
        if(n>26) {
            cout<<"n\n";
        }    
        else {
            cout<<"y\n";
        }    
    }    
    
    return 0;
}    
