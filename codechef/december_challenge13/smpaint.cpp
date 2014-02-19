#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>

#define getcx getchar_unlocked

using namespace std;

inline int in( ) {
	int n=0;
	
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	
	while( ch >= '0' && ch <= '9' )
		n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
		
	return n*sign;
}
int main() {
	int n,t=1001;
	
	n = in();
	
	int **a = new int*[t];
	int **fill = new int*[t];
	int **sol = new int*[t*t];
	
	for(int i=0;i<t;i++) {
		a[i] = new int[t];
		fill[i] = new int[t];
	}
	for(int i=0;i<n*n;i++) sol[i] = new int[5];
	
	int index=0,row,col,color;
	
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) fill[i][j]=0;	

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			a[i][j] = in();
			//if(a[i][j]>0) count++;
		}
	}
	
	//printf("%d\n",count);
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(a[i][j]>0) {
				color = a[i][j];
				if(fill[i][j]==color) continue;
				
				row=0; col=0;
				
				for(int k=j;k<n;k++) {
					if(a[i][k]==color) col++;
					else break;
				}
				for(int k=i;k<n;k++) {
					if(a[k][j]==color) row++;
					else break;
				}
				
				for(int k=i;k<i+row;k++) {
					for(int m=j;m<j+col;m++) {
						fill[k][m] = color;
					}
				}
				
				sol[index][0] = color;
				sol[index][1] = i+1;
				sol[index][2] = i+row;
				sol[index][3] = j+1;
				sol[index][4] = j+row;
				index++;
			}
		}
	}
	
	//for(int i=0;i<n;i++) {
	//	for(int j=0;j<n;j++) cout<<fill[i][j]<<" ";
	//	cout<<endl;
	//}
	
	printf("%d\n",index);
	for(int i=0;i<index;i++) {
		printf("%d %d %d %d %d\n",sol[i][0],sol[i][1],sol[i][2],sol[i][3],sol[i][4]);
	}
	
	delete[] a;
	delete[] fill;
	delete[] sol;
	
	return 0;
}

