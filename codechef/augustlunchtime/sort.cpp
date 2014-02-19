#include<iostream>
#include<cstdio>
#include<vector>
#include<new>
using namespace std;

int n;//,b[2001];
unsigned long long int count=0;

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

void sort(int a[],int b[], int p, int q) {
	int length = q-p+1;
	int index_less=1,index_more=2*(length+1/2) +1;
	int pivot = a[(length+1)/2];
	b[2*(length+1)/2] = pivot;
	if(length<=1);
	else {
		for(int i=1; i<=length; i++)	 {
			count++;
			if(a[i]<pivot) { b[index_less] = a[i]; index_less++; }
			else if(a[i]>pivot) { b[index_more] = a[i]; index_more++; }
		}
		int i,k;
		for(i=1; i<index_less; i++) a[i] = b[i];
   		k=i;
		for(int j=2*(length+1/2) +1; j<index_more; j++) { a[i] = b[j];	 i++; }
		sort(a,b,1,index_less-1);
		sort(a,b,k,index_more-1);	
	}
}


int main() {
	n = scan_d();
	int a[n+1];
	int b[2*(n+1)];// = new int[n+1];
	a[0]=0; b[0] = 0;
	for(int i=1; i<=n; i++) { a[i]=scan_d(); b[i]=0; }
	sort(a,b,1,n);
	//delete[] a;
	print_d(count);
	return 0;
}
