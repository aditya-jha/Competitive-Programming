#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
     
using namespace std;
     
void initialize(char rep[]) {
    for(int i=0;i<150;i++) rep[i] = ' ';
}

int main() {
    int t,n;
    char c,s[1000011],p,rep[150];
    
    scanf("%d",&t);
    
    while(t--) {
        initialize(rep);
        scanf("%d",&n);
        
        while(n--) {
            getchar();
            scanf("%c %c",&c,&p);
            rep[(int)c] = p;
        }
        
        getchar();  
        scanf("%s",s);

        int len = strlen(s);
        int dot=-1;
        
        for(int i=0;i<len;i++) {
            if(rep[(int)s[i]] != ' ') {
                s[i] = rep[(int)s[i]];
            }    
        }
        
        for(int i=0;i<len;i++) if(s[i] == '.') dot = i;
        
        int start=0, end=len-1;
        while(s[start]=='0') start++;
        if(dot!=-1) {
            while(s[end]=='0') end--;
        }    
        
        if(s[end]=='.') end--;
        
        if(start>end) putchar('0');
        else for(int i=start;i<=end;i++) putchar(s[i]);
        putchar('\n') ;
    }

    return 0;
} 
