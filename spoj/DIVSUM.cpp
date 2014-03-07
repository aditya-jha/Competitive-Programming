#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;

bool primes[500001];


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

void sieve() {
    for(int i=2;i<500001;i++) primes[i] = true;
    
    int lim = (int)ceil(sqrt(500001.0));
    for(int i=2;i<=lim;i++) {
        if(primes[i]) {
            for(int j=i*i;j<500001;j+=i) primes[j] = false;
        }    
    }    
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    sieve();
    
    int t,n;
    double rt;
    long long sum=0;
    
    t = scan_d();
    while(t--) {
        n = scan_d();
        if(n==1) { putchar_unlocked('0'); putchar_unlocked('\n'); continue; }
        sum=1;
        if(primes[n]) { putchar_unlocked('1'); putchar_unlocked('\n'); }
        else {
            rt = ceil(sqrt((double)n));
            for(int i=2;i<rt;i++) {
                if(n%i == 0) {
                    sum += i;
                    sum += (n/i);
                }
            }
            if(n/rt == rt) sum += rt;        
            
            print_d(sum);
        }    
    }    
    
    return 0;
}    
