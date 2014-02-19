#include<stdio.h>
#include<string.h>

char s[101];

int main() {
	int t,i;
	scanf("%d",&t);
	while(t>0) {
		scanf("%s",s);
		int length = strlen(s);
		for(i=0; i<length/2; i+=2) printf("%c",s[i]);
		printf("\n");
		t--;
	}
	return 0;
}
