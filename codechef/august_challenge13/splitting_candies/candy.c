#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int t;
	unsigned long long int N,K;
	scanf("%d",&t);
	while(t>0) {
		scanf("%llu %llu",&N,&K);
		if(N == 0) printf("0 0\n");
		else {
			if(K == 0) printf("0 %llu\n",N);
			else printf("%llu %llu\n",N/K,N%K);
		}
		
		t--;
	}
	return 0;
}
