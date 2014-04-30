#include<iostream>
#include<vector>
#include<algorithm>

uisng namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    cin>>t;
    
    while(t--) {
        int m,n;
        cin>>m>>n;
        
        int *dp = new int[n];
        for(int i=0;i<n;i++) {
            cin>>dp[i];
        }    
        
        sort(dp,dp+n);
        
        int i=n-1;
        int con = 0;
        while(i>-1 and m>0) {
            if(dp[i]<=m) {
                m -= dp[i];
                con++;
            }    
            i--;
        }    
        
        if(con%2 ==0) {
            cout<<"Kate\n";
        }    
        else cout<<"Little Deepu\n";
        
        delete[] dp;
    }    
    return 0;
}    
