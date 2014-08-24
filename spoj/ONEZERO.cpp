#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>

using namespace std;

const int maxn = 20002;

bool visited[maxn];
int n,u;

pair<int,char> p[maxn];

void BFS(int s) {
    int child[2];
    for(int i=0;i<=n;i++) visited[i] = false;
    queue<int> q;
    q.push(s);
    
    visited[s] = true;
    
    p[s].first = -1;
    p[s].second = '1';
    
    while(!q.empty()) {
        u = q.front();
        q.pop();
        
        child[0] = (u*10)%n;
        child[1] = (child[0]+1)%n;
        
        for(int i=0;i<2;i++) {
            if(!visited[child[i]]) {
                p[child[i]].first = u;
                p[child[i]].second = i+'0';
                
                if(child[i] == 0) return;
                
                visited[child[i]] = true;
                q.push(child[i]);
            }    
        }    
    }    
}    

void print(int i) {
    if(i == -1) return;
    print(p[i].first);
    //cout<<p[i].first<<": "<<p[i].second<<endl;
    putchar(p[i].second);
}    

int main() {
    
    int t;
    scanf("%d",&t);
    
    while(t--) {
        scanf("%d",&n);
        
        if(n==1) {
            putchar('1');
            putchar('\n');
        }    
        else {
            BFS(1);
            print(0);
            
            putchar('\n');
        }    
    }    
    
    return 0;
}    
