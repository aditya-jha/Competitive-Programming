#include<stdio.h>

int main() {
	long int t;

	scanf("%ld",&t);
	char s[100005];
	getchar();
	while(t--) {
		long int count_R=0,count_Y=0,count=0,i=0;
		
		int flag=0;
			
		count = scanf("%s",s);
		if(s[0]='Y') flag=1;
		else {
		for(i=0;s[i]!='\0';i++) {
			//count++;
			if(s[i]=='R') count_Y=0;
			else if(s[i]=='Y') { count_Y++; if(count_Y==3) { flag=1; break; } }
			else { flag = 1; break; }			
		}
		}
		
		if(flag!=0) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
