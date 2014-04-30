#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> f,s;

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

int solve(int a, int b) {
    f.clear();
    s.clear();
    
    while(a>0) {
        f.push_back(a);
        a >>= 1;
    }    
    while(b>0) {
        s.push_back(b);
        b >>= 1;
    }        
    
    for(int i=0;i<f.size();i++) {
        for(int j=0;j<s.size();j++) {
            if(f[i] == s[j]) {
                return i+j;
            }    
        }    
    }    
    
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    int n;
    n=scan_d();
    
    while(n--) {
        int a,b;
        a=scan_d();
        b=scan_d();

        print_d(solve(a,b));
    }    
    return 0;
}    
