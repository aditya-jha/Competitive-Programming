#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

FILE *fp,*fout;

int main() {
    fp = fopen("reverse.txt","r");
    fout = fopen("rsol.txt","w");
    char s[100],num[100];
    for(int i=0;i<1500 ;i++) {
        fscanf(fp,"%s %s",s,num);
        cout<<num<<endl;
       if(i%50==0) fprintf(fout,"\n");
        fprintf(fout,"%s,",num);
    }    
    fclose(fp);
    fclose(fout);

    return 0;
}    
