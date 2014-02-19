#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int n, sum[34]={0}, a[100000], binary[100000][34]={0};

template<typename type> inline type scan(type i) {
	type ip = getchar_unlocked(), ret=0;
	for(;ip<'0'||ip>'9';ip=getchar_unlocked());
	for(;ip>='0' && ip<='9'; ip=getchar_unlocked()) ret = ret*10+ip-'0';
	return ret;
}

template<typename type> inline void print(type n) {
	int i=21;
	char output_buffer[22];
	output_buffer[21]='\n';
	do { output_buffer[--i]=(n%10)+'0'; n/=10; } while(n);
	do { putchar_unlocked(output_buffer[i]); } while(++i<22);
}

void get_binary(int a, int i) {
	int j=0; while(a!=0) { binary[i][j] = a%2; a = a/2; j++; }	
}

int get_value() {
	int s=0,k=33;
	//while(sum[k]==0) k--;
	for(int i=0; i<=2; i++) {
		s+=(sum[i]*int(pow(2,i)));
	}
	return s;
}

int generate_sum(int i, int j) {
	int s;
	for(int k=0; k<3; k++) {
		s = binary[i][k]+binary[j][k];
		//if(i=1 and j==3) cout<<s<<" ";
		if(s==2) sum[k] = 1;
		else sum[k] = 0;
	}
//	if(i==1 && j==3) for(int k=0; k<34; k++) cout<<sum[k];
	return get_value();
}

int main() {

	n=scan(n);
	unsigned long long int total=0;
	for(int i=0; i<n; i++) {  a[i]=scan(i); get_binary(a[i],i); }

	for(int i=0; i<n-1; i++) {
		for(int j=i+1; j<n; j++) {
//			cout<<"a[i]: "<<a[i]<<" a[j]: "<<a[j]<<" ";
			total += generate_sum(i,j);
		}
	}

//	binary[0][0] = 0;binary[0][1] = 1;binary[0][2] = 0;
//		binary[1][0] = 0;binary[1][1] = 0;binary[1][2] = 1;
//	print(generate_sum(0,1));
//for(int i=0; i<4; i++) if(i%2==0) sum[i]=1; else sum[i]=0;
	//cout<<get_value();
	print(total);
	return 0;
}
