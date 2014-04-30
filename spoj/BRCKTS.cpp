#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>

using namespace std;

char str[30011];

struct node {
    int to_open, to_close;
    node() {
        to_open = to_close = 0;
    }    
} ST[4*(30001) + 1];  

void buildST(int ss, int se, int index) {
    if(ss == se) {
        if(str[ss] == '(') {
            ST[index].to_open = 0;
            ST[index].to_close = 1;
        }    
        else {
            ST[index].to_open = 1;
            ST[index].to_close = 0;
        }    
    }    
    else {
        int left = 2*index + 1, right = left+1;
        int mid = ss+(se-ss)/2;
        
        buildST(ss,mid,left);
        buildST(mid+1,se,right);
        
        int for_closing_right = min(ST[left].to_close, ST[right].to_open);
        
        ST[index].to_close = ST[left].to_close - for_closing_right + ST[right].to_close;
        ST[index].to_open = ST[right].to_open - for_closing_right + ST[left].to_open;
        
    }    
}    

void update(int ss, int se, int i, int index) {
    if(ss == se) {
        if(str[i] == '(') {
            ST[index].to_close--;
            ST[index].to_open++;
            str[i] = ')';
        }    
        else {
            ST[index].to_close++;
            ST[index].to_open--;
            str[i] = '(';
        }    
    }    
    else {
        int left = 2*index + 1, right = left+1;
        int mid = ss+(se-ss)/2;
        
        if(mid >= i) {
            update(ss, mid, i, left);
        }    
        else {
            update(mid+1,se,i,right);
        }    
        
        int for_closing_right = min(ST[left].to_close, ST[right].to_open);
        
        ST[index].to_close = ST[left].to_close - for_closing_right + ST[right].to_close;
        ST[index].to_open = ST[right].to_open - for_closing_right + ST[left].to_open;
        
    }    
}    

int scan_d() {
	int ip=getchar_unlocked(),ret=0;
	for(;ip<'0'||ip>'9';ip=getchar_unlocked());
	for(;ip>='0'&&ip<='9';ip=getchar_unlocked())
		ret=ret*10+ip-'0';

	return ret;
}

int main() {
    
    int n,m,k;
    
    for(int i=1;i<11;i++) {
        printf("Test %d:\n",i);
        n = scan_d();
        //cin>>n;
        n--;
        
        scanf("%s",str);
        
        buildST(0,n,0);
        
        m = scan_d();
        //cin>>m;
        
        while(m--) {
            k =scan_d();
            //cin>>k;
            if(k==0) {
                if(ST[0].to_close == 0 and ST[0].to_open == 0) {
                   printf("YES\n");
                }
                else {
                    printf("NO\n");
                }
            }
            else {
                update(0,n,k-1,0);
            }
        }
    }            
    
    return 0;
}    
