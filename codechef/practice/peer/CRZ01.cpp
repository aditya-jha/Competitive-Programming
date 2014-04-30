#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int main() {    
    int t;
    cin>>t;
    
    while(t--) {
        double n,k,sol;

        cin>>n>>k;
        
        if(n>1) sol = n*pow(k,1/n);
        else sol = k;
        
        printf("%0.6f\n",(float)sol);
    }    
    
    return 0;
    
}    
