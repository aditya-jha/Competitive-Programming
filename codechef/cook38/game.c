#include<stdio.h>


long long scan_lld() {
	lld ip=getc(stdin),ret=0;
	for(;ip<'0'||ip>'9';ip=getc(stdin));
	for(;ip>='0'&&ip<='9';ip=getc(stdin))
		ret=ret*10+ip-'0';
	
	return ret;
}

long long int N,M,K,i;

long long int partition(long long int p, long long int r) {
	long long int x = a[r], i = p-1,j;
	for(j=p; j<r; j++) {
		if(a[j] <= x) {
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[r]);
	return i+1;
}

void quicksort(int a[], int p, int r) {
	if(p<r) {
		int q = partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}


int main() {
	
	N = scan_lld();
	M = scan_lld();
	K = scan_lld();

	long long int A[N];
	for(i=0;i<N;i++) A[i]=scan_lld();
	
	
	
	return 0;
}
