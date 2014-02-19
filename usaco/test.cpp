#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main() {
	FILE *fin = fopen("test.in","r");
	FILE *fout = fopen("text.out","w");

	int a,b;

	fscanf(fin,"%d %d",&a,&b);	
	fprintf(fout,"%d\n",a+b);
	
	fclose(fin);
	fclose(fout);
	return 0;
}
