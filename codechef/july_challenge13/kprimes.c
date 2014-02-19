#include<stdio.h>
#include<math.h>

int check(int i);
int isprime(int i);

int main() {
	int tests;
	scanf("%d",&tests);
		
	while(tests > 0) {
		int A,B,K;
		scanf("%d %d %d", &A, &B, &K);
		int value = 0,i;
		for(i=A; i<=B; i++) {
			if(check(i) == K) value++;
		}
			
		printf("%d\n", value);
		tests--;
	}
	return 0;
}

int isprime(int i) {
	if(i%2==0) return 0;
	else if(i%3==0) return 0;
	else {
		int j=5;
		while(j<int(sqrt(double(i)))) {
			if(i%j == 0) return 0;
			j = j+2;
		}
	}
	return 1;
}


int check(int i) {
	int prev=1, count=0, j=5;
	while(i!=1) {
		if(isprime(i)) {
			//cout<<"Prime: "<<i<<" prev: "<<prev<<" ";
			if(prev != i) {
				prev = i;
				count++;
			}
			i = 1;
		} else {
			if(i%2 == 0) {
				while(i%2==0) i=i/2;
				if(prev != 2) {
					prev = 2;
					count++;
				}
			} else if(i%3 == 0){
				while(i%3==0) i = i/3;
				//cout<<"i: "<<i<<" prev: "<<prev<<" ";
				if(prev != 3) {
					prev = 3;
					count++;
				}
			} else {
				if(i%j==0) {
					//cout<<"i: "<<i<<" prev: "<<prev<<" ";
					while(i%j==0) i = i/j;
					if(prev != j) {
						prev = j;
						count++;
					}
					j = j+2;
				} else j = j+2;
			}	
		}
	}
	return count;
}
