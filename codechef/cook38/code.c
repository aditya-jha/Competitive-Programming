#include<stdio.h>
#include<string.h>

int i,j;

long long int xor(int N, long long int K, long long int ans, int a[])
{
	long long int first=ans,second;
	for(j=0;j<N;j++) {
		first = first^a[j];
	}
	if(K>1) {
		second = first;
		for(j=0;j<N;j++) {
			second = second^a[j];
		}
	}
	if(K%2==0) return second;
	else return first;
}

long long int and(int N, long long int K, long long int ans, int a[])
{
	for(i=0;i<K;i++) {
		for(j=0;j<N;j++) {
			ans = ans&a[j];
		}
		if(ans == 0) break;
	}
	return ans;
}

long long int or(int N, long long int K, long long int ans, int a[])
{
	ans = ((N|(N-1))|ans);
	return ans;
}


int main() {
	int t;
	scanf("%d",&t);

	while(t--) {
		int N;
		long long int K, ans;
		scanf("%d",&N);
		scanf("%lld %lld",&K,&ans);
		
		int a[N];
		for(i=0;i<N;i++) scanf("%d",&a[i]);
		
		char op[4];
		scanf("%s",op);

		if(op[0]=='X') printf("%lld\n",xor(N,K,ans,a));
		else if(op[0]=='A') printf("%lld\n",and(N,K,ans,a));
		else printf("%lld\n",or(N,K,ans,a));

//		printf("%lld\n",or(N,K,ans,a));
	}

	return 0;
}
