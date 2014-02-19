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

long scan_ld() {ld ip=getc(stdin),ret=0;for(;ip<'0'||ip>'9';ip=getc(stdin));for(;ip>='0'&&ip<='9';ip=getc(stdin))ret=ret*10+ip-'0';
	return ret;}
void print_lld(lld n) {int i=21;char output_buffer[22];output_buffer[21]='\n';do { output_buffer[--i]=(n%10)+'0';n/=10;} while(n);	
	do {putchar_unlocked(output_buffer[i]);} while(++i<22);}

long long int binary(long long int n) {
	long long int temp,val;
	val=0;
	for(double i=0;n!=0;i++) {
		temp = n%2;
		n=n/2;
		val+= temp*(long long int)pow(10.0,i);
	}
	return val;
}

long long int modexp(long long int x,long long int y) {
	if(y==0) return 1;
	
	long long int z = modexp(x,y/2);
	
	if(y%2==0) return (z*z)%MOD;
	else return (((x*z)%MOD)*z)%MOD;
}

int main() {
	long int t,n;
	long long int val,r,q;

	t=scan_ld();

	while(t--) {
		r=0;q=0;
		n=scan_ld();
		vector<int> v;
		
		while(n!=0) {
			v.push_back(n%2);
			n=n/2;
		}
		
		if(v.size()>16) {
			int i,j;
			for(i=0;i<4;i++) { r += v[i]*(long long int)pow(10.0,double(i));}
			for(j=0;i<v.size();i++,j++) { q += v[i]*(long long int)pow(10.0,double(j)); }
			
			val = (modexp(modexp(4,q),10000)*modexp(4,r))%MOD;

			print_lld(val);
		} else {
			for(int i=0;i<v.size();i++) { q += v[i]*(long long int)pow(10.0,double(i)); }
			val = modexp(4,q);
			print_lld(val);
		}
	}
	

	return 0;
}

