#include<iostream>
#include<cstdio>
#include<vector>
#include<queue> 
#include<algorithm>

using namespace std;

#define MOD 1000000007
#define llu long long unsigned
#define lld long long
#define ld long

int t,n,a,b,q;

int map[202][202];

int BFS(int start, int end) {
    bool visited[n];
    for(int i=0;i<n;i++) visited[i] = false;
    int d[n];
    for(int i=0;i<n;i++) d[i] = -1;
    
    visited[start] = true;
    
    d[start] = 0;
    
    queue<int> Q;
    Q.push(start);
    
    while(!Q.empty()) {
        if(d[end]!= -1) return d[end];
        int v = Q.front(),p=0;
        Q.pop();   
        while(map[v][p]!= -1) {
            int w = map[v][p];
            if(visited[w] == false) {
                visited[w] = true;
                Q.push(w);
                d[w] = d[v] + 1;
            }    
            p++;
        }    
    }    
}    

int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);   
        char c;
        getchar();
        
        for(int i=0;i<n;i++) {
            int p=0;
            for(int j=0;j<n;j++) {
                c = getchar();
                if(c=='Y') map[i][p++] = j;
            }
            map[i][p] = -1;
            getchar();
        }        
        /*
        int dist[202][202];
        
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                dist[i][j] = BFS(i,j);
            }   
        }  
        */
        scanf("%d",&q);
        while(q--) {
            scanf("%d %d",&a,&b);            
            //if(a==b) { printf("0\n"); continue; }
            
            //if(a>b) swap(a,b);
            
            printf("%d\n",BFS(a,b));
        }    
    }    
    
    //system("pause");
    return 0;   
}    
