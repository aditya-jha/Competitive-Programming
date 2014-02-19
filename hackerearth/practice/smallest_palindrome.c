#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char s[10001];

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%s",s);
		int length=strlen(s), half = length/2, cost[2], min=0, i , j;
		long int count=0;
		scanf("%d %d", &cost[0], &cost[1]);
		if(cost[0]>cost[1]) min = cost[1]; else min = cost[0];

		for(i=0,j=length-1; i<half; i++,j--) {
			if(s[i]=='/' || s[j]=='/') {
				if(s[i]==s[j]) count+=(2*min);
				else if(s[i]=='/') count+=cost[s[j]-'a'];
				else count+=cost[s[i]-'a'];
			} else if(s[i]!=s[j]) { count=-1; break; }
		}
	
		printf("%ld\n",count);
	}
	return 0;
}
