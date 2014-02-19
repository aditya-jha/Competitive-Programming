#include<stdio.h>

#define MOD 1000000007
#define lld long long int

int x,y,i,j;
long long int dp[2000][2000];

void initialize(x,y) {
	for(i=0; i<=x; i++) {
		for(j=0; j<=y; j++) dp[i][j]=-1;
	}
}

long long int count(int a,int b) {
	//printf("a:%d b:%d\n",a,b);
	if(dp[a][b]!=-1) return dp[a][b];

	if(a==0) {	
		if(b==0) return 1;
		else { dp[a][b] = count(a,b-1); return dp[a][b]; }
	}
	else if(b==0) {
		if(a==0) return 1;
		else { dp[a][b] = count(a-1,b); return dp[a][b]; }
	}
	else {
		dp[a][b] = (count(a,b-1)+count(a-1,b-1)+count(a-1,b))%MOD;
		//if(dp[a][b]>MOD) dp[a][b] = dp[a][b]%MOD;
		return dp[a][b];
	}

}

int main() {
	int t;// = scan_d();
	scanf("%d",&t);
	initialize(1999,1999);
	long long int k = count(1999,1999);
	while(t--) {
		//x = scan_d(); y = scan_d();
		scanf("%d %d",&x,&y);
		//initialize(x,y);
		printf("%lld\n",dp[x][y]);		
//		print_lld(count(x,y));
	}
	return 0;
}
