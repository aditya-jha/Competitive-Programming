#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main() {
	FILE *fp = fopen("qtree.txt","w");
	
	fprintf(fp,"%d\n",100000);
	
	for(int i=2;i<100001;i++) fprintf(fp,"1 %d\n",i); 
	
	fclose(fp);
	
	return 0;
	
}
