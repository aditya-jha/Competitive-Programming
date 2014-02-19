#include<iostream>
#include<cstdio>
using namespace std;

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

#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)

int type[1000010];
bool index[1000010];
int a[500010];

int main() {
    
    for(int i=0;i<1000010;i++) {
        type[i] = 1000010;
        index[i] = false;
    }    
    
    int n = scan_d(), k = scan_d();
    n++;    

    int diff, sol = 1000010;
    for(int i=1;i<n;i++) {
        a[i] = scan_d();        
    }    
    
    int minim;
    for(int i=1;i<n;i++) {
        index[a[i]] = 1;
        minim = min(i,n-i);
        type[a[i]] = min(minim,type[a[i]]);
    }    
    
    for(int i=1;i<n;i++) {
        if(a[i] >= k) continue;
        diff = k - a[i];
        if(diff == a[i]) continue;
        
        if(index[diff]) {
            sol = min(sol, max(type[diff], type[a[i]]));
        }    
    }    
    
    if(sol == 1000010) cout<<"-1\n";
    else print_d(sol);
    
    return 0;
}     
