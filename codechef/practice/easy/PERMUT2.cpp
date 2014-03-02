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
    ios_base::sync_with_stdio(0);
    
    int n;
    int a[100001];
    
    //cin>>n;
    n = scan_d();
    
    while(n!=0) {
        
        for(int i=1;i<=n;i++) a[i] = scan_d(); //cin>>a[i];
        
        int flag = 0;
        for(int i=1;i<=n;i++) {
            if(a[a[i]] != i) {
                flag = 1;
                break;
            }    
        }    
        
        if(flag == 0) {
            printf("ambiguous\n");
            //cout<<"ambiguous\n";
        }    
        else {
            printf("not ambiguous\n");
            //cout<<"not ambiguous\n";
        }    
        
        //cin>>n;
        n = scan_d();
    }    
    
    return 0;
}  
