/*
ID: adityai1
PROG: ride
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>

using namespace std;

#define MOD 47

int main() {
	FILE *fin=fopen("ride.in","r"), *fout=fopen("ride.out","w");
	
	char *comet = new char[10];
	char *group = new char[10];

	fscanf(fin,"%s",comet);	
	fscanf(fin,"%s",group);	

	int a=1,b=1;
	
	for(int i=0;comet[i];i++) {
		a*=(comet[i]-64);
	}
	a=a%MOD;
	for(int i=0;group[i];i++) {
		b*=(group[i]-64);
	}
	b=b%MOD;

	if(a==b) fprintf(fout,"GO\n");
	else fprintf(fout,"STAY\n");

	return 0;
}
