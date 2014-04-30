#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

int sol[10][100002];
char s[100002];

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

void preProcess(char s[], int n) {
	int *dp = new int[n];
	for(int i=0;i<n;i++) dp[i] = (int)s[i]-'0';

    for(int i=0;i<10;i++) {
        int add=0;
        int sub=0;
        for(int j=0;j<n;j++) {
            if(dp[j]-i > 0) add += dp[j]-i;
            else sub += dp[j]-i;
            
            sol[i][j+1] = add-sub;
        }    
    }    
    delete[] dp;
}    

int main() {
   
    int n,m,x,digit;
    n = scan_d();
    m = scan_d();
    
    scanf("%s",s);
    
    preProcess(s,n);
    
    while(m--) {
    	x = scan_d();
    	digit = s[x-1]-'0';
    	print_d(sol[digit][x-1]);
    }
    return 0;
    
}    
