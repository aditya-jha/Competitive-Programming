#include<iostream>
#include<cstdio>
#include<climits>

using namespace std;

#define max(a,b) (a>b?a:b)

int main() {
    ios_base::sync_with_stdio(0);
    
    int n;
    cin>>n;
    
    int a[n], sum, sol=-1000000000;
    
    for(int i=0;i<n;i++) cin>>a[i];
    
    for(int i=1;3*i<=n;i++) {
        if(n%i==0) {
            for(int j=0;j<i;j++) {
                sum = 0;
                for(int k=j;k<n;k+=i) {
                    sum += a[k];
                }
                sol = max(sol, sum);    
            }    
        }    
    }    
    
    cout<<sol;
    
    return 0;
}    
