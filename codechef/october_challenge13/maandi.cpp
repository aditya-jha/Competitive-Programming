#include<cstdio>
#include<cmath>

int check(long int k) {
	while(k!=0) {
		if(k%10 == 4 || k%10==7) return 1;
		else k=k/10;
	}
	return 0;
}

int main() {
	int t,i,count;
	long int n,j;
	scanf("%d",&t);
	while(t--) {
		count=0;
			
		scanf("%ld",&n);
		
		count += check(n);
		
		for(i=2;i<=sqrt((double)n);i++) {
			if(n%i==0) {
				j = n/i;
				count += check(i);
				if(i==j) continue;
				count += check(j);
			}
				
		} 
		printf("%d\n",count);
	}
	return 0;
}
