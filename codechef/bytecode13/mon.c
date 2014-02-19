#include<stdio.h>

int main() {
	int n,m,z,i;
	scanf("%d",&n);
	while(n>0) {
		scanf("%d %d",&m,&z);
		unsigned long long int sum=m-1;
		//printf("%lli ",final);
		int a[z];
		
		for(i=0; i<z; i++) { scanf("%d",&a[i]); }
//		for(i=0; i<z; i++) { printf("%d ",a[i]); }		
		
		if(a[0]>1) { sum+=a[0]-2; }
		//printf("%llu\n",sum);
		for(i=1; i<z; i++) {
			printf("%i ",a[i]-2);
			sum+=a[i]-2;
		}

		printf("%llu\n",sum);

		n--;
	}
	return 0;
}
	

