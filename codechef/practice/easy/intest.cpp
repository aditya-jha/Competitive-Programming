#include<iostream>
#include<cstdio>

using namespace std;

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

int main() {
	//ios_base::sync_with_stdio(0);
	int n,k,t,count=0;
	//cin>>n>>k;
	//scanf("%d%d",&n,&k);
	n=scan_d();
	k=scan_d();
	while(n--) {
		//count=0;
		//cin>>t;
		//scanf("%d",&t);
		t=scan_d();
		if(t%k==0) count++;
	}

	//cout<<count<<'\n';
	//printf("%d\n",count);
	print_d(count);

	return 0;
}
