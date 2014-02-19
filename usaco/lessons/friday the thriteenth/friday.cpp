/*
ID: adityai1
PROG: friday
LANG: C++
*/

#include<cstdio>
#include<iostream>

int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int day[7];

bool isleap(int year) {
	if(year%100==0) {
		if(year%400==0) return true;
		else return false;
	} else {
		if(year%4==0) return true;
		else return false;
	}
}

int main() {
	FILE *fin = fopen("friday.in","r");
	FILE *fout = fopen("friday.out","w");

	int n,year=1900,m=0,end,d=0;
	fscanf(fin,"%d",&n);
	end = year+n-1;
	day[d]++;
	while(year<=end) {
		while(m<12) {		
			if(m==1) {
				if(isleap(year)) {
					d = (d+month[m++]+1)%7;
					day[d]++;
				} else {
					d = (d+month[m++])%7;
					day[d]++;
				}		
			} else {
				d = (d+month[m++])%7;
				day[d]++;
			}
		}
		m=0;
		year++;
	}
	day[d]--;	
	//fprintf(fout,"%d ",day[6]);	
	for(int i=0;i<6;i++) {
		fprintf(fout,"%d ",day[i]);
	}
	fprintf(fout,"%d\n",day[6]);

	fclose(fin);
	fclose(fout);

	return 0;
}
