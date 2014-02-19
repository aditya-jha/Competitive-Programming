#include<stdio.h>
#include<algorithm>
using namespace std;

int c[1000001],n;

void mergesort(int a[], int p, int r);
int *merge(int a[], int p, int q, int r);

int main() {
	int t,q,l,r;
	scanf("%d",&t);
	while(t>0) {
		scanf("%d %d",&n,&q);
		int a[n];
		unsigned long long int sum=0;
		//for(int i=0; i<n; i++) c[i]=0;
		for(int i=0; i<n; i++) { scanf("%d",&a[i]); }
		for(int i=0; i<q; i++) { scanf("%d %d",&l,&r); for(int i=l-1; i<r; i++) c[i]++; }
		
		mergesort(a,0,n-1);
		mergesort(c,0,n-1);

		for(int i=0; i<n; i++) {
			sum += c[i]*a[i];
		}
		//for(int i=0; i<n; i++) printf("%d ",c[i]);
		printf("%llu\n",sum);
		t--;
	}

	return 0;
}


int *merge(int a[], int p, int q, int r) {
	int lenb = q-p+1, lenc = r-q;
	int b[lenb], c[lenc], indexb = 0, indexc = 0;

	for(int i=0,j=p; i<lenb; i++,j++) b[i] = a[j];

	for(int i=0,j=q+1; i<lenc; i++,j++) c[i] = a[j];

	for(int k=p; k<=r; k++) {
		if(indexb != lenb and indexc != lenc) {
			if(b[indexb] < c[indexc]) {
				a[k] = b[indexb];
				indexb++;
			} else {
				a[k] = c[indexc];
				indexc++;
			}
		} else {
			if(indexb == lenb) {
				a[k] = c[indexc];
				indexc++;
			} else {
				a[k] = b[indexb];
				indexb++;
			}
		}
	}
	
	return a;
}


void mergesort(int a[], int p, int r) {
	if(p<r) {
		int q = (p+r)/2;
		mergesort(a,p,q);
		mergesort(a,q+1,r);
		merge(a,p,q,r);
	}
}
