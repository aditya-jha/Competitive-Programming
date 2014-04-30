#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;

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

int main() {
    int t;
    t = scan_d();
    
    while(t--) {
        int n, temp, A, B;
        A = scan_d();
        B = scan_d();
        n = scan_d();
        
        int *dp = new int[n];        
        for(int i=0;i<n;i++) {
            dp[i] = scan_d();            
        }    
        
        sort(dp,dp+n);
        
        int sumA=0, sumB=0,i=0, valA, valB;
        while(sumA <= A and i<n) {
            sumA += dp[i];
            i++;   
        }    
        if(sumA > A) {
            sumA -= dp[i-1];
        }    
        valA = i-1;
        A = A-sumA;
        valA += A/dp[0];
        
        i=0;
        while(sumB <= B and i<n) {
            sumB += dp[i];
            i++;
        }    
        if(sumB>B) sumB -= dp[i-1];
        valB=i-1;
        B -= sumB;
        valB += B/dp[0];
        
        if(valA > valB) {
            printf("Raghu Won\n");
        }    
        else if(valB < valB) printf("Sayan Won\n");
        else printf("Tie\n");
        
    }    
    
    return 0;
}    
