#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int t,u,n,index;
	double d,r,curr,last_month,c,m,diff,max=0.00;
	scanf("%d",&t);
	while(t>0) {
		scanf("%lf %d %d",&d,&u,&n);
		last_month = u*d;
		index = -1;
		max = 0.00;
		int i;
		for(i=0; i<n; i++) {	
			scanf("%lf %lf %lf",&m,&r,&c);
			curr = c/m + r*u;
			diff = last_month - curr;
			if(diff>max) {
				max = diff;
				index = i;
			}
		}
		printf("%d\n",index+1);
		t--;
	}
	return 0;
}
