#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<cstring>
#include<string>
 
using namespace std;
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
 
long long unsigned scan_llu() {
	llu ip=getc(stdin),ret=0;
	for(;ip<'0'||ip>'9';ip=getc(stdin));
	for(;ip>='0'&&ip<='9';ip=getc(stdin))
	ret=ret*10+ip-'0';
	return ret;
}
 
void print_llu(llu n) {
	int i=21;
	char output_buffer[22];
	output_buffer[21]=' ';
	do {
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	} while(n);
 
	do {
		putchar_unlocked(output_buffer[i]);
	} while(++i<22);
}
 
const int maxn = 1001;
 
int t,i,j,ind,k,N,len,rev;
llu L[maxn],A,B,C,num,temp,x,add;
char s[maxn];
 
llu multiply(llu a, llu b) {
	if(b==0) return 0;
	llu z = multiply(a,(b>>1));
	if(b%2==0) return (z<<1)%C;
	else return (a+(z<<1)%C)%C;
}
 
llu process(llu x,llu add) {
	llu total = L[ind];
	total = multiply(total,x);
	return (total+add)%C;
}
 
int main() {
	t = scan_d();
	while(t--) {
		N = scan_d();
		
		for(i=0;i<N;i++) L[i] = scan_llu();
		A = scan_llu(); B = scan_llu(); C = scan_llu();
		scanf("%s",s);
		
		A = A%C; B = B%C;
		
		rev = 0; i=0; ind = 0; j=N-1; x=1; add=0;
		
		for(k=0;k<N;k++) {
			if(s[k] == 'A') {
				if(rev) { ind = j; j--; }
				else { ind = i; i++; }	
				
				add = (add+A)%C;
				
				print_llu(process(x,add));
			}
			else if(s[k] == 'M') {
				if(rev) { ind = j; j--; }
				else { ind = i; i++; }	
				
				x = multiply(x,B);
				add = multiply(add,B);
				
				print_llu(process(x,add));
			}
			else {	
				if(rev) { ind = i; i++; rev = false;}	
				else { ind = j; j--; rev = true; }
				
				print_llu(process(x,add));
			}
		}
		
		putchar('\n');
	}
	
	return 0;
}
