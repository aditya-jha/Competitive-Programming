#include<stdio.h>

int main() {
	int t;
	scanf("%d",&t);
	while(t>0) {
		int n,hq1,hq2,set,ind,value,i;
		scanf("%d %d %d",&n,&hq1,&hq2);
		int city[n+1];
		set=hq2;
		city[0]=0; city[hq1]=0;
		i=1;
		while(i<hq1) { scanf("%d",&city[i]); i++; }
		i++;
		while(i<=n) { scanf("%d", &city[i]); i++; }		
		ind = city[hq2];	
		//printf("%d %d %d\n", set, index, value);
	
	
		while(ind!=0) {
			value = city[ind];
			city[ind] = set;
			set = ind;
			ind = value;
		}	
		
		//for(i=1;i<=n; i++) if(city[i] == hq1) {   }	

	/*	
		i=1;
		while(i<hq2) { printf("%d ",city[i]); i++; }
		i++;
		while(i<=n) { printf("%d ", city[i]); i++; }		
		printf("'\n'");	
*/
		for(i=1;i<=n; i++) if(i!=hq2) printf("%d ",city[i]);
		
		t--;
	}
	return 0;
}
