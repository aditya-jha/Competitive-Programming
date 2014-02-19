#include<stdio.h>

#define RIGHT comp[end] = 0; sum += (final-end) + (start-initial); final = end; end = a[end_index--]
#define LEFT comp[start] = 0; sum += (final-end) + (start-initial); initial = start; start = a[start_index++]
int j=0;

int main() {
	int n,m,z;
	scanf("%d",&n);
	while(n>0) {
		long long int sum=0;
		scanf("%d %d",&m,&z);
		int a[z], start, end, start_index=1, end_index=z-2, initial=1, final=m, flag=-1;; 

		//for(j=0; j<m; j++) comp[j]=1;
		//for(j=0; j<z; j++) b[j]=0;

		for(j=0; j<z; j++) scanf("%d",&a[j]);
		
		start = a[0]; end = a[z-1];
		//printf("start: %i end: %i ",start, end);
		while(z-->1) {
			
			if(final-end > start-initial) { printf("%d ",end);
				sum += (final-end) + (end-initial); final = end-1; end = a[end_index--];  
			}
			else if(final-end < start-initial) { printf("%d ",start);
				sum += (final-start) + (start-initial); initial = start+1; start = a[start_index++];  
			}
			else {
				int p= start_index, q=end_index;
				if(flag==0) { printf("%d ",end); sum += (final-end) + (end-initial); final = end-1; end = a[end_index--]; }
				else {
					while(p<=q) {
						if(a[p]-initial == final-a[q]) { p++; q--; }
						else {
							if(final-a[q] > a[p]-initial) { printf("%d ",end);
								sum += (final-end) + (end-initial); final = end-1; end = a[end_index--]; 
								flag=1; break; 
							} else {printf("%d ",start);
								sum += (final-start) + (start-initial); initial = start+1; start = a[start_index++];  
								flag = 1; break; 
							}
						}
					 	flag=0;					
					}
					if(flag==0) { printf("%d ",end); sum += (final-end) + (end-initial); final = end-1; end = a[end_index--];  }
				}
					
				
			}
			
		}
		printf("%d \n",end);
		sum += (final-end) + (end-initial);
		printf("%lli\n",sum);
		//for(j=0; j<m; j++) printf("%i ",comp[j]);
		n--;
	}
	return 0;
}
