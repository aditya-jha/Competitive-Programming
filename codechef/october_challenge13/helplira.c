#include<stdio.h>

#define abs(a) (a>-1?a:-a)

int main() {
	int N, min=0,max=0,x1,y1,x2,y2,x3,y3,i;
	double min_val,max_val;
	
	scanf("%d",&N);
	float a[N];
	for(i=0;i<N;i++) {
		scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
		a[i] = abs(( x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2) )/2);
	}
	//for(i=0;i<N;i++) {
	//	printf("%0.9lf\n",a[i]);
	//}
	min_val = a[0];
	max_val = a[0];
	for(i=1;i<N;i++) {
		if(a[i]>=max_val) {
			max_val = a[i];
			max = i;
		}
		if(a[i]<=min_val) {
			min_val = a[i];
			min = i;
		}
	}
	printf("%d %d\n",min+1,max+1);
	return 0;
}	
