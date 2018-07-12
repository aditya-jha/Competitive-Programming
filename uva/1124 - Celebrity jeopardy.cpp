#include<iostream>

using namespace std;

int main() {
	char s;
	s = getchar();

	while(s != -1) {
		putchar(s);
		s = getchar();
	}

	return 0;
}