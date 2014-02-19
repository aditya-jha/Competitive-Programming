#include<iostream>
#include<cstdio>

using namespace std;

#define MOD 1000000007
#define llu long long unsigned
#define lld long long
#define ld long
 
int scan_d() {
	int ip=getchar_unlocked(),ret=0;
	for(;ip<'0'||ip>'9';ip=getchar_unlocked());
	for(;ip>='0'&&ip<='9';ip=getchar_unlocked())
		ret=ret*10+ip-'0';

	return ret;
}

void print_d(int n) {
	int i=10;
	char output_buffer[11];output_buffer[10]='\n';
	
	do {
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	} while(n);
	
	do {
		putchar_unlocked(output_buffer[i]);
	} while(++i<11);
}

int n,q,sx1,sx2,sy1,sy2,sol,ans,temp;
int arr[301][301];
int mat[301][301][11];

int func() {
	int *a = new int[12];   
	for(int i=1;i<11;i++) a[i]=0;
	sy2--;
	for(int i=sx1-1;i<sx2;i++) {
		int j=sy1-1;
		//cout<<"j: "<<j<<endl;
		if(j==0) {
			for(int k=1;k<11;k++) {
				if(mat[i][sy2][k]) { 
					//cout<<mat[i][sy2][k];
					a[k]++;
				}
			}
		} else {
			j--;
			//cout<<"sy2-1: "<<sy2-1<<", j: "<<j<<endl;
			for(int k=1;k<11;k++) {
				if(mat[i][sy2][k] - mat[i][j][k]) {
					a[k]++;
					//cout<<mat[i][sy2-1][k] - mat[i][j][k];
					//cout<<"k: "<<k<<" ";
				}
			}
		}
	}
	sol=0;
	for(int i=1;i<11;i++) {
		if(a[i]) sol++;
		//cout<<a[i]<<" ";
	} //cout<<endl;
	
	delete[] a;
	return sol;
}

int main() {
	//ios_base::sync_with_stdio(0);
	//cin>>n;
	n = scan_d();
	//cout<<"n: "<<n<<endl;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			//cin>>temp;
			temp = scan_d();
			arr[i][j] = temp;
			for(int k=j;k<n;k++) {
				mat[i][k][temp]++;
			}
		}
	}
	/*
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			for(int k=1;k<11;k++) {
				cout<<mat[i][j][k]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	*/
	//cin>>q;
	q = scan_d();
	while(q--) {
		//cout<<"i: "<<i<<endl;
		//cin>>sx1>>sy1>>sx2>>sy2;
		sx1 = scan_d();
		sy1 = scan_d();
		sx2 = scan_d();
		sy2 = scan_d();
		//cout<<func()<<'\n';
		ans=func();
		print_d(ans);
	}
	return 0;
}
