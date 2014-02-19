#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

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

int mat[310][310];
int n,q,x1,x2,sy1,sy2,sol;

int rect() {
    	int *a = new int[12];   
    	for(int i=1;i<11;i++) a[i]=0;
    
    	for(int i=x1;i<x2;i++) {
        	for(int j=sy1;j<sy2;j++) {
            		a[mat[i][j]]++;
        	}    
    	}    
    
    	int count=0;
    	for(int i=1;i<11;i++) if(a[i]) count++;
    
    	delete[] a;
    	return count;
}

int main() {
    //ios_base::sync_with_stdio(0);
    
    //cin>>n;
    	n = scan_d();
    	for(int i=0;i<n;i++) {
        	for(int j=0;j<n;j++) mat[i][j]=scan_d();//cin>>mat[i][j];
    	}    
    
    	//cin>>q;
    	q = scan_d();
    	
    	for(int i=0;i<q;i++) {
	        //cin>>x1>>sy1>>x2>>sy2;
	        x1=scan_d();
	        sy1=scan_d();
	        x2=scan_d();
	        sy2=scan_d();
        	x1--; sy1--;
        	sol=rect();
        	print_d(sol);
        	//cout<<rect()<<'\n';   
    	}    
    
    	return 0;
}    
