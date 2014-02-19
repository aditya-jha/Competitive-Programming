#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<cstring>
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

vector<long long> v;
long long digit[501];

void preprocess() {
	v.push_back(9);
	int index=1;
	long long num;
	
	for(int i=1;i<15;i++) {
		num = 9*(long long)pow(10.0,i);
		v.push_back(num);
		for(int j=0;j<index;j++) {
			v.push_back(num+v[j]);
		}
		index = v.size();
	}
	
	digit[0]=0;
	for(int i=1;i<501;i++) {
		for(int j=0;j<v.size();j++) {
			if(v[j]%i == 0) {
				digit[i] = v[j];
				break;
			}
		}
	}
	
}

int main() {
	preprocess();
	
	int t,n;
	t = scan_d();
	
	while(t--) {
		n = scan_d();
		print_lld(digit[n]);
	}
	
	return 0;
}
