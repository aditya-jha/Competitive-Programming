#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main() {
    int a,b;
    
    FILE *fi = fopen("addin.txt","r");
    FILE *fo = fopen("addout.txt","w");
    
    fscanf(fi,"%d %d",&a,&b);
    fprintf(fo,"%d",a+b);
    
    
    fclose(fi);
    fclose(fo);
    
    return 0;
    
}    
