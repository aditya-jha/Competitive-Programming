#include<iostream>
using namespace std;

#define lld long long
 
int scan_d() {
	int ip=getchar_unlocked(),ret=0;
	for(;ip<'0'||ip>'9';ip=getchar_unlocked());
	for(;ip>='0'&&ip<='9';ip=getchar_unlocked())
		ret=ret*10+ip-'0';

	return ret;
}

void print_lld(lld n) {
	int i=21;
	char output_buffer[22];
	output_buffer[21]='\n';
	
	do { 
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	} while(n);
	
	do {
		putchar_unlocked(output_buffer[i]);
	} while(++i<22);
}


long long dp[10010];
int a[10010];
int n,k;

long long max(long long a, long long b) {
    if(a>b) return a;
    else return b;
}    

long long foo(int i) {
    if(i<n) {
        if(dp[i]==0) {
            dp[i] = max(a[i]+foo(i+k+1), foo(i+1));
            return dp[i];
        }
        else return dp[i];    
    }   
    return 0; 
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;    
    t = scan_d();
    
    while(t--) {
        n = scan_d();
        k = scan_d();
        n++;

        for(int i=1;i<n;i++) a[i] = scan_d();
        
        for(int i=0;i<10010;i++) dp[i]=0;
        
        print_lld(foo(1));
    }    
    
    return 0;
}    
