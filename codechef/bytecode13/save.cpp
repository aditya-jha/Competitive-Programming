#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<algorithm>
#define fr(i,n) for(i=0;i<n;i++)
#define Fr(i,m,n) for(i=m;i<n;i++)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define mod 1000000007
typedef long long int ll;
//using namespace std;
ll power(ll m, ll n) 
{
    if(n== 0) return 1;
    if(n == 1) return m;
    ll u = (m*m);
    u = power(u, n/2);
    if(n&1) u = (u*m);
    return u;
}

int main()
{
    int n,t,i,j,c;
    ll ans;
    char s[100];
    ll x[100],vis[200],base;
    scanf("%d",&t);
    while(t--)
	{
		ans=0;
		memset(vis,-1,sizeof(vis));
        scanf("%s",s);
        n=strlen(s);
        x[0]=1;	vis[s[0]]=1;
        c=0;
        Fr(i,1,n)
        {
        	if(vis[s[i]]!=-1)
        	{	x[i]=vis[s[i]];
				continue;
			}
        	x[i]= vis[s[i]]=c;
        	if(c==0) c+=2;
        	else	 c++;
        }
        if(c==0)	base=2;
        else	base=c;
       // printf("\t");
        fr(i,n)
        {	//printf("%lld ",x[i]);
        	ans+= x[i]*power(base,n-i-1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
