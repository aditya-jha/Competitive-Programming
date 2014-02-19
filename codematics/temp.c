#include<stdio.h>

#define MOD 1000000007

int x,y,i,j;
long int dp[2000][2000];

void initialize(x,y) {
	for(i=0; i<=x; i++) {
		for(j=0; j<=y; j++) dp[i][j]=-1;
	}
}

long long int count(int a,int b) {
	//printf("a:%d b:%d\n",a,b);
	//if(dp[a][b]!=-1) return dp[a][b];

	if(a==0) {	
		if(b==0) return 1;
		else return count(a,b-1);
	}
	else if(b==0) {
		if(a==0) return 1;
		else return count(a-1,b);
	}
	else {
		return (count(a,b-1)+count(a-1,b-1)+count(a-1,b))%MOD;
		//return dp[a][b];
	}

}

int scan_d() {
	int ip=getchar_unlocked(),ret=0;
	for(;ip<'0'||ip>'9';ip=getchar_unlocked());
	for(;ip>='0'&&ip<='9';ip=getchar_unlocked())
		ret=ret*10+ip-'0';

	return ret;
}



int main() {
	int t = scan_d();
	//scanf("%d",&t);
	while(t--) {
		x = scan_d(); y = scan_d();
		//scanf("%d %d",&x,&y);
		initialize(x,y);
		printf("%lld\n",count(x,y));		
	}
	return 0;
}
