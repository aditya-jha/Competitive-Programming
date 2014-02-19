#include<cstdio>
#include<cmath>

int main() {
	int t,v;
	long long int h,d;
	scanf("%d",&t);
	while(t--) {
		scanf("%lld %lld %d",&h,&d,&v);
		double ans = (h*v)/(d - sqrt((double)(d*d) - (double)(h*h)));
		printf("%.9f\n",ans);
	}
	return 0;
}
