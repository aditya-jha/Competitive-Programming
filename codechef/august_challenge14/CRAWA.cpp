#include<iostream>
#include<cstdio>

using namespace std;

#define abs(a) (a<0?(-1*a):a)

int main() {
    ios_base::sync_with_stdio(0);
    
    int t,x,y,a,b;
    cin>>t;
    
    while(t--) {
        cin>>x>>y;
        
        a = abs(x);
        b = abs(y);
        
        if(x>0 and y>0) {
            if(x%2!=0) {
                if(y<=(x+1)) cout<<"YES\n";
                else if(y>(x+1) and y%2==0) cout<<"YES\n";
                else cout<<"NO\n";
            }    
            else {
                if(y>x and y%2==0) cout<<"YES\n";
                else cout<<"NO\n";
            }    
        }
        else if(x<0 and y>0) {
            if(a%2==0) {
                if(y<=a) cout<<"YES\n";
                else if(y>a and y%2==0) cout<<"YES\n";
                else cout<<"NO\n";
            }  
            else {
                if(y>a and y%2==0) cout<<"YES\n";
                else cout<<"NO\n";
            }      
        }
        else if(x<0 and y<0) {
            if(a%2==0) {
                if(y>=x) cout<<"YES\n";
                else if(y<x and b%2==0) cout<<"YES\n";
                else cout<<"NO\n";
            }    
            else {
                if(y<x and b%2==0) cout<<"YES\n";
                else cout<<"NO\n";
            }    
        }
        else if(x>0 and y<0) {
            if(x%2==0) {
                if(y<=(-1*x) and b%2==0) cout<<"YES\n";
                else cout<<"NO\n";
            }    
            else {
                if(y>(-1*x)) cout<<"YES\n";
                else if(y<(-1*x) and b%2==0) cout<<"YES\n";
                else cout<<"NO\n";
            }    
        }                
        else {
            if(x==0) {
                if(b%2==0) cout<<"YES\n";
                else cout<<"NO\n";
            }    
            else {
                if(x>0 and x%2!=0) cout<<"YES\n";
                else if(x<0 and a%2==0) cout<<"YES\n";
                else cout<<"NO\n";
            }    
        }    
    }  
    
    return 0;  
}    
