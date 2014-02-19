#include<iostream>
#include<cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        long int N,C,M,d,w,ans=0;
        scanf("%ld %ld %ld",&N,&C,&M);
        
        d = N/C;
        w = d;
        ans+=d;
        while(w >= M) {
            d = w/M;
            ans += d;
            w = w%M;
            w += d;
        }    
        printf("%ld\n",ans);
    }    
    return 0;
}    
