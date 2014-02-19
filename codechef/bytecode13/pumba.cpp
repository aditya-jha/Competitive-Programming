#include<iostream>
#include<cstdio>
#include<cmath>

int t,n;

template<typename type> inline type scan(type i) {
	type ip = getchar_unlocked(), ret=0;
	for(;ip<'0'||ip>'9';ip=getchar_unlocked());
	for(;ip>='0' && ip<='9'; ip=getchar_unlocked()) ret = ret*10+ip-'0';
	return ret;
}

template<typename type> inline void print(type n) {
	int i=21;
	char output_buffer[22];
	output_buffer[21]='\n';
	do { output_buffer[--i]=(n%10)+'0'; n/=10; } while(n);
	do { putchar_unlocked(output_buffer[i]); } while(++i<22);
}

void mergesort(long int a[], int p, int r);
long int *merge(long int a[], int p, int q, int r);
long long int get_sum_left(long int a[], int index);
long long int get_sum_right(long int a[], int index);

int main() {
	t = scan(t);
	while(t--) {
		n = scan(n);
		long int a[n];
		long long int left_sum, right_sum, z;
		int index=1;
		for(int i=0; i<n; i++) a[i] = scan(a[i]);
		//for(int i=0; i<n; i++) print(a[i]);
		mergesort(a,0,n-1);
		//for(int i=0; i<n; i++) print(a[i]);
		while(index<n) {
			left_sum = get_sum_left(a,index);
			right_sum = get_sum_right(a,index);
			z = left_sum^right_sum;
			if(z == 0) { break; }
			else index++;
		}
		if(index<n) {
			unsigned long long int sum=0;
			for(int i=index; i<n; i++) sum += a[i];
			print(sum);
		} else printf("NO\n");
	}
	
	return 0;
}


long int *merge(long int a[], int p, int q, int r) {
	int lenb = q-p+1, lenc = r-q;
	long int b[lenb], c[lenc];
	int indexb = 0, indexc = 0;

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


void mergesort(long int a[], int p, int r) {
	if(p<r) {
		int q = (p+r)/2;
		mergesort(a,p,q);
		mergesort(a,q+1,r);
		merge(a,p,q,r);
	}
}

long long int get_sum_left(long int a[], int index) {
	long long int sum=a[0];
	for(int i=1; i<index; i++) sum = sum^a[i];
	return sum;
}

long long int get_sum_right(long int a[], int index) {
	long long int sum=a[index];
	for(int i=index+1; i<n; i++) sum = sum^a[i];
	return sum;
}
