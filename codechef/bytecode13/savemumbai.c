#include<stdio.h>
#include<string.h>
#include<math.h>

unsigned long long int p[65]={1};
unsigned long long int power(int a, int b) {
	int i=1; p[1] = a;

	if(b==0) return 1;
	if(b==1) return a;
	p[b] = p[b-1]*a;
	return p[b];
}

unsigned long long int get_value(int c[], int value, int index) {
	unsigned long long int sum=0;
	int i=index-1,j=0;
	while(i>-1) {
		sum += c[i]*power(value,j);
		j++; i--;
	}
	return sum;
}

int main() {
	int t;
	char s[62];
	scanf("%d",&t);
	while(t--) {
		scanf("%s",s);
		int freq[100], c[65], index=0,value=2, length = strlen(s),i=0;
		for(i=0; i<100; i++) freq[i] = -1; i=0;
		
		c[index] = 1; index++;
		freq[s[i++]-38] = 1;
		
		if(i<length) {
			if(s[i] != s[i-1]) { freq[s[i]-38] = 0; c[index] = 0; index++; }
			else { c[index] = 1; index++; value = 0; }
			i++;
		}
		while(i<length) {
			if(freq[s[i]-38] != -1) c[index++] = freq[s[i]-38];
			else { c[index++] = value; freq[s[i]-38] = value; value++; if(value==1) value++; }
			i++;
		}
		if(value<2) value=2;
		printf("%llu\n",get_value(c,value,index));
//		for(i=0; i<index; i++) printf("%d ",c[i]); printf("\n");
//		for(i=0; i<100; i++) printf("%d ",freq[i]);
	}

	return 0;
}


