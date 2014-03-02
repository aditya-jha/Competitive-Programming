#include<iostream>
#include<cstdio>

using namespace std;

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

int a[1001][1001],b[1001][1001],match[1001][1001];

int main() {
    int t,n,m,q,x1,y1,x2,y2;
    
    t = scan_d();
    
    while(t--) {
        n = scan_d();
        m = scan_d();
        q = scan_d();
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) a[i][j] = scan_d();
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                b[i][j] = scan_d();
                if(a[i][j] == b[i][j]) match[i+1][j+1] = 1;
                else match[i+1][j+1] = 0;
        }        
        
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                match[i][j] += match[i][j-1];
            }    
        }    
        
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                cout<<match[i][j]<<" ";
            }    
            cout<<endl;
        }
        
        
        while(q--) {
            int sum = 0;
            x1 = scan_d(); y1 = scan_d(); x2 = scan_d(); y2 = scan_d();
            
            for(int i=x1;i<=x2;i++) {
                sum += (match[i][y2] - match[i][y1-1]);
            }
            print_d(sum);    
        }    
    }    
}    
    return 0;
}    
