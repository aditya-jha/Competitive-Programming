#include<stdio.h>
#include<cmath>

int isprime(int i) {
	int j;
	if(i%2==0) return 0;	
	if(i%3==0) return 0;
	for(j=5; j<sqrt(double(i)); j+=2) if(i%j==0) return 0;
	return 1;
}

int main() {
	int t,a,b,i;
	unsigned long long int count=0;
	scanf("%d",&t);

	while(t>0) {
		count=0;
		scanf("%d %d",&a,&b);		
		i=a;
		if(a==b and a==1) printf("%llu\n",count);
		else {
		if(i<=2) { if(b>=2) { count++; i=5; } }
		while(i<=b) {
			if(i%4==1) {
				if(isprime(i)) count++;
			}
			i++;
		}
		printf("%llu\n",count); }
		t--;
	}
	return 0;
}
