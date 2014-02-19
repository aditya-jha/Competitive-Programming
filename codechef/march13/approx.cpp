#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int arr[1000005];

void solve() {
	arr[0]=0;
	int rem,dem;
	dem=33102;
	rem=103993%dem;

	for(int i=1;i<1000002;i++) {
		rem=rem*10;
		arr[i]=rem/dem;
		rem=rem%dem;
	}	
}


int main() {
	solve();
	int t,k;
	scanf("%d",&t);	
	while(t--) {
		scanf("%d",&k);
		if(k==0) printf("3\n");
		else {
			printf("3.");
			k++;
			for(int i=1;i<k;i++) {
				printf("%d",arr[i]);
			}
			putchar('\n');
		}
	}
	return 0;
}
