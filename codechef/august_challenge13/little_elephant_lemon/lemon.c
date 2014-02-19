#include<stdio.h>
#include<stdlib.h>

unsigned long long int maxim(int v[][101], int p, int c[]) {
	unsigned long long int maximum = 0;
	int index = 0;
	int i;
	for(i=0; i<c[p]; i++) {
		if(v[p][i] > maximum) {
			maximum = v[p][i];
			index = i;
		}
	}

	//cout<<"v["<<p<<"]["<<index<<"] = "<<v[p][index]<<" "<<"max: "<<maximum<<endl;
	v[p][index] = 0;
	return maximum;
}
	

/*
void maximu(int v[][101], int p, int c[]) {
	
	for(int i=0; i<=c[p]; i++) {
		cout<<v[p][i]<<" ";
	}
	cout<<endl;
}
*/
int main() {
	int t,n,m;
	scanf("%d",&t);
	while(t>0) {
		scanf("%d %d",&n,&m);
		int p[m],c[n],v[n][101];
		unsigned long long int drunk = 0;
		int i;
		for(i=0; i<m; i++) scanf("%d",&p[i]);
		//for(int i=0; i<m; i++) cout<<p[i]<<" ";

		int k=0,j;
		for(i=0; i<n; i++) {
			scanf("%d",&c[i]);
			for(j=0; j<c[i]; j++) scanf("%d",&v[k][j]);
			k++;
		}
/*
		for(int i=0; i<n; i++)  {
			for(int j=0; j<c[i]; j++) cout<<v[i][j]<<" ";
			cout<<endl;
		}


cout<<endl;
*/
		for(i=0; i<m; i++) {
			drunk += maxim(v,p[i],c);        
		}		

		printf("%llu\n",drunk);		

		t--;	
	}

	return 0;
}
