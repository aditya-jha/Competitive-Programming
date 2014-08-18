#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    long long a,b,c,d, count,e;
    
    cin>>a>>b>>c>>d;
    
    while(a+b+c+d != 0) {
        count = 0;
        
        while(true) {
            if(a == b and b == c and c == d) {
                break;
            }    
            count++;
            
            e = a;
            a = abs(a-b);
            b = abs(b-c);
            c = abs(d-c);
            d = abs(d-e);
        }
        
        cout<<count<<"\n"; 
        
        cin>>a>>b>>c>>d;
    }    
    
    return 0;
    
}    
