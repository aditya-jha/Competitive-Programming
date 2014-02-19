#include<stdio.h>

int N,i,j,ind=0;
long long int a,b,data[2][100000], max_a=0;
char s[6];

void add(long long int a, long long int b);
void erase(long long int a, long long int b);
void get(long long int a, long long int b);
int search(long long int a, long long int b);

int main() {
	scanf("%d",&N);
	while(N>0) {
		scanf("%s %lli %lli",s,&a,&b);
		if(a>max_a) max_a = a;
		
		//printf("%s %lli %lli\n",s,a,b);
		if(s[0]=='a') add(a,b);
		else if(s[0]=='e') erase(a,b);
		else get(a,b);
		N--;
	}
	return 0;
}


void add(long long int a, long long int b) {
	if(search(a,b)==0) { data[0][ind] = a; data[1][ind] = b; ind++; }
}

void erase(long long int a, long long int b) {
	for(i=0; i<ind; i++) if(data[0][i]==a) if(data[1][i]==b) { data[0][i]=0; data[1][i]=0; }	
}

void get(long long int a, long long int b) {
	int flag=0;
	long long int min_b=1,k;
	for(k=a+1; k<=max_a; k++) {
		for(j=0; j<ind; j++) { 
			if(data[0][j]==k) { 
				if(flag==0) { min_b=data[1][j]; flag = 1; }
				else { if(data[1][j] < min_b) min_b = data[1][j]; }  
			}
		}
		if(flag!=0) break;
	}
	if(flag==0) printf("-1\n");
	else printf("%lli %lli\n",k,min_b);
}

int search(long long int a, long long int b) {
	for(i=0; i<ind; i++) if(data[0][i]==a) if(data[1][i]==b) return 1;	
	return 0;
}
