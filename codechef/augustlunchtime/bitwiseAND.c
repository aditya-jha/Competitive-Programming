#include<stdio.h>

int main() {
	long int n,j,i;
	unsigned long long int sum=0;
	scanf("%li",&n);
	long long int a[n];
	for(i=0; i<n; i++) scanf("%lli",&a[i]);
	
	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++) sum+=a[i]&a[j];

	printf("%llu",sum);
	return 0;	
}
