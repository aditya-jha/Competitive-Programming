#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

bool isPrime(int n) {
    if(n==2) return true;
    if(n==3) return true;
    
    if(n%2==0 or n%3==0) return false;
    
    int lim = (int)sqrt((float)n);
    for(int i=5;i<=lim;i+=2) {
        if(n%i==0) return false;
    }    
    return true;
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    cin>>t;
    
    while(t--) {
        int x,y;
        cin>>x>>y;
        
        int sum = x+y;
        
        for(int i=sum+1;;i++) {
            if(isPrime(i)) {
                cout<<i-sum<<'\n';
                break;
            }    
        }    
    }    
    
    return 0;
}    
