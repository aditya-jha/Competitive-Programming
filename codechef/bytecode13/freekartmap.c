#include<stdio.h>
 
int t,n,hq1,hq2,i;
 
int main() {
	scanf("%d",&t);
	while(t>0) {
		scanf("%d %d %d",&n,&hq1,&hq2);
		int city[n+1], set=hq2, index, value = 0;
		city[0]=0; city[hq1]=0;
		i=1;
		while(i<hq1) { scanf("%d",&city[i]); i++; }
		i++;
		while(i<=n) { scanf("%d", &city[i]); i++; }	
		index = city[hq2];

		while(index!=0) { value = city[index]; city[index] = set; set = index; index = value; }	

		for(i=1;i<=n; i++) if(i!=hq2) printf("%d ",city[i]);
		t--;
	}
	return 0;
}
