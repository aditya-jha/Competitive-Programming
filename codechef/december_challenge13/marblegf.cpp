#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>

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

void print_lld(lld n) {
	int i=21;
	char output_buffer[22];
	output_buffer[21]='\n';
	
	do { 
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	} while(n);
	
	do {
		putchar_unlocked(output_buffer[i]);
	} while(++i<22);
}

int n,q,x,y,maxn;
char c;
int a[1000005];
long long int st[2100000],sum;

inline int getMid(int s, int e) { return s+ (e-s)/2; }

long long int buildTree(int ss, int se, int si) {
	if(ss==se) {
		st[si]=a[ss];
		return st[si];
	}
	int mid = getMid(ss,se);
	st[si] = buildTree(ss,mid,2*si+1) + 
		 buildTree(mid+1,se,2*si+2);
	return st[si];
}

long long int getSum(int ss, int se, int qs, int qe, int index) {
	if(qs<=ss && qe>=se) return st[index];
	if(se<qs || ss>qe) return 0;
	int mid = getMid(ss, se);
    	
    	return getSum(ss, mid, qs, qe, 2*index+1) +
               getSum(mid+1, se, qs, qe, 2*index+2);
}

void updateValue(int ss, int se, int i, int diff, int index) {
	if(i>=ss and i<=se) {
		st[index]+=diff;
		
		if(se!=ss) {
			int mid = getMid(ss,se);
			updateValue(ss,mid,i,diff,2*index+1);
			updateValue(mid+1,se,i,diff,2*index+2);
		}
	}
}


int main() {
	//ios_base::sync_with_stdio(0);
	
	//cin>>n>>q;
	n=scan_d();
	q=scan_d();
	for(int i=0;i<n;i++) a[i]=scan_d();//
		//cin>>a[i];

	buildTree(0,n-1,0);

	while(q--) {
		//cin>>c>>x>>y;
		cin>>c;
		//cout<<c<<endl;
		x=scan_d();
		y=scan_d(); 
		
		if(c=='S') {
			//cout<<getSum(0,n-1,x,y,0)<<'\n';
			sum=getSum(0,n-1,x,y,0);
			print_lld(sum);
		}
		else if(c=='G') {
			a[x] += y;
			//for(int i=0;i<n;i++) cout<<a[i]<<" ";
			//cout<<endl;
			updateValue(0,n-1,x,y,0);
		} else if(c=='T') {
			y = -1*y;
			a[x]+=y;
			//for(int i=0;i<n;i++) cout<<a[i]<<" ";
			//cout<<endl;
			updateValue(0,n-1,x,y,0);
		}
	}

	return 0;
}
