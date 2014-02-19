#include<stdio.h>

#define abs(a) (a>-1?a:-a)
#define MOD 1000000007
#define llu long long unsigned
#define lld long long
#define ld long
 
int scan_d() {
	int ip=getchar_unlocked(),ret=0;
	for(;ip<'0'||ip>'9';ip=getchar_unlocked());
	for(;ip>='0'&&ip<='9';ip=getchar_unlocked())
		ret=ret*10+ip-'0';

	return ret;
}


long scan_ld() {
	ld ip=getc(stdin),ret=0;
	for(;ip<'0'||ip>'9';ip=getc(stdin));
	for(;ip>='0'&&ip<='9';ip=getc(stdin))
	ret=ret*10+ip-'0';
	
	return ret;
}

void print_ld(ld n) {
	int i=11;
	char output_buffer[12];output_buffer[11]='\n';
	
	do {
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	} while(n);
	
	do {
		putchar_unlocked(output_buffer[i]);
	} while(++i<12);
}

long int s[2001] = {0};
int k;

void fill() {
	int i;
	for(i=1;i<=2000;i++) s[i] = (i*(i+1))/2;
}

int binarysearch(long int n, int low, int high) {
	if(n<s[low] || n>s[k]) return 0;
	else {
		int mid = (low+high)/2;
		if(n==s[mid]) return 1;
		else if(n>s[mid]) return binarysearch(n,mid+1,high);
		else return binarysearch(n,low,mid-1);
	}
}

int main() {
	fill();
    	int t;
    	long int B,i;
    	t = scan_d();
    
    	while(t--) {
    		long int sum = 0;
    		k = scan_d();
    		B = scan_ld();
    		
    		sum = (k*(k+1))/2;
    		
    		if(binarysearch(B,1,k)) sum--;
    		
    		print_ld(sum);
    	}
    	
    	return 0;
}
    
    
