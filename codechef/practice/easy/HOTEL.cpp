#include<iostream>
#include<cstdio>
 
using namespace std;
 
#define max(a,b) (a>b?a:b)
 
int open[1010], close[1010];
 
int main() {
    ios_base::sync_with_stdio(0);
    
    int t,n,temp,maxim;
    cin>>t;
    
    while(t--) {
        for(int i=0;i<1010;i++) open[i] = close[i] = 0;
        
        cin>>n;
        
        for(int i=0;i<n;i++) {
            cin>>temp;
            open[temp]++;
        }    
        for(int i=0;i<n;i++) {
            cin>>temp;
            close[temp]++;
        }    
        
        temp = maxim = 0;
        for(int i=0;i<1010;i++) {
            temp -= close[i];
            temp += open[i];
            maxim = max(temp,maxim);
        }    
        
        cout<<maxim<<'\n';
    }    
    return 0;
}     

