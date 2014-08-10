#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

const int MOD = 1000000007;

vector<vector<int> > v(11, vector<int>(101));
vector<vector<int> > dp(1025, vector<int>(101));

void initial() {
    for (int i=0; i<11; i++) {
        for (int j=0; j<101; j++){
            v[i][j] = 0;
        }
    }
    
    for (int i=0; i<1025; i++) {
        for (int j=0; j<101; j++) {
            dp[i][j] = -1;
        }
    }
}    

int solve(int val, int n, int index) {
    if (index > 100) {
        return (val%(1<<11)==0);
    }    

    if (dp[val][index] != -1) {
        return dp[val][index];
    }    
    
    dp[val][index] = solve(val,n,index+1);
    
    int *a = new int[11];
    int *b = new int[11];
    
    for (int i=1; i<=n; i++) {
        a[i] = v[i][index];
        b[i] = (val>>(i-1))%2;
    }
    
    for (int i=1; i<=n; i++) {
        if (a[i] && b[i]) {
            dp[val][index] = (dp[val][index] + solve(val - (1<<(i-1)),n,index+1))%MOD;
        }
    }        
    
    delete[] a,b;
    
    return dp[val][index];
}    

int main() {    
    
    int t,n,temp;
    char c;
    scanf("%d",&t);
    
    while(t--) {
        
        initial();
        
        scanf("%d",&n);
        c = getchar();
                
        for(int i=1;i<=n;i++) {
            scanf("%d",&temp);
            v[i][temp] = 1;
            
            c = getchar();
            while(c != '\n' and c!=EOF) {
                scanf("%d",&temp);
                v[i][temp] = 1;
                c = getchar();
            }    
        }    
            
        printf("%d\n",solve((1<<n)-1,n,1));
    }    
    
    return 0;
}    
