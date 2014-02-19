#include<iostream>
using namespace std;

int a[71][71];

int minimum_value(int a[][71], int N, int M, int K);

int main() {
	int tests;	
	cin>>tests;
	
	while(tests>0) {
		int N,M,K;
		cin>>N>>M>>K;
		int a[71][71] = {0};
		cout<<minimum_value(a,N,M,K)<<endl;
		
		tests--;
	}
	
	//system("puase");
	return 0;
}

int minimum_value(int a[][71], int N, int M, int K) {
	int max = a[0][0];
	for(int k=0; k<K; k++) {
		int i=0,j=0;
		
		while(true) {
			if(i==N-1 and j==M-1) break;
			else {
				if(i != N-1 and j != M-1) {
					if(a[i+1][j] < a[i][j+1]) {
					a[i+1][j]++;
					i++;
					} else {
					a[i][j+1]++;
					j++;
					}
				} else {
					if(i == N-1) {
						a[i][j+1]++;
						j++;
					} else {
						a[i+1][j]++;
						i++;
					}
				}
			}
			
		}
	}	

	a[N-1][M-1] = 0;

	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			if(a[i][j] > max) max = a[i][j];
	
	return max;
}
