#include<stdio.h>
#include<stdlib.h>

char buff[25];
int j=24;

int main(void) {
	while(j>0) {
		buff[j] = getchar_unlocked();
		j--;
	};

	char *s = buff;
	*s++;
	while(*s++) putchar_unlocked(*s);
	putchar_unlocked('\n');

	return 0;
}

