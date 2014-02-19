#include<stdio.h>

int scan_d() {int ip=getchar_unlocked(),ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked());for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return ret;}

int main() {
    int t,h2,m1,m2,s1,s2,r;
    t=scan_d();
    //scanf("%d",&t);   
    while(t--) {
        r=scan_d();
        m1=scan_d();
        s1=scan_d();
        h2=scan_d();
        m2=scan_d();
        s2=scan_d();
        
        //scanf("%d %d %d %d %d %d",&r,&m1,&s1,&h2,&m2,&s2);   
        r = (h2-r)*3600 + (m2-m1)*60 + (s2-s1);
        
        r = r%400;
        if(r<=99) { putchar('S'); putchar('\n'); }// printf("S\n");
        else if(r>=100 && r<=199) { putchar('C'); putchar('\n'); }//printf("C\n");
        else if(r>=200 && r<=299) { putchar('S'); putchar('\n'); }//printf("S\n");
        else { putchar('C'); putchar('\n'); }//printf("C\n");
        
    }    
    //system("pause");
    return 0;
}    
