#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

 
#define MOD 1000000007
#define llu long long unsigned
#define lld long long
#define ld long

int arr[1000002];

int gcd(int a, int b) {
	if(b==0) return a;
	else return gcd(b,a%b);
}

int scan_d() {
	int ip=getchar_unlocked(),ret=0;
	for(;ip<'0'||ip>'9';ip=getchar_unlocked());
	for(;ip>='0'&&ip<='9';ip=getchar_unlocked())
		ret=ret*10+ip-'0';

	return ret;
}

int main() {
	int i=1, j=2, sq = i*i + j*j, ss, p;
	for(int k=2;k<1000;) {
		ss = sq; p=2;
		if(arr[ss]!=1) {
			while(ss<=1000000) {
				arr[ss]=1;
				ss = sq*p;
				p++;
			}
		}
		k++;
		sq = 1+ k*k;
		
	}
	
	i=2; j=3; sq = i*i + j*j;
	while(sq<=1000000) {
		while(sq<=1000000) {
			if(arr[sq]!=1) {
				if(gcd(j,i) ==1 ) {
					ss = sq; p=2;
					while(ss<=1000000) {
						arr[ss]=1;
						ss = sq*p;
						p++;
					}	
				}
					
			}
			j++;
			sq = i*i + j*j;
		}
		i++;
		j= i+1;
		sq = i*i + j*j;
	}

	int t;
	t = scan_d();
	while(t--) {
		sq = scan_d();
		
		if(arr[sq]>0) {
			putchar_unlocked('P');putchar_unlocked('E');putchar_unlocked('R');putchar_unlocked('F');putchar_unlocked('E');
			putchar_unlocked('C');putchar_unlocked('T');putchar_unlocked('\n');
		}	
		else {
			putchar_unlocked('I');putchar_unlocked('M');putchar_unlocked('P');putchar_unlocked('E');
			putchar_unlocked('R');putchar_unlocked('F');putchar_unlocked('E');
			putchar_unlocked('C');putchar_unlocked('T');putchar_unlocked('\n');
		}	
	}
	return 0;
}

