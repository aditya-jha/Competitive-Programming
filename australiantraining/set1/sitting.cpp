#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main() {
    FILE *fin = fopen("sitin.txt","r");
    FILE *fout = fopen("sitout.txt","w");
    
    long long a,b,s,t,x;
    
    fscanf(fin,"%lld %lld %lld",&a,&b,&s);
    t = a*b;
    if(t>s) {
        x=0;
        t = s;
    }    
    else x = s-t;
    fprintf(fout,"%lld %lld\n",t,x);
    
    fclose(fout);
    fclose(fin);
    
    return 0;
}    
