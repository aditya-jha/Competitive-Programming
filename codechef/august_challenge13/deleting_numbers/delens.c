#include<stdio.h>

int main(void) {
	int n;	
	scanf("%d",&n);
	int a[n],i;
	for(i=0; i<n; i++) scanf("%d",&a[i]);
	printf("%d\n",n);
	for(i=n; i>0; i--) printf("%d 1\n",i);
	return 0;
}
