#include<iostream>
using namespace std;

unsigned long long int maxim(int v[][101], int p, int c[]) {
	unsigned long long int maximum = 0;
	int index = 0;
	
	for(int i=0; i<c[p]; i++) {
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
	cin>>t;
	while(t>0) {
		cin>>n>>m;
		int p[m],c[n],v[n][101];
		unsigned long long int drunk = 0;

		for(int i=0; i<m; i++) cin>>p[i];
		//for(int i=0; i<m; i++) cout<<p[i]<<" ";

		int k=0;
		for(int i=0; i<n; i++) {
			cin>>c[i];
			for(int j=0; j<c[i]; j++) cin>>v[k][j];
			k++;
		}
/*
		for(int i=0; i<n; i++)  {
			for(int j=0; j<c[i]; j++) cout<<v[i][j]<<" ";
			cout<<endl;
		}


cout<<endl;
*/
		for(int i=0; i<m; i++) {
			drunk += maxim(v,p[i],c);        
		}		

		cout<<drunk<<endl;		

		t--;	
	}
	return 0;
}
