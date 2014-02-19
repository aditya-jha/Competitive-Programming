#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

#define MOD 1000000007
#define llu long long unsigned
#define lld long long
#define ld long
 
//end of definitions
 
 
//fast input
 
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


long long scan_lld() {
	lld ip=getc(stdin),ret=0;
	for(;ip<'0'||ip>'9';ip=getc(stdin));
	for(;ip>='0'&&ip<='9';ip=getc(stdin))
		ret=ret*10+ip-'0';
	
	return ret;
}

long long unsigned scan_llu() {
	llu ip=getc(stdin),ret=0;
	for(;ip<'0'||ip>'9';ip=getc(stdin));
	for(;ip>='0'&&ip<='9';ip=getc(stdin))
		ret=ret*10+ip-'0';
	
	return ret;
}
 
//end of fast input
 
//fast output
 
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


void print_llu(llu n) {
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
 
//end of fast output


llu gcd(llu a, llu b) {
	if(b==0) return a;
	else return gcd(b,a%b);
}

llu modulo(llu a,llu b, llu m) {
	if(b==0) return 1;
	llu z = modulo(a,b/2,m);
	
	if(b%2==0) return (z*z)%m;
	else return (a*z*z)%m;
}

int main() {
	ios_base::sync_with_stdio(0);
	
	unsigned long long int n,k,m,i,sum;
		
	n = scan_llu();
	k = scan_llu();
	m = scan_llu();
	sum = 1;
	if(n==1) cout<<"0\n";
	else {
		if(n%2==0) {
			for(i=3;i<n;i+=2) {
				if(gcd(i,n) == 1) sum+=(modulo(i,k,m));
			}
		} else {
			for(i=2;i<n;i++) {
				if(gcd(i,n) == 1) sum+=(modulo(i,k,m));
			}
		}
		print_llu(sum);
	}
	
	return 0;
}
