/*
ID: adityai1
PROG: gift1
LANG: C++
*/

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>

using namespace std;

struct people {
	char name[20];
	int given;
	int rec;
};

struct people group[100];

int search(char s[],int n) {
	for(int i=0;i<n;i++) {
		if(strcmp(s,group[i].name)==0) return i;
	}
}

int main() {
//	ios_base::sync_with_stdio(0);

	FILE *fin = fopen("gift1.in","r");
	FILE *fout = fopen("gift1.out","w");

	int n,a,b,index,gg;
	fscanf(fin,"%d",&n);	
	
//	people group[15];
	char alias[20];

	for(int i=0;i<n;i++) {	
		fscanf(fin,"%s",group[i].name);
	}
	
	for(int i=0;i<n;i++) {
		fscanf(fin,"%s",alias);		
		index = search(alias,n);
		
		fscanf(fin,"%d %d",&a,&b);
		
		if(b==0) continue;
		
		gg=(int)a/b;
		group[index].given = gg*b;
	
//		cout<<"name: "<<alias<<", index: "<<index<<", given: "<<a/b * b<<endl;
	
		for(int j=0;j<b;j++) {
			fscanf(fin,"%s",alias);
			index = search(alias,n);
			group[index].rec += gg;
		}
	}

	for(int i=0;i<n;i++) {
		fprintf(fout,"%s %d\n",group[i].name,group[i].rec-group[i].given);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}
