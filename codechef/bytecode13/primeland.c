#include<stdio.h>

int t;
unsigned long long int c,d;

int main() {
	scanf("%d",&t);
	while(t>0) {
		scanf("%llu %llu", &c, &d);
		printf("%llu\n",c*d - c - d);
		t--;
	}

	return 0;
}
