#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

#define MOD 1000000007
#define llu long long unsigned
#define lld long long
#define ld long

long long scan_lld() {
	lld ip=getc(stdin),ret=0;
	for(;ip<'0'||ip>'9';ip=getc(stdin));
	for(;ip>='0'&&ip<='9';ip=getc(stdin))
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


int main() {
	lld n,k;
        n = scan_lld();
        k = scan_lld();
        
        lld c[100005], sum[100005];

        for (lld i = 1; i <= n; i++) {
                c[i] = scan_lld();
        }
        
        sort(c + 1, c + n + 1);
        sum[0] = 0;
        
        for (lld i = 1; i <= n; i++) {
                sum[i] = sum[i - 1] + c[i];
        }
        
        lld temp = 0;
        for (lld i = 1; i <= k; i++) {
                temp += (i - 1) * c[i];
                temp -= (k - i) * c[i];
        }
        
        lld res = temp;
        lld l = 2, r = k + 1;
        for (; r <= n; l++, r++) {
                temp += (k - 1) * c[r] - (sum[r - 1] - sum[l - 1]);
                temp -= (sum[r - 1] - sum[l - 1]) - (k - 1) * c[l - 1];
                res = min(res, temp);
        }
        print_lld(res);
        
        return 0;
        
}
