#include<stdio.h>

int t,n,i;
void mergesort(long int a[], int p, int r);
long int *merge(long int a[], int p, int q, int r);
long int get_sum_left(long int a[], int index);
long int get_sum_right(long int a[], int index);

int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		long int a[n], left_sum, right_sum, z, total;
		int index=1;
		scanf("%li",&a[0]);
		total = a[0];
		for(i=1; i<n; i++) { scanf("%li",&a[i]); total = total^a[i]; }
		if(total == 0) {
		mergesort(a,0,n-1);
		
		while(index<n) {
			left_sum = get_sum_left(a,index);
			right_sum = get_sum_right(a,index);
			z = left_sum^right_sum;
			if(z == 0) { break; }
			else index++;
		}
		if(index<n) {
			unsigned long long int sum=0;
			for(i=index; i<n; i++) sum += a[i];
			printf("%llu\n",sum);
		} else printf("NO\n");
		} else printf("NO\n");
	}
	
	return 0;
}


long int *merge(long int a[], int p, int q, int r) {
	int lenb = q-p+1, lenc = r-q,j,k;
	long int b[lenb], c[lenc];
	int indexb = 0, indexc = 0;

	for(i=0,j=p; i<lenb; i++,j++) b[i] = a[j];

	for(i=0,j=q+1; i<lenc; i++,j++) c[i] = a[j];

	for(k=p; k<=r; k++) {
		if(indexb != lenb && indexc != lenc) {
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


void mergesort(long int a[], int p, int r) {
	if(p<r) {
		int q = (p+r)/2;
		mergesort(a,p,q);
		mergesort(a,q+1,r);
		merge(a,p,q,r);
	}
}

long int get_sum_left(long int a[], int index) {
	long int sum=a[0];
	for(i=1; i<index; i++) sum = sum^a[i];
	return sum;
}

long int get_sum_right(long int a[], int index) {
	long int sum=a[index];
	for(i=index+1; i<n; i++) sum = sum^a[i];
	return sum;
}
