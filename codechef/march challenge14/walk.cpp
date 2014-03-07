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
int walk(int a[], int n) {
    int sol = a[n-1];
    for(int i=n-2;i>-1;i--) {
        sol++;
        if(a[i]>sol) sol = a[i];
    }    
    return sol;
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    int t,n;
    t=scan_d();//cin>>t;
    
    while(t--) {
        //cin>>n;
        n = scan_d();
        
        int *a = new int[n];
        for(int i=0;i<n;i++) a[i] = scan_d(); //cin>>a[i];
        
        //cout<<walk(a,n)<<'\n';
        print_d(walk(a,n));
        
        delete[] a;
    }    
    
    return 0;
}    
