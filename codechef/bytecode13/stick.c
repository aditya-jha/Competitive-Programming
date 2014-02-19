#include<stdio.h>

int t,n,x[208];

int main() {
	scanf("%d",&t);
	while(t>0) {
		
		int count=1, start,length,j,i;
		for(i=0; i<208; i++) x[i]=0;
		scanf("%d",&n);		
		int a[n],b[n];
		for(i=0; i<n; i++) {
			scanf("%d %d",&a[i],&b[i]);
			x[a[i]+108]=b[i];		
		}
		
		for(i=0; i<n; i++) {
			count=1; length=b[i]; start=a[i]+108;
			//cout<<"a[i]: "<<a[i]<<" length: "<<length<<endl;
			for(j=start+1; j<208; j++) {
				if(x[j] != 0) {
					//cout<<"j-start: "<<j-start<<endl;
					if(length>(j-start)) {
						//cout<<"length: "<<length<<endl;
						count++;
						if(length<j-start+x[j]) length = x[j];
						start = j;
					} else break;
				}
			}
			printf("%d ",count); 
		}		
		//printf("1\n");
		t--;
	}
	return 0;
}
