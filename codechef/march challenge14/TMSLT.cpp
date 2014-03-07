#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
 
const int MOD = 1000000;
 
int n,a,b,c,d;
 
int scan_d() {
	int ip=getchar_unlocked(),ret=0;
	for(;ip<'0'||ip>'9';ip=getchar_unlocked());
	for(;ip>='0'&&ip<='9';ip=getchar_unlocked())
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
		putchar_unlocked(output_buffer[i]);
	} while(++i<11);
}
 
int dp[1000000];
 
int computeStrength() {
    for(int i=0;i<1000000;i++) dp[i]=0;
    
    dp[d]++;// = d;
    long long int hold = d;
    
    int strengthA=0,strengthB = 0;
    
    for(int i=1;i<n;i++) {
        hold = (a*hold*hold + b*hold + c)%MOD;
        dp[hold]++;
    }    
    
    for(int i=0;i<1000000;i++) dp[i] = dp[i]%2;
    
    int j=0;
    for(int i=1000000-1;i>-1;i--) {
        if(dp[i]==1) {
            if(j%2==0) {
                strengthA += i;
            }    
            else strengthB += i;
            
            j++;
        }    
    }    
    
    return strengthA-strengthB;
}    
 
int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    t = scan_d();//cin>>t;
    
    while(t--) {
        //cin>>n>>a>>b>>c>>d;
        n = scan_d();
        a = scan_d();
        b = scan_d();
        c = scan_d();
        d = scan_d();
        
        print_d(computeStrength());     
    }  
    
    return 0;  
}     
