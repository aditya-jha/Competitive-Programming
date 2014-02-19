#include<stdio.h>

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
	int t,n,k,count,val,i;
	long int a[101];
	t = scan_d();
	while(t--) {
		count=0;
		n = scan_d();
		
		for(i=0;i<n;i++) a[i] = scan_ld();
		k = scan_d();
		
		val=a[k-1];
		for(i=0;i<n;i++) {
			if(a[i]<val) count++;
		} 
		count++;
		print_d(count);
	}
	return 0;
}
