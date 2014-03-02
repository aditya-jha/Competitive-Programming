#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define min(a,b) (a<b?a:b)

int scan_d() {
	int ip=getc(stdin),ret=0;
	for(;ip<'0'||ip>'9';ip=getc(stdin));
	for(;ip>='0'&&ip<='9';ip=getc(stdin))
		ret=ret*10+ip-'0';

	return ret;
}
void print_d(int n) {
	int i=10;
	char output_buffer[11];output_buffer[10]='\n';
	
	do {
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	} while(n);
	
	do {
		putchar(output_buffer[i]);
	} while(++i<11);
}

int n,d,cost[10000];

int treasure() {
    int *dp = new int[n+1];
    dp[0] = cost[0];
    //for(int i=1;i<n;i++) dp[i] = 1000000000;
    
    for(int i=1;i<n;i++) {
        dp[i] = dp[i-1]+cost[i];
        for(int j=i-2;j>-1 and j>=i-d;j--) {
            dp[i] = min(dp[j]+cost[i], dp[i]);
        }    
    }  
    
    //for(int i=1;i<n;i++) cout<<dp[i]<<" ";
    //cout<<endl;
    
    int ans = dp[n-1];
    delete[] dp;
    
    return ans;
    
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    //cin>>t;
    t = scan_d();
    
    while(t--) {
        //cin>>n>>d;
        n = scan_d(); d = scan_d();
        
        for(int i=0;i<n;i++) cost[i] = scan_d(); //cin>>cost[i];
        
        //cout<<treasure()<<'\n';
        print_d(treasure());
    }    
    
    return 0;
}    
