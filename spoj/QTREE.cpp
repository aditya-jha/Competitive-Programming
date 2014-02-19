# include <cstdio>
# include <vector>
# include <cstring>
# include <algorithm>

using namespace std;
const int NMAX=10000;
const int segsize=1<<15,base=1<<14;

struct two
{
	int a,b;
	two(int x=0,int y=0)
	{
		a=x;b=y;
	}
};

vector<two>adjlist[NMAX];
two edges[NMAX];
int parent[NMAX],parwt[NMAX],depth[NMAX],cnt[NMAX],heavychild[NMAX],skip[NMAX];
char heavypar[NMAX];
int segtree[segsize],nextfree,parpos[NMAX];

void update(int pos,int val)
{
	segtree[pos+=base]=val;
	while((pos>>=1))
		segtree[pos]=max(segtree[pos<<1],segtree[(pos<<1)|1]);
}

int query(int node,int l,int r,int L,int R)
{
	if(l==L&&r==R)return segtree[node];
	int M=(L+R)>>1,lc=node<<1;
	if(r<=M)return query(lc,l,r,L,M);
	else if(l>M)return query(lc|1,l,r,M+1,R);
	else return max(query(lc,l,M,L,M),query(lc|1,M+1,r,M+1,R));
}

void dfs1(int u)
{
	cnt[u]=1;
	for(int i=0;i<adjlist[u].size();i++)
	{
		int v=adjlist[u][i].a;
		if(v==parent[u])continue;
		parent[v]=u;
		parwt[v]=adjlist[u][i].b;
		depth[v]=depth[u]+1;
		dfs1(v);
		cnt[u]+=cnt[v];
	}

	for(int i=0;i<adjlist[u].size();i++)
	{
		int v=adjlist[u][i].a;
		if(v==parent[u])continue;
		if(cnt[u]<=(cnt[v]<<1))
		{
			heavychild[u]=v;
			heavypar[v]=true;
		}
	}
}

void dfs2(int u)
{
	if(heavypar[u])
	{
		skip[u]=skip[parent[u]];
		update(parpos[u]=nextfree++,parwt[u]);
	}
	else skip[u]=u;

	if(heavychild[u]!=-1)dfs2(heavychild[u]);
	for(int i=0;i<adjlist[u].size();i++)
	{
		int v=adjlist[u][i].a;
		if(v==parent[u]||v==heavychild[u])continue;
		dfs2(v);
	}
}

int LCA(int u,int v)
{
	while(skip[u]!=skip[v])
	{
		if(depth[skip[u]]<depth[skip[v]])v=parent[skip[v]];
		else u=parent[skip[u]];
	}
	return (depth[u]<depth[v])?u:v;
}

int maxpath(int u,int v)
{
	if(u<0||v<0)while(1);
	if(u==v)return 0;
	else if(!heavypar[u])return max(parwt[u],maxpath(parent[u],v));
	else
	{
		int w=skip[u];
		if(depth[w]<=depth[v])return query(1,parpos[u]-(depth[u]-depth[v])+1,parpos[u],0,base-1);
		else return max(query(1,parpos[u]-(depth[u]-depth[w])+1,parpos[u],0,base-1),maxpath(w,v)); 
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		for(int i=0;i<NMAX;i++)
			adjlist[i].clear();
		memset(heavychild,-1,NMAX<<2);
		memset(heavypar,0,NMAX);
		memset(segtree,0,segsize<<2);
		nextfree=0;

		int N;
		scanf("%d",&N);

		for(int i=1;i<N;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			a--,b--;
			adjlist[a].push_back(two(b,c));
			adjlist[b].push_back(two(a,c));
			edges[i]=two(a,b);
		}

		dfs1(0);
		for(int i=1;i<N;i++)
			if(parent[edges[i].b]==edges[i].a)swap(edges[i].a,edges[i].b);
		dfs2(0);

		while(1)
		{
			char inp[10];
			scanf("%s",inp);
			if(inp[0]=='D')break;
			if(inp[0]=='Q')
			{
				int u,v,w;
				scanf("%d%d",&u,&v);
				u--,v--;
				w=LCA(u,v);
				printf("%d\n",max(maxpath(u,w),maxpath(v,w)));

			}
			else if(inp[0]=='C')
			{
				int a,b,u;
				scanf("%d%d",&a,&b);
				u=edges[a].a;
				if(heavypar[u])update(parpos[u],parwt[u]=b);
				else parwt[u]=b;
			}
		}
	}
	return 0;
}
