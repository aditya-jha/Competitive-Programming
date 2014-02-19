#include<stdio.h>
#include<math.h>

int main() {
	int t,v;
	long int h,d;
	scanf("%d",&t);
	while(t--) {
		scanf("%ld %ld %d",&h,&d,&v);
		double ans = (h*v)/(d - sqrt((double)d*d - (double)h*h));
		printf("%.9f\n",ans);
	}
	return 0;
}
