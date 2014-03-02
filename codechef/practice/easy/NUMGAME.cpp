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

int main() {    
    int t,n;
    
    t = scan_d();
    
    while(t--) {
        n = scan_d();
        
        if(n&1) {
            putchar_unlocked('B');
            putchar_unlocked('O');
            putchar_unlocked('B');
            putchar_unlocked('\n');
        }    
        else {
            putchar_unlocked('A');
            putchar_unlocked('L');
            putchar_unlocked('I');
            putchar_unlocked('C');
            putchar_unlocked('E');
            putchar_unlocked('\n');
        }    
    }    
    
    return 0;
}    
