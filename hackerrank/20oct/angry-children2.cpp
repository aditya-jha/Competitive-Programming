#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;


#define MOD 1000000007
#define llu long long unsigned
#define lld long long
#define ld long

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

lld partition(lld a[], lld p, lld r) {
	lld x = a[r], i = p-1;
	for(lld j=p; j<r; j++) {
		if(a[j] <= x) {
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[r]);
	return i+1;
}

void quicksort(lld a[], lld p, lld r) {
	if(p<r) {
		lld q = partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}

int main() {
	lld n,k,temp;
	lld arr[100000];
	
	n = scan_lld();
	k = scan_lld();
	//scanf("%lld %lld",&n,&k);

	for(lld i=0;i<n;i++) {
		arr[i] = scan_lld();
		//scanf("%lld",&temp);
		//v.push_back(temp);
	}

	//sort(v.begin(), v.end());
	quicksort(arr,0,n-1);	

	
	lld sum, min=LLONG_MAX;
	lld end=k-1, start=0, check=k-1,i,j;
	
	while(end<n) {
		i=start, j=end; sum=0;
		while(check>0) {
			sum = sum + (check*(arr[j]-arr[i]));
			check -= 2;
			i++; j--;
		}
		if(sum<min) min=sum;
		//printf("start is: %ld,  end is: %ld,  sum is: %lld\n",start,end,sum);
		start++;
		end++;
		check=k-1;
	}
	print_lld(min);
	//printf("%lld\n",min);

	return 0;
}
