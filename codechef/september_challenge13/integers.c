#include<stdio.h>
#include<stdlib.h>

#define lld long long int

long long int a[100000];

void swap(lld* a, lld* b) { lld t=*a; *a=*b; *b=t; }

long long int partition(lld p, lld r) {
	lld x = a[r], i = p-1, j;
	for(j=p; j<r; j++) {
		if(a[j] <= x) {
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[r]);
	return i+1;	
}

lld randomized(lld p, lld r, lld i) {
	if(p == r) return a[p];
	
	lld q = partition(p,r);
	lld k = q-p+1;

	if(i == k) 
		return a[q];
	else if(i<k) 
		return randomized(p,q-1,i);
	else
		return randomized(q+1,r,i-k);
}

long long scan_lld() {
	lld ip=getc(stdin),ret=0;
	for(;ip<'0'||ip>'9';ip=getc(stdin));
	for(;ip>='0'&&ip<='9';ip=getc(stdin))
		ret=ret*10+ip-'0';
	
	return ret;
}

void print_lld(lld n) {
	int i=21;
	char output_buffer[22];
	output_buffer[21]='\n';
	
	do { 
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	} while(n);
	
	do {
		putchar_unlocked(output_buffer[i]);
	} while(++i<22);
}

int main() {
	lld n,temp,i,total=0,count=0,size=0,x;
	//scanf("%lld",&n);
	n=scan_lld();
	for(i=0;i<n;i++) {
		scanf("%lld",&temp);
		if(temp<0) { a[size++]=temp; }
	}
	//scanf("%lld",&x);
	x=scan_lld();
	
	
	if(size-x>-1) {
		lld index = randomized(0,size-1,x);
		count = count - (index*x);
		temp = index;
		//printf("index: %lld\n",index);
		for(i=0;i<size;i++) if(a[i]<index) count -= (a[i] - temp);

		//printf("%lld\n",(count<total?count:total));
		print_lld((count));
	} 
	//else printf("%lld\n",total);
	else {
		for(i=0;i<size;i++) total -= a[i];
		print_lld(total);
	}
	//for(i=0;i<size;i++) printf("%lld ",a[i]);
	return 0;
}

