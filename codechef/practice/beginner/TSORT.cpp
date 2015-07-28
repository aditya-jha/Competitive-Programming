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

int a[1000001];


int main() {
    ios_base::sync_with_stdio(0);
    
    int n,t;
    //cin>>n;
    n = scan_d();
    
    for(int i=0;i<n;i++) {
        //cin>>t;
        t = scan_d();
        a[t]++;
    }    
    
    for(int i=0;i<1000001;i++) {
        //if(a[i]) {
            for(int j=0;j<a[i];j++) print_d(i);//cout<<a[j]<<'\n';
        //}    
    }    
    
    return 0;
    
}    
