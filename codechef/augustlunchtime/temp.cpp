#include<stdio.h>
#include<string.h>

char s[101];

int main() {
	int t;
	scanf("%t",&t);
	while(t-->0) {
		scanf("%s",s);
		int length = strlen(s);
		for(int i=0; i<length/2; i+=2) printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}
