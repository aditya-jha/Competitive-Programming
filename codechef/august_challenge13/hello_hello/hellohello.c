#include<stdio.h>
#include<stdlib.h>

int scan_d() {
	int ip=getchar_unlocked(),ret=0;
	for(;ip<'0'||ip>'9';ip=getchar_unlocked());
	for(;ip>='0'&&ip<='9';ip=getchar_unlocked())
		ret=ret*10+ip-'0';

	return ret;
}

void print_d(int n) {
	int i=10;
	char output_buffer[11];output_buffer[10]='\n';
	
	do {
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	} while(n);
	
	do {
		putchar_unlocked(output_buffer[i]);
	} while(++i<11);
}

void swap(int *a,int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int check(int a[], int start, int end, int z) {
	if(z >= (end - start)) {
		int i=0;
		for(i=start; i<=end; i++) {
			if(a[i] != 0) return 0;
		}
		return 1;
	} else return 0;
}

int main() {
	int n = scan_d(),m = scan_d();
	int a[n],l[m],r[m],k,i,track[m];

	for(i=0; i<n; i++) a[i] = scan_d();
	for(i=0; i<m; i++) { l[i] = scan_d(); r[i] = scan_d(); track[i]=0; }
	k = scan_d();

	int x=0,y=0,ans=0,count=0,zero=0,j=0;

	while(k>0) {
		//count = 0;
		x = scan_d();
		y = x + ans;
		//if(a[y-1] !=0) 
			a[y-1] = a[y-1] - 1;
		
		if(a[y-1] == 0) {
			zero++;			
			for(i=j; i<m; i++) {
				if(y>=l[i] && y<=r[i]) {
					if(check(a,l[i]-1,r[i]-1,zero) != 0) {
						ans++;
						track[i] = 1;
						swap(&l[i],&l[j]);
						swap(&r[i],&r[j]);
						swap(&track[i],&track[j]);
						j++;
					}
				}
			}
		}

		//for(i=0; i<m; i++) printf("track[%d]: %c\n",i,track[i]);

		print_d(ans);
		k--;
	}
	return 0;
}
