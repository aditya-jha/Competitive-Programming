#include<stdio.h>

int main() {    
    int t,n;
    unsigned long long x;
    
    scanf("%d",&t);
    
    while(t--) {
        scanf("%d",&n);
        
        x = n/2;
        
        printf("%llu\n",x*(x/2) - (x/2)*(x/2));
    }    
    
    return 0;
}    
