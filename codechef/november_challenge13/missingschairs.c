#include<stdio.h>
#include<stdlib.h>

#define MOD 1000000007
#define llu long long unsigned
#define lld long long
#define ld long

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

long long int modexp(long int y) {
	if(y==0) return 1;
	
	long long int z = modexp(y/2);
	
	if(y%2==0) return (z*z)%MOD;
	else return (2*z*z)%MOD;
}

int main() {
	int t;
	long int n;
	//scanf("%d",&t);
	t = scan_d();
	while(t--) {
		//scanf("%ld",&n);
		n = scan_ld();
		//long long int val = modexp(n)-1;
		print_lld(modexp(n)-1);
		//printf("%lld\n",modexp(n)-1);
	
	}
	return 0;
}
