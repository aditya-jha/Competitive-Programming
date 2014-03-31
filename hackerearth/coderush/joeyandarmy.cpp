#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<cstring>

using namespace std;

#define lld long long

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
    
    int n,k;
    //cin>>n>>k;
    n = scan_d();
    k = scan_d();
    
    int *mine = new int[n+1];
    for(int i=1;i<=n;i++) mine[i] = scan_d();//cin>>mine[i];
    
    int k1,k2,l,r;
    long long counter;
    
    while(k--) {
        counter=0;
        cin>>k1>>k2>>l>>r;
        
        if(l>r) swap(l,r);
        
        for(int i=l;i<=r;i++) {
            if(mine[i]>= k1 and mine[i]<=k2) counter += mine[i];
        }    
        
        print_lld(counter);
        //cout<<counter<<'\n';
    }    
    
    delete[] mine;
    return 0;
}    
