#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int n,m,a,maxx=-1;
    cin>>n>>m;
    
    int sum[m+1];
    sum[0] = 0;
    
    for(int i=1;i<=m;i++) {
        cin>>a;
        sum[i] = sum[i-1] + a;
        maxx = max(maxx,a);
    }    

    if(n>=m) {
        cout<<maxx<<endl;
        return 0;
    }    

    int dp[n+1][m+1];      
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(i==1) dp[i][j]=sum[j];
            else {
                dp[i][j]=INT_MAX;
                for(int k=i-1; k<=(j-1); k++) 
                    dp[i][j]=min(dp[i][j],max(sum[j]-sum[k],dp[i-1][k]));                
            }        
        }
    }    
    
    int sol = INT_MAX;
    for(int i=1;i<=n;i++) {
        sol = min(sol, dp[i][m]);
    }        
    
    cout<<sol<<endl;
    
    return 0;
}    
