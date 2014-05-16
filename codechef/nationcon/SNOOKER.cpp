#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int k;
    float x;
    int m,n,l,r,u,d;
    
    cin>>k>>x;
    
    while(k--) {
        cin>>m>>n>>l>>r>>u>>d;
        int ans = 0;
        int q = x/(n*1.41);
        //cout<<q<<endl;
        if(q%2 == 0) {
            ans = ((l+r)*q)/2;
        }    
        else {
            ans = ((q-1)/2)*l + ((q+1)/2)*r;
        }    
        //cout<<ans<<endl;
        int w = x/(m*1.41);
        if(w%2==0) {
            ans += ((u+d)*w)/2;
        }    
        else {
            ans += ((w-1)*d)/2 + ((w+1)*u)/2;
        }    
        cout<<ans<<endl;
    }    
    return 0;
}    
