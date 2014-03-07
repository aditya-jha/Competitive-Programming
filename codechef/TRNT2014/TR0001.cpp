#include<iostream>
#include<cstdio>

using namespace std;

#define llu unsigned long long
#define max(a,b) (a>b?a:b)

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    cin>>t;
    
    llu n,m,moves,more,x,y;
    
    while(t--) {
        moves = 0;
        cin>>n>>m;
        
        x = -1;
        y = -1;
        //more = max(n,m);
        
        n--; m--;
        while(x+1<n or y+1<m) {
            moves++;
            x += ((n-x)/2);
            y += ((m-y)/2);
        }        
        
        cout<<moves<<'\n';
    }    
    
    return 0;
}    
