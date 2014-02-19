#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int partition(long int a[], int p, int r) {
	long int x = a[r];
	int i = p-1;
	for(int j=p; j<r; j++) {
		if(a[j] <= x) {
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[r]);
	return i+1;
}

void quicksort(long int a[], int p, int r) {
	if(p<r) {
		int q = partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}

int main() {
	int t,N,i;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&N);
		long int X[N], Y[N];
		for(i=0;i<N;i++) {
			scanf("%ld %ld",&X[i],&Y[i]);
		}
		quicksort(X,0,N-1);
		quicksort(Y,0,N-1);
		int count_x=1;
		int count_y=1;
		for(int i=1;i<N;i++) {
			if(X[i]!=X[i-1]) count_x++;
			if(Y[i]!=Y[i-1]) count_y++;
		}
		printf("%d\n",(count_x<count_y?count_x:count_y));
	}
	return 0;
}
