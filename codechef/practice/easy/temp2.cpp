#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define min(a,b) (a<b?a:b)

int scan_d() {
	int ip=getc(stdin),ret=0;
	for(;ip<'0'||ip>'9';ip=getc(stdin));
	for(;ip>='0'&&ip<='9';ip=getc(stdin))
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
		putchar(output_buffer[i]);
	} while(++i<11);
}

int n,d,cost[10000];

int find(int a, int b) {
    int val = cost[a], ind = a;
    for(int i=a+1;i<n and i<=b;i++) {
        if(cost[i]<=val) {
            ind = a;
            val = cost[i];
        }    
    }    
    cout<<val<<endl;
    return val;
}    

int foo() {
    int index=0;
    int sum = cost[0];
    while(true) {
        if((index+d) >= (n-1)) {
            sum += cost[n-1];
            break;
        }    
        index = find(index+1,index+d);
        sum += cost[index];
        cout<<index<<endl;
    }    
    return sum;
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    t = scan_d();
    
    while(t--) {
        n = scan_d(); d = scan_d();
        
        for(int i=0;i<n;i++) cost[i] = scan_d();
        
        print_d(foo());
    }    
    
    return 0;
}    
