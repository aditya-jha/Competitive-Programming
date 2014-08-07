#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    cin>>t;
    
    while(t--) {
        int a;
        long long int b;
        
        cin>>a>>b;
        
        if(b==0) {
            cout<<"1\n";
            continue;
        }    
        
        int temp = b%4;
        if(temp == 0) {
            a = a%10;
            cout<<(a*a*a*a)%10<<'\n';
        }    
        else {
            a = a%10;
            cout<<((int)pow((float)a,(float)temp))%10<<'\n';
        }    
    } 
    
    return 0;   
}    
