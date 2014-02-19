#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int main() {
	
	int n;
	scanf("%d",&n);
	
	int a[n][2],x,y;
	char mat[n],c;
	for(int i=0;i<n;i++) scanf("%d %d",&a[i][0],&a[i][1]);
	
	for(int i=0;i<n;i++) {
		scanf("%s",mat);
		for(int j=0;j<n;j++) {
			if(mat[j] = 'Y') {
				x = i; y = j;
				break;
			}
		}
	}
	
	printf("1\n1 %d %d\n",x,y);
	return 0;	
}
