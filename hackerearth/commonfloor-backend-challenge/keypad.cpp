#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

long long total=0;

bool myfunction (int i,int j) { return (i>j); }

int perform(int dp[], int t, int position, int index, int n) {
    
    while(t-- and index<n) {
        total += (position*dp[index++]);
        
    }    
    
    return index;
}

int main() {
    ios_base::sync_with_stdio(0);
    
    int n,k,tot=0,temp;
    cin>>n;
    
    int *dp = new int[n];
    for(int i=0;i<n;i++) cin>>dp[i];
    
    cin>>k;
    
    int *key = new int[51];
    for(int i=0;i<51;i++) key[i] = 0;
    for(int i=0;i<k;i++) {
        cin>>temp;
        for(int i=1;i<=temp;i++) key[i]++;
        tot += temp;
    }    
    
    if(tot<n) {
        cout<<"-1\n";
        return 0;
    }    
    
    sort(dp,dp+n,myfunction);
    
    int index = 0,i=1;
    
    while(index<n and i<51) {
        if(key[i]>0) {
            index = perform(dp, key[i], i, index, n);
            i++;
        }
        else i++;    
    }    
    
    cout<<total<<'\n';
    
    return 0;
}    
